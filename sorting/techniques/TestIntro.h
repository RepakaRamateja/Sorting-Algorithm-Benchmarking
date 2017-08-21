/////////////////////////////////////////////////////////////////////
//  IntroSort.h - implements intro sort technique using vectors    //
//  ver 1.1                                                        //
//  Lanaguage:     Visual C++ 2005                                 //
//  Platform:      Macbook pro                                     //
//                                                                 //
//  Author:        Ramteja                                         //
//                                                                 //
/////////////////////////////////////////////////////////////////////

#pragma once
#include"ISort.h"
#include<vector>
#include"Windowsstopwatch.h"
using namespace std;
class IntrosSort :public ISort
{

public:
	
	//intro sort functionality
	void sort(std::vector<int>& vector)
	{
		std::cout << "\nenter the Intro sort for elements" << vector.size() << "\n";
		WindowsStopwatch watch;
		int end = vector.size();
		watch.start();
		_introsort(vector, end);
		watch.stop();
		std::cout << "time taken to sort the above elements" << watch.getTime();
		std::cout << "\n";
		
	}

	void introsort_r(std::vector<int>& vector, int first, int last, int depth) {
		while (last - first > 0) {
			if (depth = 0)
				_heapsort(vector, first, last - first + 1);
			else {
				int pivot;
				if (_isSorted(vector, last))
					break;
				pivot = _partition(vector, first, last);
				introsort_r(vector, pivot + 1, last, depth - 1);
				last = pivot - 1;
			}
		}
	}

	void _introsort(std::vector<int>& vector, int n) {
		introsort_r(vector, 0, n - 1, (int(2 * log(double(n)))));
		_insertion(vector, n);
	}

	int _partition(std::vector<int>& vector, int first, int last) {
		int pivot, mid = (first + last) / 2;

		pivot = vector[first] > vector[mid] ? first : mid;

		if (vector[pivot] > vector[last])
			pivot = last;

		_swap(&vector[pivot], &vector[first]);
		pivot = first;

		while (first < last) {
			if (vector[first] <= vector[last])
				_swap(&vector[pivot++], &vector[first]);
			++first;
		}

		_swap(&vector[pivot], &vector[last]);
		return pivot;
	}

	void _insertion(std::vector<int>& vector, int n) {
		int i;
		for (i = 1; i < n; i++) {
			int j, save = vector[i];
			for (j = i; j >= 1 && vector[j - 1] > save; j--)
				vector[j] = vector[j - 1];
			vector[j] = save;
		}
	}

	void _swap(int *a, int *b) {
		int save = *a;
		*a = *b;
		*b = save;
	}
	void _doheap(std::vector<int>& vector, int begin, int end) {
		int save = vector[begin];
		while (begin <= end / 2) {
			int k = 2 * begin;
			while (k < end && vector[k] <vector[k + 1])
				++k;
			if (save >= vector[k])
				break;
			vector[begin] = vector[k];
			begin = k;
		}
		vector[begin] = save;
	}

	void _heapsort(std::vector<int>& vector, int begin, int end) {
		int i;
		for (int i = (end - 1) / 2; i >= begin; i--) {
			_doheap(vector, i, end - 1);
		}
		for (i = end - 1; i>begin; i--) {
			_swap(&vector[i], &vector[begin]);
			_doheap(vector, begin, i - 1);
		}
	}
	bool _isSorted(std::vector<int>& vector, int end) {
		for (int i = 0; i<end; i++) {
			if (vector[i] > vector[i + 1]) {
				return false;
			}
			else {
				return true;
			}
		}
		return true;
	}


};