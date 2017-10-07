// Simple ROOT macro to plot a histogram.
// Modify arguments as needed.
// To execute, type .X plotUniform.C
{
  TFile* f = new TFile("simpleMC.root");
  f->ls();
  TH1F* h1 = (TH1F*)f.Get("h_Uniform");
  h1->SetMinimum(0.);
  h1->SetXTitle("r");
  h1->SetYTitle("f(r)");
  h1->Draw();


}
