#pragma once
#include"ISort.h"
#include <algorithm>
#include<vector>
#include"Windowsstopwatch.h"
using namespace std;
class quicksort :public ISort
{
public:

	//quick sort implementation
	void sort(std::vector<int>& vector)
	{
		
		long n = vector.size();
		WindowsStopwatch watch;
		std::cout << "\nenter the quick sort for elements" << vector.size() << "\n";
		watch.start();
		quick_sort(vector, 0, n - 1);
		watch.stop();
		std::cout << "time taken to sort the above elements" << watch.getTime();
		std::cout << "\n";

	}

	//recursive call happens here
	void  quick_sort(std::vector<int>& vector, long left, long right) {
		if (left >= right) return;

		long middle = left + (right - left) / 2;
		swap(vector[middle], vector[left]);
		long midpoint = partition(vector, left + 1, right, vector[left]);
		swap(vector[left], vector[midpoint]);
		quick_sort(vector, left, midpoint);
		quick_sort(vector, midpoint + 1, right);
	}

	//applies divide and conqueor rule and divides into partition
	int partition(vector<int>& A, long left, long right, long who) {
		for (int i = left; i<right; ++i) {
			if (A[i] <= who) {
				swap(A[i], A[left]);
				left++;
			}
		}
		return left - 1;
	}

	
};