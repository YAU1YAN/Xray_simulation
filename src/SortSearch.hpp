#ifndef _SORTSEARCH_HPP_
#define _SORTSEARCH_HPP_
#include <algorithm>

class SortSearch {
private:
	/**
	 * Partition algorithm used by quick sort
	 */
	int partition(float* input, int left, int limit);

public:
	SortSearch(){}
	virtual ~SortSearch(){}

	/**
	 * Implementation of a binary search
	 */
	int binarySearch(float input, float* x, float* y);

	/**
	 * Implementation of a quicksort on an array of floats.
	 *
	 * @param input (float*) the array to be sorted.
	 * @param left (int) the starting point, this can be either the 
	 * 		start of the array (0) or the start point of a subset of the array.
	 * @param right (int) the length to be sorted, this can be either the 
	 * 		length of the array or the end point of a subset of the array.
	 */
	float* quickSort(float* input, int left, int right);
};
#endif //_SORTSEACH_HPP_
