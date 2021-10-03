#include <SPI.h>
#include <LoRa.h>
#include <SSD1306.h>
#include <Encoder.h>
#include <WiFi.h>
#include <IOXhop_FirebaseESP32.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>
#include "RTClib.h"
#include <Fuzzy.h>

#define FIREBASE_HOST "mitigasi-8e083-default-rtdb.firebaseio.com/"
#define FIREBASE_AUTH "k1GYmcDzeZW76OOEW4NjV8nZkQlQTfugEzgoDmUk"
#define WIFI_SSID "iPhone 6"
#define WIFI_PASSWORD "qwertyuiop"


// Deklarasi Fuzzy
Fuzzy *fuzzy = new Fuzzy();

// Fuzzy Input Kemiringan Tanah
FuzzySet *datar_landai = new FuzzySet(0,3,5,8);
FuzzySet *agak_curam = new FuzzySet(8,15,25,35);
FuzzySet *sangat_curam = new FuzzySet(35,45,55,75);

// Fuzzy Input Kelembaban Tanah
FuzzySet *kering = new FuzzySet(0,10,15,26);
FuzzySet *lembab = new FuzzySet(26,35,50,75);
FuzzySet *basah = new FuzzySet(75,85,95,100);

// Fuzzy Input Pergeseran Tanah
FuzzySet *ringan = new FuzzySet(0,0.5, 1, 1,62);
FuzzySet *normal = new FuzzySet(1.62, 2.45, 2.85, 3.24);
FuzzySet *extreme = new FuzzySet(3.24, 4.5, 5.5, 6.5);

// Fuzzy Input Curah Hujan
FuzzySet *cerah_ringan = new FuzzySet(0,5,15,20);
FuzzySet *sedang = new FuzzySet(20,30,40,50);
FuzzySet *lebat_sangatlebat = new FuzzySet(50,70,90,120);

// FuzzySet Output
FuzzySet *aman = new FuzzySet(0, 15, 25, 35);
FuzzySet *waspada = new FuzzySet(35, 45, 55, 70);
FuzzySet *awas = new FuzzySet(70,80,90,100);

// Call Fuzzy Set And Fuzzy Rule

#include "2_fuzzy_set.h"
#include "3_fuzzy_rule.h"

// 



//Sensor 
#define raindigital 25 // Sensor hujan
#define RainPin 13 // Tipping bucket 
const int SOIL = A0; // soil 
const int swPin = 15 ; //Pin encoder
Encoder myEnc(2, 0); //Pin encoder

// komunikasi Lora
#define SS 18
#define RST 14
#define DI0 26  
#define BAND 915E6

DynamicJsonBuffer jsonBuffer;
Adafruit_MPU6050 mpu;


int counter = 0;
long oldPosition  = -999;
bool bucketPositionA = false;                          
const double bucketAmount = 1.46;        
const double bucketRain = 2.8;
boolean firstboot = true;
float dailyRain = 0.0;
float dailyRain2 = 0.0;                  
double hourlyRain = 0.0;                
double dailyRain_till_LastHour = 0.0;                   
bool first;  
int soilA;           
String id_menit;                  
unsigned long oldTime, oldTime2;
String data1,data2,data3,data4,data5,data6,data7,data8,data9,data10,data11,data12;
int sensorValue2 = 0;
String latitude = "-7.1880113";
String longitude = "107.6306125";
String Status;

float batas_pergeseran1 = 1.62;
float batas_pergeseran2 = 3.24;
float batas_kemiringan = 70;
float batas_kelembapan = 70;


