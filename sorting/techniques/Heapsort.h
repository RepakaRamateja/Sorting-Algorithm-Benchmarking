////////////////////////////////////////////////////////////////////////////
//  Counting.h - implements counting sort technique                          //
//  ver 1.1                                                                 //
//  Lanaguage:     Visual C++ 2005                                          //
//  Platform:      Macbook pro                                              //
//                                                                          //
//  Author:        Ramteja                                                  //
//  Source:  Adam Drozdek, "Data Structures and Algorithms in C++ and wiki ////
/////////////////////////////////////////////////////////////////////
#pragma once
#include"ISort.h"
#include <algorithm>
#include<vector>
#include"Windowsstopwatch.h"
class HeapSort :public ISort
{
public:
	//sorting function which takes the input vector and applies heapify concept and swap the element
	void sort(std::vector<int>& vector)
	{
		WindowsStopwatch watch;

		std::cout << "\nenter the heap sort for elements" << vector.size() << "\n";

		watch.start();
		heapformation(vector);
		for (std::vector<int>::size_type i = vector.size() - 1; i > 0; --i)
		{
			Swap(vector, i, 0);
			maxheapify(vector, i, 0);
		}
		watch.stop();
		std::cout << "time taken to sort the above elements" << watch.getTime();
		std::cout << "\n";

	}

	//formation of the heap
	void heapformation(std::vector<int>& vHeap)
	{
		for (int i = vHeap.size() - 1; i >= 0; --i)
		{
			maxheapify(vHeap, vHeap.size(), i);
		}
	}

	//which accepts element and based on left and right node it brings the root highest element 
	void maxheapify(std::vector<int>& vHeap, const std::vector<int>::size_type heapSize, const std::vector<int>::size_type siftNode)
	{
		std::vector<int>::size_type i, j;

		j = siftNode;
		do
		{
			i = j;
			if (((2 * i + 1) < heapSize) && vHeap[j] < vHeap[2 * i + 1])
				j = 2 * i + 1;
			if (((2 * i + 2) < heapSize) && vHeap[j] < vHeap[2 * i + 2])
				j = 2 * i + 2;

			Swap(vHeap, i, j);
		} while (i != j);
	}

	//function that is used for swapping  the numbers

	void Swap(std::vector<int>& vHeap, std::vector<int>::size_type i, std::vector<int>::size_type j)
	{
		if (i == j)
			return;

		int temp;
		temp = vHeap[i];
		vHeap[i] = vHeap[j];
		vHeap[j] = temp;
	}



};