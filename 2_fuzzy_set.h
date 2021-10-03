void fuzzySet () {

  
  // FuzzyInput Kemiringan Tanah
  FuzzyInput *kemiringan_tanah = new FuzzyInput(1);

  suhu->addFuzzySet(datar_landai);
  suhu->addFuzzySet(agak_curam);
  suhu->addFuzzySet(sangat_curam);
  
  fuzzy->addFuzzyInput(kemiringan_tanah);



  // FuzzyInput KELEMBABAN
  FuzzyInput *kelembaban_tanah = new FuzzyInput(2);

  kelembaban->addFuzzySet(kering);
  kelembaban->addFuzzySet(lembab);
  kelembaban->addFuzzySet(basah);

  fuzzy->addFuzzyInput(kelembaban_tanah);



  // FuzzyInput Pergeseran Tanah
  FuzzyInput *pergeseran_tanah = new FuzzyInput(3);

  cahaya->addFuzzySet(ringan);
  cahaya->addFuzzySet(normal);
  cahaya->addFuzzySet(extreme);
  fuzzy->addFuzzyInput(pergeseran_tanah);

  
  // FuzzyInput Curah Hujan
  FuzzyInput *curah_hujan = new FuzzyInput(4);

  cahaya->addFuzzySet(cerah_ringan);
  cahaya->addFuzzySet(sedang);
  cahaya->addFuzzySet(lebat_sangatlebat);
  
  fuzzy->addFuzzyInput(curah_hujan);



  // FuzzyOutput Status Bencana
  FuzzyOutput *status_bencana = new FuzzyOutput(1);

  pompa->addFuzzySet(aman);
  pompa->addFuzzySet(waspada);
  pompa->addFuzzySet(awas);

  fuzzy->addFuzzyOutput(status_bencana);




  
}
