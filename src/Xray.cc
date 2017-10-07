#include "Xray.hpp"

float Xray::simulatedPhoton(float* x, float* y, int N, int i, float* r) {
	float acceptedE = 0;
	accept = false;
	float randomEnergyInstance = r[i] * 30000; /*ran*emax*/
	float randomFrequenctInstance = r[i+N] * 2.818930E+13; /*ran*fMax*/
	std::cout << randomEnergyInstance <<"\n";
	int n = sortSearch.binarySearch(randomEnergyInstance, x, y);
	float matchedY = (((y[n+1] - y[n])/(x[n+1]-x[n]))*(randomEnergyInstance - x[n]))+ y[n];
	if (matchedY >= randomFrequenctInstance) {
		acceptedE = randomEnergyInstance;
		accept = true;
	}
	
	return acceptedE;
}



float Xray::simulatePenetration(float* x2, float* y2, float E, int N, float thickness,  int i, float* r) {
	float penetratedE = 0;
	penetrate = false;
	int n = sortSearch.binarySearch(E, x2, y2);
	float matchedAlength = (((y2[n+1] - y2[n])/(x2[n+1]-x2[n]))*(E - x2[n])) + y2[n];
	float P = 1 - (exp(-thickness / matchedAlength));
	float dice = r[i+(2*N)];
	if (dice > P) {
			penetratedE = E;
			penetrate = true;
	}
	return penetratedE;
}

void Xray::run(float* x, float* y, float* x2, float* y2, int N, float thickness){
	TFile file("simpleMC.root", "recreate");
	//float* r = generateRandom();
	float* r = generateRandomMLCG();
	////////////////////////////////////////////////////////////////
	TH1F h_Uniform("h_Uniform", "RandomNumberGenerator", 100,  0, 1);

	float a =0; 
	float b = 0;
	sumP =0; 
	sumPsqr = 0;
	sigma =0;
	meanEnergy =0; 
	acceptablePhotons =0;
	total = 0;
	accept = false; 
	penetrate = false; 
	sigmaA =0;
	for (int i=0; i < N; ++i){
		//std::cout << i <<"\n";
		a = simulatedPhoton(x, y, N, i, r) ;
		if (accept){
			++acceptablePhotons;
			b =simulatePenetration(x2, y2, a, N , thickness, i , r);
			if (penetrate){
				++total;
  	  			h_Uniform.Fill(b);
  	  			sumP = sumP + b;
  	  			sumPsqr = sumPsqr + (b*b);
			}
		}

	}
	
	meanEnergy = sumP / total;
	sigma = (sumPsqr /total) - (meanEnergy * meanEnergy);
	sigmaA = sqrt(sigma)/ sqrt(total);

	std::cout << "thickness:" << "\t" << thickness << "     meanEnergy:\t" << meanEnergy << "    sigmaE" << sigmaA << "\n";

	file.Write();
 	file.Close();
}



int Xray::getAcceptablePhotons() {
	return acceptablePhotons;
}
float Xray::getMeanEnergy() {
	return meanEnergy;
}
int Xray::getTotal() {
	return total;
}
float Xray::getSigmaA(){
	return sigmaA;
}

float* Xray::generateRandom() {
	int N = 40000000;
	float* r = new float[N];
	float n  =123;
	int a = 40692;
	float m = 2147483399;
	for (int i=0; i < N; ++i){
		n = fmod(a*n,m);
		r[i] = n/m;
		
	}
	return r;
}
float* Xray::generateRandomT() {
	int N = 40000000;
	float* r = new float[N];
	int seed = 12345;
    TRandom3 ran(seed);
	for (int i=0; i < N; ++i){
		r[i] = ran.Rndm();
		
	}
	return r;
}

float* Xray::generateRandomMLCG() {
	int N = 40000000;
	float* r = new float[N];
	RandomNumberGenerator test = RandomNumberGenerator();
	test.seed((int)500); // set the initial seed
	int seed = 123451;
    TRandom3 ran(seed);
	for (int i=0; i < N; ++i){
		r[i] = test.random();
	}
	return r;
}

void Xray::printArrays(float* array, int N) {
	for (int i = 0; i < N; ++i) {
		std::cout << array[i] << "\t";
	}
	std::cout << "\n";
}
