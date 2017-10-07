#ifndef _RANDOMGENERATOR_HPP_
#define _RANDOMGENERATOR_HPP_

#include <climits>

class RandomNumberGenerator {
private: 
	int a;
	int currentSeed;
	float rng();
public:
	RandomNumberGenerator(){
		a = 40692;
		currentSeed = 500; // a random starting seed
	}
	virtual ~RandomNumberGenerator(){}
	float random();
	void seed(int newSeed);
};

#endif //_RANDOMGENERATOR_HPP_
