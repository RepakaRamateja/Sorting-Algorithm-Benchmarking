/////////////////////////////////////////////////////////////////////
//  MergeSort.h - implements merge sort technique                  //
//  ver 1.1                                                        //
//  Lanaguage:     Visual C++ 2005                                 //
//  Platform:      Macbook pro                                     //
//                                                                 //
//  Author:        Ramteja                                         //
//  Source:  Adam Drozdek, "Data Structures and Algorithms in C++ ////
/////////////////////////////////////////////////////////////////////

#pragma once
#include"ISort.h"
#include<iostream>
#include"Windowsstopwatch.h"
using namespace std;
class Mergesort :public ISort
{
public:

	//merge sort implementation
	void sort(std::vector<int>& vector)
	{
		WindowsStopwatch watch;
		std::cout << "\nenter the merge sort for elements" << vector.size() << "\n";
		watch.start();
		vector=merge_Sort(vector);
		watch.stop();
		std::cout << "time taken to sort the above elements" << watch.getTime();
		std::cout << "\n";
		
	}

	//merge function which takes left sub vector and right sub vector and merges into single vector
	vector<int> Merge(vector<int> left, vector<int> right)
	{
		vector<int> result;
		while ((int)left.size() > 0 || (int)right.size() > 0) {
			if ((int)left.size() > 0 && (int)right.size() > 0) {
				if ((int)left.front() <= (int)right.front()) {
					result.push_back((int)left.front());
					left.erase(left.begin());
				}
				else {
					result.push_back((int)right.front());
					right.erase(right.begin());
				}
			}
			else if ((int)left.size() > 0) {
				for (int i = 0; i < (int)left.size(); i++)
					result.push_back(left[i]);
				break;
			}
			else if ((int)right.size() > 0) {
				for (int i = 0; i < (int)right.size(); i++)
					result.push_back(right[i]);
				break;
			}
		}
		return result;
	}

	//recursive sort function which takes one vector and returns another vector which is sorted

	vector<int> merge_Sort(vector<int> m)
	{
		if (m.size() <= 1)
			return m;

		vector<int> left, right, result;
		int middle = ((int)m.size() + 1) / 2;

		for (int i = 0; i < middle; i++) {
			left.push_back(m[i]);
		}

		for (int i = middle; i < (int)m.size(); i++) {
			right.push_back(m[i]);
		}

		left = merge_Sort(left);
		right = merge_Sort(right);
		result = Merge(left, right);

		return result;
	}

};