// This is a macro used to generate a neutrino flux
// that would result a uniform neutrino interaction
// in the energy range from 0 to 10 GeV

void gen_uniform_flux() {
  // It takes the cross section as the input
  TFile* xsec = new TFile("nue_ar40_xsec.root", "read");
  TGraph* nu_ar40_cc = (TGraph*)xsec->Get("nu_e_Ar40/tot_cc");
  TGraph* nu_ar40_nc = (TGraph*)xsec->Get("nu_e_Ar40/tot_nc");

  // TH1D for saving the new flux
  TH1D* newflux = new TH1D("nueflux", "nueflux", 100, 0, 10);
  for (int i = 0; i < 100; ++i) {
    double e = newflux->GetBinCenter(i+1);
    double totxsec = nu_ar40_cc->Eval(e) + nu_ar40_nc->Eval(e);
    double weight = 0.1/totxsec;
    newflux->SetBinContent(i+1, weight);
  }

  TFile* fluxfile = new TFile("nue_ar40_flux.root", "recreate");
  newflux->Write();
  fluxfile->Close();
}