void setup() {
  Serial.begin(115200);
//  SPI.begin(5, 19, 27, 18);
//  LoRa.setPins(SS, RST, DI0);
  pinMode(raindigital,INPUT);
  pinMode(swPin, INPUT);
  pinMode(RainPin, INPUT);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.setString("Perangkat1/engine","1");
  Firebase.setString("maps/lokasi/alat1/Latitude", latitude);
  Firebase.setString("maps/lokasi/alat1/Longitude", longitude);
  while (!Serial);

//  Serial.println("LoRa Sender");
//
//  if (!LoRa.begin(BAND)) {
//    Serial.println("Starting LoRa failed!");
//    while (1);
//  }
//
//  Serial.println("");
//  delay(100);
//  
//  while (!Serial)
//    delay(10); // will pause Zero, Leonardo, etc until serial console opens

  Serial.println("Adafruit MPU6050 test!");

  // Try to initialize!
  if (!mpu.begin()) {
    Serial.println("Failed to find MPU6050 chip");
    while (1) {
      delay(10);
    }
  }
  Serial.println("MPU6050 Found!");

  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
  Serial.print("Accelerometer range set to: ");
  switch (mpu.getAccelerometerRange()) {
  case MPU6050_RANGE_2_G:
    Serial.println("+-2G");
    break;
  case MPU6050_RANGE_4_G:
    Serial.println("+-4G");
    break;
  case MPU6050_RANGE_8_G:
    Serial.println("+-8G");
    break;
  case MPU6050_RANGE_16_G:
    Serial.println("+-16G");
    break;
  }
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);
  Serial.print("Gyro range set to: ");
  switch (mpu.getGyroRange()) {
  case MPU6050_RANGE_250_DEG:
    Serial.println("+- 250 deg/s");
    break;
  case MPU6050_RANGE_500_DEG:
    Serial.println("+- 500 deg/s");
    break;
  case MPU6050_RANGE_1000_DEG:
    Serial.println("+- 1000 deg/s");
    break;
  case MPU6050_RANGE_2000_DEG:
    Serial.println("+- 2000 deg/s");
    break;
  }

  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
  Serial.print("Filter bandwidth set to: ");
  switch (mpu.getFilterBandwidth()) {
  case MPU6050_BAND_260_HZ:
    Serial.println("260 Hz");
    break;
  case MPU6050_BAND_184_HZ:
    Serial.println("184 Hz");
    break;
  case MPU6050_BAND_94_HZ:
    Serial.println("94 Hz");
    break;
  case MPU6050_BAND_44_HZ:
    Serial.println("44 Hz");
    break;
  case MPU6050_BAND_21_HZ:
    Serial.println("21 Hz");
    break;
  case MPU6050_BAND_10_HZ:
    Serial.println("10 Hz");
    break;
  case MPU6050_BAND_5_HZ:
    Serial.println("5 Hz");
    break;
  }

  // Call function fuzzy on header

  fuzzySet();
  fuzzyRule();
  
  Serial.println("");
  delay(100);
}


void loop() {

 // Sensor kelembaban tanah
  int soilA = analogRead(SOIL);
  Serial.print("Analog Soil: ");
  Serial.println(soilA);
  soilA = map(soilA, 4095,800,0, 100);
  if (soilA>100){
      soilA=100;
    }
  else if (soilA<0){
      soilA=0;
    }

  Serial.print("persen Soil: ");
  Serial.println(soilA);
  Firebase.setInt("Perangkat1/kelembapantanah",soilA);

 sensorValue2 = digitalRead(raindigital);
  if (sensorValue2 == LOW)
{ 
  Serial.println("Status : Hujan");
if(firstboot == true){  
  int i = Firebase.getFloat("Perangkat1/id_menit"); 
  id_menit = String(i);
  firstboot = false;
}
   if ((bucketPositionA==false)&&(digitalRead(RainPin)==LOW)){
    bucketPositionA=true;
    dailyRain+=bucketAmount;                               // update the daily rain
    dailyRain2+=bucketAmount;                               // update the daily rain
    Serial.print(dailyRain2);
    Serial.println();
  }
  if ((bucketPositionA==true)&&(digitalRead(RainPin)==HIGH)){
    bucketPositionA=false;  
  }
  if (millis() - oldTime > 60000) // baca sinyal pulse setiap 10 milli second
  {   
      Serial.print(dailyRain,3);Serial.print(" mm");
      Serial.println();
      Serial.print(dailyRain2,3);Serial.print(" mm");
      Serial.println();
      JsonObject& hujanObject = jsonBuffer.createObject();
      JsonObject& tempTime = hujanObject.createNestedObject("timestamp");
      hujanObject["nilai"] = dailyRain2;
      tempTime[".sv"] = "timestamp";
      Firebase.push("Perangkat1/hujan/" + id_menit + "/hujanpermenit/", hujanObject);
      Firebase.set("Perangkat1/hujan/" + id_menit + "/total/", dailyRain);
      Firebase.set("Perangkat1/hujan/total", dailyRain); 
      //dailyRain2 = 0.0;
      float raindrop = Firebase.getFloat("Perangkat1/hujan/total");
      float hujan = raindrop + dailyRain; 
      Firebase.set("Perangkat1/hujan/total", hujan);
      oldTime = millis();
  }
}

else  
{
  Serial.println("Status : Tidak Hujan");
  Firebase.set("maps/lokasi/alat1/status", 0);
  dailyRain = 0.0;
  int a;
  int b = Firebase.getFloat("Perangkat1/id_menit");
  int id_menit2;  
  id_menit2 = (b + 1);
  //Serial.print(id_menit2);
  Serial.println();
  Firebase.set("Perangkat1/id_menit", id_menit2);

  int statusHujan = Firebase.getInt("maps/lokasi/alat1/status");
  while(statusHujan == 0) {
//    Serial.print(F("Tidak ada hujan! Nilai sensor: "));
//    Serial.println(sensorValue2);
     sensorValue2 = digitalRead(raindigital);
    if(sensorValue2 >=1){
      Firebase.set("maps/lokasi/alat1/status", 1);
    }
    //Serial.println(sensorValue2);
    statusHujan = Firebase.getInt("maps/lokasi/alat1/status");
    firstboot = true;
  }
}

  // Encoder
  long newPosition = myEnc.read();
  float pergeseran_tanah;
  float kecepatan,  posisi_sebelumnya;
  
  if (newPosition != oldPosition) {
    oldPosition = newPosition;
    Serial.println(newPosition);
    pergeseran_tanah = (newPosition / 4 * 1.62);
    Serial.print("Pergeseran tanah : ");
    Serial.println(pergeseran_tanah);
  } 
  
  if (pergeseran_tanah != posisi_sebelumnya) {
    delay(1000);
    kecepatan = pergeseran_tanah - posisi_sebelumnya;
  }
  posisi_sebelumnya = pergeseran_tanah;
  Firebase.setFloat("Perangkat1/pergeserantanah", pergeseran_tanah);
  //delay(1000);

  /* Get new sensor events with the readings */
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);

  /* Print out the values */
  Serial.print("Acceleration X: ");
  Serial.print(a.acceleration.x);
  Serial.print(", Y: ");
  Serial.print(a.acceleration.y);
  Serial.print(", Z: ");
  Serial.print(a.acceleration.z);
  Serial.println(" m/s^2");
