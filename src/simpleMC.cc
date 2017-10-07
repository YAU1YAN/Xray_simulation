#include <iostream>
#include <cmath>
#include <TH1D.h>
#include <TFile.h>
#include <TRandom3.h>
#include "Xray.hpp"
#include "AxisUtility.hpp"

using namespace std;

int main(){

  Xray* simulator = new Xray();
  AxisUtility* axisUtility = new AxisUtility();

  int N = 4000000;
  float thickness = 0;
  float thicknessStep = 1000;



  float* x = axisUtility->xAxisArray();
  float* y = axisUtility->yAxisArray();

  float* x2 = axisUtility->xAxisArray2();
  float* y2 = axisUtility->yAxisArray2();

  for (int i = 0; i < 1; ++i){
      thickness = (i * thicknessStep);
      simulator->run(x, y, x2, y2, N, thickness);
  }
  // simulator->run(x, y, x2, y2, N, thickness);


/*
  cout << "\n acceptable photons: " << length << "\n"; // no member acceptedElength?
  cout << "\n penetrated photons: " << pLength << "\n";
  cout << "\n mean energy: " << simulator->getMeanEnergy() << "\n";
  cout << "\n median energy: " << simulator->getMedianEnergy() << "\n";
*/
  delete simulator;
  delete axisUtility;
// Store all histograms in the output file and close up
  return 0;
}
