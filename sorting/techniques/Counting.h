/////////////////////////////////////////////////////////////////////
//  Counting.h - implements counting sort technique                  //
//  ver 1.1                                                        //
//  Lanaguage:     Visual C++ 2005                                 //
//  Platform:      Macbook pro                                     //
//                                                                 //
//  Author:        Ramteja                                         //
//  Source:  Adam Drozdek, "Data Structures and Algorithms in C++ ////
/////////////////////////////////////////////////////////////////////

#pragma once
#include"ISort.h"
#include <algorithm>
#include<vector>
#include"Windowsstopwatch.h"
class Countingsort :public ISort
{
public:

	void sort(std::vector<int>& vector)
	{
		WindowsStopwatch watch;

		std::cout << "\nenter the counting sort for elements" << vector.size() << "\n";

		watch.start();
		long n = vector.size();
		long i;
		long largest = vector[0];
		long *tmp = new long[n];

		for ( i = 0; i < n; i++)
		{

			if (largest < vector[i])
			{
				largest = vector[i];
			}

		}

		unsigned long *count = new unsigned long[largest + 1];

		for (i = 0; i <= largest; i++)
		{
			count[i] = 0;
		}

		for (i = 0; i < n; i++)
		{
			count[vector[i]]++;
		}
		
		for (i = 1; i <= largest; i++)
		{
			count[i] = count[i - 1] + count[i];
		}

		for (i = n - 1; i >= 0; i--)
		{

			tmp[count[vector[i]] - 1] = vector[i];
			count[vector[i]]--;
		}
  
		for (i = 0; i < n; i++)
		{
			vector[i] = tmp[i];
		}

		watch.stop();

		std::cout << "time taken to sort the above elements" << watch.getTime();
		std::cout << "\n";
	}

};