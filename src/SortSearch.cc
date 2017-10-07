#include "SortSearch.hpp"

int SortSearch::binarySearch(float input, float* x, float* y) {
	float input1 = input;
	float temp1 = 0;
	int temp2 = 50;
	float temp3 = 100;  
	for (int i = 0; i < 8; ++i) {
		if (input1 >= x[temp2]) {
			temp1 = (temp3 + temp1) / 2;
		} else {
			temp3 = (temp3 + temp1) / 2;
		}
		temp2 = (temp3 + temp1) / 2;

	}
	return temp2;
}

float* SortSearch::quickSort(float* input, int left, int right) {
    int pivot;
    if(left < right) {
        pivot = partition(input, left, right);
        quickSort(input, left, pivot);  
        quickSort(input, pivot+1, right);
    }
    return input;
}

int SortSearch::partition(float* input, int left, int limit) {
    int start = input[left];
    int i = left;
    for(int j = left + 1; j < limit; ++j) {
        if(input[j] <= start) {
            ++i;
            std::swap(input[i], input[j]);
        }
    }
    std::swap(input[i], input[left]);
    return i;
}
