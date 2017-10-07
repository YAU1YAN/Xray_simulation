#include "AxisUtility.hpp"

float* AxisUtility::xAxisArray() {
	float* array = new float[101];
	strcpy(m_filename, "distribution.txt");
	for (int i = 0; i < 101; ++i) {
		array[i] = extractElementsFromFile(i, 0, m_filename);
	}
	return array;
}

float* AxisUtility::xAxisArray2() {
	float* array = new float[101];
	strcpy(m_filename, "Alength.txt");
	for (int i = 0; i < 101; ++i) {
		array[i] = extractElementsFromFile(i, 0, m_filename);
	}
	return array;
}

float* AxisUtility::yAxisArray() {
	float* array = new float[101];
	strcpy(m_filename, "distribution.txt");
	for (int i = 0; i < 101; ++i) {
		array[i] = extractElementsFromFile(i, 1, m_filename);
	}
	return array;
}

float* AxisUtility::yAxisArray2() {
	float* array = new float[101];
	strcpy(m_filename, "Alength.txt");
	for (int i = 0; i < 101; ++i) {
		array[i] = extractElementsFromFile(i, 0, m_filename);
	}
	return array;	
}

float AxisUtility::extractElementsFromFile(int i, int j, char* fileName) {
	std::vector<std::vector<float> > table;
	// Load table from file
	std::ifstream file(fileName);
	while (file) {
		std::string line;
		std::getline(file, line);
		std::istringstream stringStream(line);
		std::vector<float> row;
		while (stringStream) {
			float data;
			stringStream >> data;
			row.push_back(data);
		}
		table.push_back(row);
	}
	return table[i][j];
}
