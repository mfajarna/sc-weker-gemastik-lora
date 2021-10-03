void fuzzyRule () {
  
  // Building FuzzyRule////////////////////////////////////////////////////////////////// 1
  FuzzyRuleAntecedent *cerahRingan_datarLandai_1 = new FuzzyRuleAntecedent();
  cerahRingan_datarLandai_1->joinWithAND(cerah_ringan, datar_landai);

  FuzzyRuleAntecedent *lembab_1 = new FuzzyRuleAntecedent();
  lembab_1->joinSingle(lembab);

  FuzzyRuleAntecedent *cerahRingan_datarLandai_lembab_1 = new FuzzyRuleAntecedent();
  cerahRingan_datarLandai_lembab_1->joinWithAND(cerahRingan_datarLandai_1, lembab_1);

  FuzzyRuleAntecedent *extreme_1 = new FuzzyRuleAntecedent();
  extreme_1->joinSingle(extreme);

  FuzzyRuleAntecedent *cerahRingan_datarLandai_lembab_extreme_1 = new FuzzyRuleAntecedent();
  cerahRingan_datarLandai_lembab_extreme_1->joinWithAND(cerahRingan_datarLandai_lembab_1, extreme_1);


  FuzzyRuleConsequent *waspada_1 = new FuzzyRuleConsequent();
  waspada_1->addOutput(waspada);

  FuzzyRule *fuzzyRule1 = new FuzzyRule(1, cerahRingan_datarLandai_lembab_extreme_1, waspada_1);
  fuzzy->addFuzzyRule(fuzzyRule1);

  // Building FuzzyRule////////////////////////////////////////////////////////////////// 2
  FuzzyRuleAntecedent *cerahRingan_agakCuram_2 = new FuzzyRuleAntecedent();
  cerahRingan_agakCuram_2->joinWithAND(cerah_ringan, agak_curam);

  FuzzyRuleAntecedent *basah_2 = new FuzzyRuleAntecedent();
  basah_2->joinSingle(basah);

  FuzzyRuleAntecedent *cerahRingan_agakCuram_basah_2 = new FuzzyRuleAntecedent();
  cerahRingan_agakCuram_basah_2->joinWithAND(cerahRingan_agakCuram_2, basah_2);

  FuzzyRuleAntecedent *extreme_2 = new FuzzyRuleAntecedent();
  extreme_2->joinSingle(extreme);

  FuzzyRuleAntecedent *cerahRingan_agakCuram_basah_extreme_2 = new FuzzyRuleAntecedent();
  cerahRingan_agakCuram_basah_extreme_2->joinWithAND(cerahRingan_agakCuram_basah_2, extreme_2);


  FuzzyRuleConsequent *bahaya_2 = new FuzzyRuleConsequent();
  bahaya_2->addOutput(bahaya);

  FuzzyRule *fuzzyRule2 = new FuzzyRule(2, cerahRingan_agakCuram_basah_extreme_2, bahaya_2);
  fuzzy->addFuzzyRule(fuzzyRule2);

  // Building FuzzyRule////////////////////////////////////////////////////////////////// 3
  FuzzyRuleAntecedent *cerahRingan_agakCuram_3 = new FuzzyRuleAntecedent();
  cerahRingan_agakCuram_3->joinWithAND(cerah_ringan, agak_curam);

  FuzzyRuleAntecedent *lembab_3 = new FuzzyRuleAntecedent();
  lembab_3->joinSingle(lembab);

  FuzzyRuleAntecedent *cerahRingan_agakCuram_lembab_3 = new FuzzyRuleAntecedent();
  cerahRingan_agakCuram_lembab_3->joinWithAND(cerahRingan_agakCuram_3, lembab_3);

  FuzzyRuleAntecedent *ringan_3 = new FuzzyRuleAntecedent();
  ringan_3->joinSingle(ringan);

  FuzzyRuleAntecedent *cerahRingan_agakCuram_lembab_ringan_3 = new FuzzyRuleAntecedent();
  cerahRingan_agakCuram_lembab_ringan_3->joinWithAND(cerahRingan_agakCuram_lembab_ringan_3, ringan_3);

  FuzzyRuleConsequent *waspada_3 = new FuzzyRuleConsequent();
  waspada_3->addOutput(waspada);


  FuzzyRule *fuzzyRule3 = new FuzzyRule(3, cerahRingan_agakCuram_lembab_ringan_3, waspada_2);
  fuzzy->addFuzzyRule(fuzzyRule3);
  
  // Building FuzzyRule////////////////////////////////////////////////////////////////// 4

  FuzzyRuleAntecedent *sangatLebat_sangatCuram_4 = new FuzzyRuleAntecedent();
  sangatLebat_sangatCuram_4->joinWithAND(sangat_lebat, sangat_curam);

  FuzzyRuleAntecedent *lembab_4 = new FuzzyRuleAntecedent();
  lembab_4->joinSingle(lembab)

  
  FuzzyRuleAntecedent *sangatLebat_sangatCuram_lembab_4 = new FuzzyRuleAntecedent();
  sangatLebat_sangatCuram_lembab_4->joinWithAND(sangatLebat_sangatCuram_4, lembab_4);

  
  FuzzyRuleAntecedent *extreme_4 = new FuzzyRuleAntecedent();
  extreme_4->joinSingle(extreme);

  FuzzyRuleAntecedent *sangatLebat_sangatCuram_extreme_4 = new FuzzyRuleAntecedent();
  sangatLebat_sangatCuram_extreme_4->joinWithAND(sangatLebat_sangatCuram_lembab_4, extreme_4);

  FuzzyRuleConsequent *bahaya_4 = new FuzzyRuleConsequent();
  bahaya_4->addOutput(bahaya);

  
  FuzzyRule *fuzzyRule4 = new FuzzyRule(4, sangatLebat_sangatCuram_extreme_4, bahaya_4);
  fuzzy->addFuzzyRule(fuzzyRule4);
  
  

  
  }
