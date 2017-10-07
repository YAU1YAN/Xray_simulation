#ifndef _XRAY_HPP_
#define _XRAY_HPP_

#include <iostream>
#include <fstream>
#include <sstream>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <algorithm>
#include <cmath>
#include <TH1D.h>
#include <TFile.h>
#include <TRandom3.h>

#include "SortSearch.hpp"
#include "RandomNumberGenerator.hpp"

class Xray {
private:
	/** 
	 * table is of row 101, column 2
	 */
	void xrayReadOutTest();

	
	/**
	 * A collection of sorting and searching algorithms
	 */
	SortSearch sortSearch;

 	/**
 	 * N = elements of array you want to print
 	 */
	void printArrays(float* array, int N);
	float* generateRandom();
	float* generateRandomT();
	float* generateRandomMLCG();
	float simulatedPhoton(float* x, float* y, int N, int i, float* r);
	float simulatePenetration(float* x2, float* y2, float E, int N, float thickness,  int i, float* r);
	float sumP;
	float sumPsqr;
	float sigma;
	float meanEnergy;
	int acceptablePhotons;
	int total;
	bool accept;
	bool penetrate;
	float sigmaA;

public:
	Xray() {
		srand(time(NULL));
		sortSearch = SortSearch();
		sumP = 0.0;
		sumPsqr = 0.0;
		sigma = 0.0;
		sigmaA = 0.0;
		meanEnergy = 0.0;
		acceptablePhotons = 0;
		total = 0;
		accept = false;
		penetrate = false;
	}
	virtual ~Xray() {}


	/************
	 * NOT USED *
	 ************/
	void randomnessTest();

	/**
	 * the monte carlo selection after binary search give an array stuffed with accepted photon energy,
	 * attached -1 as end mark
	 */
	int getAcceptablePhotons();
	float getMeanEnergy();
	int getTotal();
	float getSigmaA();

	void run(float* x, float* y, float* x2, float* y2, int N, float thicknes);
};
#endif //_XRAY_HPP_
