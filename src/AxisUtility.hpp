#ifndef _AXIS_UTILITY_HPP_
#define _AXIS_UTILITY_HPP_

#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <math.h>
#include <stdlib.h>

class AxisUtility {
	
private:
	float extractElementsFromFile(int i, int j, char* fileName);
	char *m_filename;

public:
	AxisUtility() {
		m_filename = new char[25];
	}
	virtual ~AxisUtility(){
		delete m_filename;
	}
	/**
	 * array for tablated x-ray energy
	 */
	float* xAxisArray();

	/**
	 * array fo tablated x-ray energy from attenuation table
	 */
	float* xAxisArray2();

	/**
	 * array of tableted corresponding emission frequency
	 */
	float* yAxisArray();

	/**
	* array of tablated corresponding attenuation length
	*/
	float* yAxisArray2();

};
#endif //_AXIS_UTILITY_HPP_
