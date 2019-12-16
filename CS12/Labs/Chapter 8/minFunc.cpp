#include "minFunc.h"
const int * min(const int arr[], int arrSize) {
	if (arrSize == 0)
		return &arr[0];
	else {
		auto minVal = min(arr, arrSize - 1);
		if (*minVal < arr[arrSize - 1]) 
			return minVal;
		else 
			return &arr[arrSize - 1];
	}
}