//
  Serial.print("Rotation X: ");
  Serial.print(g.gyro.x);
  Serial.print(", Y: ");
  Serial.print(g.gyro.y);
  Serial.print(", Z: ");
  Serial.print(g.gyro.z);
  Serial.println(" rad/s");

  float kemiringan = (g.gyro.y*180) / 3.14;  
  Serial.print("Temperature: ");
  Serial.print(temp.temperature);
  Serial.println(" degC");
  Firebase.setFloat("Perangkat1/kemiringantanah", kemiringan);

 // Status Kebencanaan

if (soilA >= batas_kelembapan && kemiringan >= batas_kemiringan) {
   Status = "bahaya";
  } else if (pergeseran_tanah >= batas_pergeseran2 && soilA >= batas_kelembapan && kemiringan >= batas_kemiringan) {
    Status = "bahaya";
  } else if (pergeseran_tanah >= batas_pergeseran2 && soilA < batas_kelembapan && kemiringan < batas_kemiringan) {
    Status = "bahaya";
  } else if (pergeseran_tanah < batas_pergeseran2 && soilA < batas_kelembapan && kemiringan >= batas_kemiringan) {
    Status = "bahaya";
  } else if (pergeseran_tanah >= batas_pergeseran2 && soilA < batas_kelembapan && kemiringan >= batas_kemiringan) {
    Status = "bahaya";
  } else if (pergeseran_tanah >= batas_pergeseran1 && soilA < batas_kelembapan && kemiringan < batas_kemiringan) {
    Status = "waspada";
  } else if (pergeseran_tanah >= batas_pergeseran1 && soilA >= batas_kelembapan && kemiringan < batas_kemiringan) {
    Status = "waspada";
  } else if (pergeseran_tanah < batas_pergeseran1 && soilA >= batas_kelembapan && kemiringan < batas_kemiringan) {
    Status = "waspada";
  } else if (pergeseran_tanah < batas_pergeseran2 && soilA < batas_kelembapan && kemiringan >= batas_kemiringan) {
    Status = "waspada";
  }  else if (pergeseran_tanah < batas_pergeseran1 && soilA < batas_kelembapan && kemiringan < batas_kemiringan) {
    Status = "aman";
  } else if (pergeseran_tanah < batas_pergeseran1 && soilA > batas_kelembapan && kemiringan < batas_kemiringan) {
    Status = "aman";
  } else{
    Status = "waspada";
  }
  Serial.print("Status     : ");
  Serial.println(Status);

  if(Status != "aman")
  {
      Firebase.setString("Perangkat1/status", Status);
  }
  



// Input for fuzzy
//  Serial.println(kemiringan)
//  Serial.println(pergeseran_tanah)
//  Serial.println(soilA) // kelembapan tanah
//  Serial.println(dailyRain) // kelembapan tanah

}
