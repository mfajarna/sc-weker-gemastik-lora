void fuzzySet () {

  
  // FuzzyInput Kemiringan Tanah
  FuzzyInput *kemiringan_tanah = new FuzzyInput(1);

  kemiringan_tanah->addFuzzySet(datar_landai);
  kemiringan_tanah->addFuzzySet(agak_curam);
  kemiringan_tanah->addFuzzySet(sangat_curam);
  
  fuzzy->addFuzzyInput(kemiringan_tanah);



  // FuzzyInput KELEMBABAN
  FuzzyInput *kelembaban_tanah = new FuzzyInput(2);

  kelembaban_tanah->addFuzzySet(kering);
  kelembaban_tanah->addFuzzySet(lembab);
  kelembaban_tanah->addFuzzySet(basah);

  fuzzy->addFuzzyInput(kelembaban_tanah);



  // FuzzyInput Pergeseran Tanah
  FuzzyInput *pergeseran_tanah = new FuzzyInput(3);

  pergeseran_tanah->addFuzzySet(ringan);
  pergeseran_tanah->addFuzzySet(normal);
  pergeseran_tanah->addFuzzySet(extreme);
  fuzzy->addFuzzyInput(pergeseran_tanah);

  
  // FuzzyInput Curah Hujan
  FuzzyInput *curah_hujan = new FuzzyInput(4);

  curah_hujan->addFuzzySet(cerah_ringan);
  curah_hujan->addFuzzySet(sedang);
  curah_hujan->addFuzzySet(lebat_sangatlebat);
  
  fuzzy->addFuzzyInput(curah_hujan);



  // FuzzyOutput Status Bencana
  FuzzyOutput *status_bencana = new FuzzyOutput(1);

  status_bencana->addFuzzySet(aman);
  status_bencana->addFuzzySet(waspada);
  status_bencana->addFuzzySet(awas);

  fuzzy->addFuzzyOutput(status_bencana);




  
}
