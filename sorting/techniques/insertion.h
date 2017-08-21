/////////////////////////////////////////////////////////////////////
//  insertionSort.h - implements insertion sort technique           //
//  ver 1.1                                                        //
//  Lanaguage:     Visual C++ 2005                                 //
//  Platform:      Macbook pro                                     //
//                                                                 //
//  Author:        Ramteja                                         //
//  Source:  Adam Drozdek, "Data Structures and Algorithms in C++ //
/////////////////////////////////////////////////////////////////////

#pragma once
#include"ISort.h"
#include"Windowsstopwatch.h"
class insertionsort :public ISort
{
public:

	//code for the insertion sort

	void sort(std::vector<int>& vector)
	{
		int temp;
		int x, y;
		
		WindowsStopwatch watch;

		std::cout << "\nenter the insertion sort for elements" << vector.size() << "\n";

		watch.start();

	for (int i = 1; i < vector.size(); i++)
	{
		for (int j = i; j >= 1; j--)
		{
			
			x = vector[j];
			y = vector[j - 1];
			if (x < y)
			{
				temp = x;
				vector[j] = y;
				vector[j - 1] = temp;
			}
			else
				break;
		}
	}

	watch.stop();
	std::cout << "time taken to sort the above elements" << watch.getTime();
	std::cout << "\n";

	}

};
