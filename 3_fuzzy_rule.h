void fuzzyRule () {
  
  // Building FuzzyRule////////////////////////////////////////////////////////////////// 1
  FuzzyRuleAntecedent *dingin_kering_1 = new FuzzyRuleAntecedent();
  dingin_kering_1->joinWithAND(dingin, kering);

  FuzzyRuleAntecedent *c_gelap = new FuzzyRuleAntecedent();
  c_gelap->joinSingle(gelap);

  FuzzyRuleAntecedent *dingin_kering_gelap_1 = new FuzzyRuleAntecedent();
  dingin_kering_gelap_1->joinWithAND(dingin_kering_1, c_gelap);

  FuzzyRuleConsequent *c_t_1 = new FuzzyRuleConsequent();
  c_t_1->addOutput(c);
  c_t_1->addOutput(t);

  FuzzyRule *fuzzyRule1 = new FuzzyRule(1, dingin_kering_gelap_1, c_t_1);
  fuzzy->addFuzzyRule(fuzzyRule1);

  // Building FuzzyRule////////////////////////////////////////////////////////////////// 2
  FuzzyRuleAntecedent *dingin_kering_2 = new FuzzyRuleAntecedent();
  dingin_kering_2->joinWithAND(dingin, kering);

  FuzzyRuleAntecedent *c_normal_cahaya = new FuzzyRuleAntecedent();
  c_normal_cahaya->joinSingle(normal_cahaya);

  FuzzyRuleAntecedent *dingin_kering_normal_cahaya_2 = new FuzzyRuleAntecedent();
  dingin_kering_normal_cahaya_2->joinWithAND(dingin_kering_2, c_normal_cahaya);

  FuzzyRuleConsequent *c_n_lampu_2 = new FuzzyRuleConsequent();
  c_n_lampu_2->addOutput(c);
  c_n_lampu_2->addOutput(n_lampu);

  FuzzyRule *fuzzyRule2 = new FuzzyRule(2, dingin_kering_normal_cahaya_2, c_n_lampu_2);
  fuzzy->addFuzzyRule(fuzzyRule2);

  // Building FuzzyRule////////////////////////////////////////////////////////////////// 3
  FuzzyRuleAntecedent *dingin_kering_3 = new FuzzyRuleAntecedent();
  dingin_kering_3->joinWithAND(dingin, kering);

  FuzzyRuleAntecedent *c_terang = new FuzzyRuleAntecedent();
  c_terang->joinSingle(terang);

  FuzzyRuleAntecedent *dingin_kering_terang_3 = new FuzzyRuleAntecedent();
  dingin_kering_terang_3->joinWithAND(dingin_kering_3, c_terang);

  FuzzyRuleConsequent *c_r_3 = new FuzzyRuleConsequent();
  c_r_3->addOutput(c);
  c_r_3->addOutput(r);

  FuzzyRule *fuzzyRule3 = new FuzzyRule(3, dingin_kering_terang_3, c_r_3);
  fuzzy->addFuzzyRule(fuzzyRule3);

  // Building FuzzyRule////////////////////////////////////////////////////////////////// 4
  FuzzyRuleAntecedent *dingin_normal_kelembaban_4 = new FuzzyRuleAntecedent();
  dingin_normal_kelembaban_4->joinWithAND(dingin, normal_kelembaban);

  FuzzyRuleAntecedent *dingin_normal_kelembaban_gelap_4 = new FuzzyRuleAntecedent();
  dingin_normal_kelembaban_gelap_4->joinWithAND(dingin_normal_kelembaban_4, c_gelap);

  FuzzyRuleConsequent *sc_t_4 = new FuzzyRuleConsequent();
  sc_t_4->addOutput(sc);
  sc_t_4->addOutput(t);

  FuzzyRule *fuzzyRule4 = new FuzzyRule(4, dingin_normal_kelembaban_gelap_4, sc_t_4);
  fuzzy->addFuzzyRule(fuzzyRule4);

  // Building FuzzyRule////////////////////////////////////////////////////////////////// 5
  FuzzyRuleAntecedent *dingin_normal_kelembaban_5 = new FuzzyRuleAntecedent();
  dingin_normal_kelembaban_5->joinWithAND(dingin, normal_kelembaban);

  FuzzyRuleAntecedent *dingin_normal_kelembaban_normal_cahaya_5 = new FuzzyRuleAntecedent();
  dingin_normal_kelembaban_normal_cahaya_5->joinWithAND(dingin_normal_kelembaban_5, c_normal_cahaya);

  FuzzyRuleConsequent *sc_n_lampu_5 = new FuzzyRuleConsequent();
  sc_n_lampu_5->addOutput(sc);
  sc_n_lampu_5->addOutput(n_lampu);

  FuzzyRule *fuzzyRule5 = new FuzzyRule(5, dingin_normal_kelembaban_normal_cahaya_5, sc_n_lampu_5);
  fuzzy->addFuzzyRule(fuzzyRule5);

  // Building FuzzyRule////////////////////////////////////////////////////////////////// 6
  FuzzyRuleAntecedent *dingin_normal_kelembaban_6 = new FuzzyRuleAntecedent();
  dingin_normal_kelembaban_6->joinWithAND(dingin, normal_kelembaban);

  FuzzyRuleAntecedent *dingin_normal_kelembaban_terang_6 = new FuzzyRuleAntecedent();
  dingin_normal_kelembaban_terang_6->joinWithAND(dingin_normal_kelembaban_6, c_terang);

  FuzzyRuleConsequent *sc_r_6 = new FuzzyRuleConsequent();
  sc_r_6->addOutput(sc);
  sc_r_6->addOutput(r);

  FuzzyRule *fuzzyRule6 = new FuzzyRule(6, dingin_normal_kelembaban_terang_6, sc_r_6);
  fuzzy->addFuzzyRule(fuzzyRule6);

  // Building FuzzyRule////////////////////////////////////////////////////////////////// 7
  FuzzyRuleAntecedent *dingin_basah_7 = new FuzzyRuleAntecedent();
  dingin_basah_7->joinWithAND(dingin, basah);

  FuzzyRuleAntecedent *dingin_basah_gelap_7 = new FuzzyRuleAntecedent();
  dingin_basah_gelap_7->joinWithAND(dingin_basah_7, c_gelap);

  FuzzyRuleConsequent *sc_st_7 = new FuzzyRuleConsequent();
  sc_st_7->addOutput(sc);
  sc_st_7->addOutput(st);

  FuzzyRule *fuzzyRule7 = new FuzzyRule(7, dingin_basah_gelap_7, sc_st_7);
  fuzzy->addFuzzyRule(fuzzyRule7);

  // Building FuzzyRule////////////////////////////////////////////////////////////////// 8
  FuzzyRuleAntecedent *dingin_basah_8 = new FuzzyRuleAntecedent();
  dingin_basah_8->joinWithAND(dingin, basah);

  FuzzyRuleAntecedent *dingin_basah_normal_cahaya_8 = new FuzzyRuleAntecedent();
  dingin_basah_normal_cahaya_8->joinWithAND(dingin_basah_8, c_normal_cahaya);

  FuzzyRuleConsequent *sc_t_8 = new FuzzyRuleConsequent();
  sc_t_8->addOutput(sc);
  sc_t_8->addOutput(t);

  FuzzyRule *fuzzyRule8 = new FuzzyRule(8, dingin_basah_normal_cahaya_8, sc_t_8);
  fuzzy->addFuzzyRule(fuzzyRule8);

  // Building FuzzyRule////////////////////////////////////////////////////////////////// 9
  FuzzyRuleAntecedent *dingin_basah_9 = new FuzzyRuleAntecedent();
  dingin_basah_9->joinWithAND(dingin, basah);

  FuzzyRuleAntecedent *dingin_basah_terang_9 = new FuzzyRuleAntecedent();
  dingin_basah_terang_9->joinWithAND(dingin_basah_9, c_terang);

  FuzzyRuleConsequent *sc_n_lampu_9 = new FuzzyRuleConsequent();
  sc_n_lampu_9->addOutput(sc);
  sc_n_lampu_9->addOutput(n_lampu);

  FuzzyRule *fuzzyRule9 = new FuzzyRule(9, dingin_basah_terang_9, sc_n_lampu_9);
  fuzzy->addFuzzyRule(fuzzyRule9);

  // Building FuzzyRule////////////////////////////////////////////////////////////////// 10
  FuzzyRuleAntecedent *normal_suhu_kering_10 = new FuzzyRuleAntecedent();
  normal_suhu_kering_10->joinWithAND(normal_suhu, kering);

  FuzzyRuleAntecedent *normal_suhu_kering_gelap_10 = new FuzzyRuleAntecedent();
  normal_suhu_kering_gelap_10->joinWithAND(normal_suhu_kering_10, c_gelap);

  FuzzyRuleConsequent *n_pompa_n_lampu_10 = new FuzzyRuleConsequent();
  n_pompa_n_lampu_10->addOutput(n_pompa);
  n_pompa_n_lampu_10->addOutput(n_lampu);

  FuzzyRule *fuzzyRule10 = new FuzzyRule(10, normal_suhu_kering_gelap_10, n_pompa_n_lampu_10);
  fuzzy->addFuzzyRule(fuzzyRule10);

  // Building FuzzyRule////////////////////////////////////////////////////////////////// 11
  FuzzyRuleAntecedent *normal_suhu_kering_11 = new FuzzyRuleAntecedent();
  normal_suhu_kering_11->joinWithAND(normal_suhu, kering);

  FuzzyRuleAntecedent *normal_suhu_kering_normal_cahaya_11 = new FuzzyRuleAntecedent();
  normal_suhu_kering_normal_cahaya_11->joinWithAND(normal_suhu_kering_11, c_normal_cahaya);

  FuzzyRuleConsequent *n_pompa_r_11 = new FuzzyRuleConsequent();
  n_pompa_r_11->addOutput(n_pompa);
  n_pompa_r_11->addOutput(r);

  FuzzyRule *fuzzyRule11 = new FuzzyRule(11, normal_suhu_kering_normal_cahaya_11, n_pompa_r_11);
  fuzzy->addFuzzyRule(fuzzyRule11);

  // Building FuzzyRule////////////////////////////////////////////////////////////////// 12
  FuzzyRuleAntecedent *normal_suhu_kering_12 = new FuzzyRuleAntecedent();
  normal_suhu_kering_12->joinWithAND(normal_suhu, kering);

  FuzzyRuleAntecedent *normal_suhu_kering_terang_12 = new FuzzyRuleAntecedent();
  normal_suhu_kering_terang_12->joinWithAND(normal_suhu_kering_12, c_terang);

  FuzzyRuleConsequent *n_pompa_sr_12 = new FuzzyRuleConsequent();
  n_pompa_sr_12->addOutput(n_pompa);
  n_pompa_sr_12->addOutput(sr);

  FuzzyRule *fuzzyRule12 = new FuzzyRule(12, normal_suhu_kering_terang_12, n_pompa_sr_12);
  fuzzy->addFuzzyRule(fuzzyRule12);

  // Building FuzzyRule////////////////////////////////////////////////////////////////// 13
  FuzzyRuleAntecedent *normal_suhu_normal_kelembaban_13 = new FuzzyRuleAntecedent();
  normal_suhu_normal_kelembaban_13->joinWithAND(normal_suhu, normal_kelembaban);
  
  FuzzyRuleAntecedent *normal_suhu_normal_kelembaban_gelap_13 = new FuzzyRuleAntecedent();
  normal_suhu_normal_kelembaban_gelap_13->joinWithAND(normal_suhu_normal_kelembaban_13, c_gelap);

  FuzzyRuleConsequent *sc_n_lampu_13 = new FuzzyRuleConsequent();
  sc_n_lampu_13->addOutput(sc);
  sc_n_lampu_13->addOutput(n_lampu);

  FuzzyRule *fuzzyRule13 = new FuzzyRule(13, normal_suhu_normal_kelembaban_gelap_13, sc_n_lampu_13);
  fuzzy->addFuzzyRule(fuzzyRule13);

  // Building FuzzyRule////////////////////////////////////////////////////////////////// 14
  FuzzyRuleAntecedent *normal_suhu_normal_kelembaban_14 = new FuzzyRuleAntecedent();
  normal_suhu_normal_kelembaban_14->joinWithAND(normal_suhu, normal_kelembaban);

  FuzzyRuleAntecedent *normal_suhu_normal_kelembaban_normal_cahaya_14 = new FuzzyRuleAntecedent();
  normal_suhu_normal_kelembaban_normal_cahaya_14->joinWithAND(normal_suhu_normal_kelembaban_14, c_normal_cahaya );

  FuzzyRuleConsequent *sc_sr_14 = new FuzzyRuleConsequent();
  sc_sr_14->addOutput(sc);
  sc_sr_14->addOutput(sr);

  FuzzyRule *fuzzyRule14 = new FuzzyRule(14, normal_suhu_normal_kelembaban_normal_cahaya_14, sc_sr_14);
  fuzzy->addFuzzyRule(fuzzyRule14);

  // Building FuzzyRule////////////////////////////////////////////////////////////////// 15
  FuzzyRuleAntecedent *normal_suhu_normal_kelembaban_15 = new FuzzyRuleAntecedent();
  normal_suhu_normal_kelembaban_15->joinWithAND(normal_suhu, normal_kelembaban);

  FuzzyRuleAntecedent *normal_suhu_normal_kelembaban_terang_15 = new FuzzyRuleAntecedent();
  normal_suhu_normal_kelembaban_terang_15->joinWithAND(normal_suhu_normal_kelembaban_15, c_terang);

  FuzzyRuleConsequent *sc_sr_15 = new FuzzyRuleConsequent();
  sc_sr_15->addOutput(sc);
  sc_sr_15->addOutput(sr);

  FuzzyRule *fuzzyRule15 = new FuzzyRule(15, normal_suhu_normal_kelembaban_terang_15, sc_sr_15);
  fuzzy->addFuzzyRule(fuzzyRule15);

  // Building FuzzyRule////////////////////////////////////////////////////////////////// 16
  FuzzyRuleAntecedent *normal_suhu_basah_16 = new FuzzyRuleAntecedent();
  normal_suhu_basah_16->joinWithAND(normal_suhu, basah);

  FuzzyRuleAntecedent *normal_suhu_basah_gelap_16 = new FuzzyRuleAntecedent();
  normal_suhu_basah_gelap_16->joinWithAND(normal_suhu_basah_16, c_gelap);

  FuzzyRuleConsequent *sc_st_16 = new FuzzyRuleConsequent();
  sc_st_16->addOutput(sc);
  sc_st_16->addOutput(st);

  FuzzyRule *fuzzyRule16 = new FuzzyRule(16, normal_suhu_basah_gelap_16, sc_st_16);
  fuzzy->addFuzzyRule(fuzzyRule16);

  // Building FuzzyRule////////////////////////////////////////////////////////////////// 17
  FuzzyRuleAntecedent *normal_suhu_basah_17 = new FuzzyRuleAntecedent();
  normal_suhu_basah_17->joinWithAND(normal_suhu, basah);

  FuzzyRuleAntecedent *normal_suhu_basah_normal_cahaya_17 = new FuzzyRuleAntecedent();
  normal_suhu_basah_normal_cahaya_17->joinWithAND(normal_suhu_basah_17, c_normal_cahaya);

  FuzzyRuleConsequent *sc_r_17 = new FuzzyRuleConsequent();
  sc_r_17->addOutput(sc);
  sc_r_17->addOutput(r);

  FuzzyRule *fuzzyRule17 = new FuzzyRule(17, normal_suhu_basah_normal_cahaya_17, sc_r_17);
  fuzzy->addFuzzyRule(fuzzyRule17);

  // Building FuzzyRule////////////////////////////////////////////////////////////////// 18
  FuzzyRuleAntecedent *normal_suhu_basah_18 = new FuzzyRuleAntecedent();
  normal_suhu_basah_18->joinWithAND(normal_suhu, basah);

  FuzzyRuleAntecedent *normal_suhu_basah_terang_18 = new FuzzyRuleAntecedent();
  normal_suhu_basah_terang_18->joinWithAND(normal_suhu_basah_18, c_terang);

  FuzzyRuleConsequent *sc_n_lampu_18 = new FuzzyRuleConsequent();
  sc_n_lampu_18->addOutput(sc);
  sc_n_lampu_18->addOutput(n_lampu);

  FuzzyRule *fuzzyRule18 = new FuzzyRule(18, normal_suhu_basah_terang_18, sc_n_lampu_18);
  fuzzy->addFuzzyRule(fuzzyRule18);

  // Building FuzzyRule////////////////////////////////////////////////////////////////// 19
  FuzzyRuleAntecedent *panas_kering_19 = new FuzzyRuleAntecedent();
  panas_kering_19->joinWithAND(panas, kering);

  FuzzyRuleAntecedent *panas_kering_gelap_19 = new FuzzyRuleAntecedent();
  panas_kering_gelap_19->joinWithAND(panas_kering_19, c_gelap);

  FuzzyRuleConsequent *sl_r_19 = new FuzzyRuleConsequent();
  sl_r_19->addOutput(sl);
  sl_r_19->addOutput(r);

  FuzzyRule *fuzzyRule19 = new FuzzyRule(19, panas_kering_gelap_19, sl_r_19);
  fuzzy->addFuzzyRule(fuzzyRule19);

  // Building FuzzyRule////////////////////////////////////////////////////////////////// 20
  FuzzyRuleAntecedent *panas_kering_20 = new FuzzyRuleAntecedent();
  panas_kering_20->joinWithAND(panas, kering);

  FuzzyRuleAntecedent *panas_kering_normal_cahaya_20 = new FuzzyRuleAntecedent();
  panas_kering_normal_cahaya_20->joinWithAND(panas_kering_20, c_normal_cahaya);

  FuzzyRuleConsequent *sl_sr_20 = new FuzzyRuleConsequent();
  sl_sr_20->addOutput(sl);
  sl_sr_20->addOutput(sr);

  FuzzyRule *fuzzyRule20 = new FuzzyRule(20, panas_kering_normal_cahaya_20, sl_sr_20);
  fuzzy->addFuzzyRule(fuzzyRule20);

  // Building FuzzyRule////////////////////////////////////////////////////////////////// 21
  FuzzyRuleAntecedent *panas_kering_21 = new FuzzyRuleAntecedent();
  panas_kering_21->joinWithAND(panas, kering);

  FuzzyRuleAntecedent *panas_kering_terang_21 = new FuzzyRuleAntecedent();
  panas_kering_terang_21->joinWithAND(panas_kering_21, c_terang);

  FuzzyRuleConsequent *sl_sr_21 = new FuzzyRuleConsequent();
  sl_sr_21->addOutput(sl);
  sl_sr_21->addOutput(sr);

  FuzzyRule *fuzzyRule21 = new FuzzyRule(21, panas_kering_terang_21, sl_sr_21);
  fuzzy->addFuzzyRule(fuzzyRule21);

  // Building FuzzyRule////////////////////////////////////////////////////////////////// 22
  FuzzyRuleAntecedent *panas_normal_kelembaban_22 = new FuzzyRuleAntecedent();
  panas_normal_kelembaban_22->joinWithAND(panas, normal_kelembaban);

  FuzzyRuleAntecedent *panas_normal_kelembaban_gelap_22 = new FuzzyRuleAntecedent();
  panas_normal_kelembaban_gelap_22->joinWithAND(panas_normal_kelembaban_22, c_gelap);

  FuzzyRuleConsequent *l_t_22 = new FuzzyRuleConsequent();
  l_t_22->addOutput(l);
  l_t_22->addOutput(t);

  FuzzyRule *fuzzyRule22 = new FuzzyRule(22, panas_normal_kelembaban_gelap_22, l_t_22);
  fuzzy->addFuzzyRule(fuzzyRule22);

  // Building FuzzyRule////////////////////////////////////////////////////////////////// 23
  FuzzyRuleAntecedent *panas_normal_kelembaban_23 = new FuzzyRuleAntecedent();
  panas_normal_kelembaban_23->joinWithAND(panas, normal_kelembaban);

  FuzzyRuleAntecedent *panas_normal_kelembaban_normal_cahaya_23 = new FuzzyRuleAntecedent();
  panas_normal_kelembaban_normal_cahaya_23->joinWithAND(panas_normal_kelembaban_23, c_normal_cahaya);

  FuzzyRuleConsequent *l_r_23 = new FuzzyRuleConsequent();
  l_r_23->addOutput(l);
  l_r_23->addOutput(r);

  FuzzyRule *fuzzyRule23 = new FuzzyRule(23, panas_normal_kelembaban_normal_cahaya_23, l_r_23);
  fuzzy->addFuzzyRule(fuzzyRule23);

  // Building FuzzyRule////////////////////////////////////////////////////////////////// 24
  FuzzyRuleAntecedent *panas_normal_kelembaban_24 = new FuzzyRuleAntecedent();
  panas_normal_kelembaban_24->joinWithAND(panas, normal_kelembaban);

  FuzzyRuleAntecedent *panas_normal_kelembaban_terang_24 = new FuzzyRuleAntecedent();
  panas_normal_kelembaban_terang_24->joinWithAND(panas_normal_kelembaban_24, c_terang);

  FuzzyRuleConsequent *l_sr_24 = new FuzzyRuleConsequent();
  l_sr_24->addOutput(l);
  l_sr_24->addOutput(sr);

  FuzzyRule *fuzzyRule24 = new FuzzyRule(24, panas_normal_kelembaban_terang_24, l_sr_24);
  fuzzy->addFuzzyRule(fuzzyRule24);

  // Building FuzzyRule////////////////////////////////////////////////////////////////// 25
  FuzzyRuleAntecedent *panas_basah_25 = new FuzzyRuleAntecedent();
  panas_basah_25->joinWithAND(panas, basah);

  FuzzyRuleAntecedent *panas_basah_gelap_25 = new FuzzyRuleAntecedent();
  panas_basah_gelap_25->joinWithAND(panas_basah_25, c_gelap);

  FuzzyRuleConsequent *n_pompa_st_25 = new FuzzyRuleConsequent();
  n_pompa_st_25->addOutput(n_pompa);
  n_pompa_st_25->addOutput(st);

  FuzzyRule *fuzzyRule25 = new FuzzyRule(25, panas_basah_gelap_25, n_pompa_st_25);
  fuzzy->addFuzzyRule(fuzzyRule25);

  // Building FuzzyRule////////////////////////////////////////////////////////////////// 26
  FuzzyRuleAntecedent *panas_basah_26 = new FuzzyRuleAntecedent();
  panas_basah_26->joinWithAND(panas, basah);

  FuzzyRuleAntecedent *panas_basah_normal_cahaya_26 = new FuzzyRuleAntecedent();
  panas_basah_normal_cahaya_26->joinWithAND(panas_basah_26, c_normal_cahaya);

  FuzzyRuleConsequent *n_pompa_t_26 = new FuzzyRuleConsequent();
  n_pompa_t_26->addOutput(n_pompa);
  n_pompa_t_26->addOutput(t);

  FuzzyRule *fuzzyRule26 = new FuzzyRule(26, panas_basah_normal_cahaya_26, n_pompa_t_26);
  fuzzy->addFuzzyRule(fuzzyRule26);

  // Building FuzzyRule////////////////////////////////////////////////////////////////// 27
  FuzzyRuleAntecedent *panas_basah_27 = new FuzzyRuleAntecedent();
  panas_basah_27->joinWithAND(panas, basah);

  FuzzyRuleAntecedent *panas_basah_terang_27 = new FuzzyRuleAntecedent();
  panas_basah_terang_27->joinWithAND(panas_basah_27, c_terang);

  FuzzyRuleConsequent *n_pompa_r_27 = new FuzzyRuleConsequent();
  n_pompa_r_27->addOutput(n_pompa);
  n_pompa_r_27->addOutput(r);

  FuzzyRule *fuzzyRule27 = new FuzzyRule(27, panas_basah_terang_27, n_pompa_r_27);
  fuzzy->addFuzzyRule(fuzzyRule27);

  }
