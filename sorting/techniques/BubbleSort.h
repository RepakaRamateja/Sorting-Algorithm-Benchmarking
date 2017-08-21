/////////////////////////////////////////////////////////////////////
//  Bubblesort.h - implements bubble sort technique                //
//  ver 1.1                                                        //
//  Lanaguage:     Visual C++ 2005                                 //
//  Platform:      Macbook pro                                     //
//                                                                 //
//  Author:        Ramteja                                         //
//  Source:  Adam Drozdek, "Data Structures and Algorithms in C++ ////
/////////////////////////////////////////////////////////////////////

#pragma once
#include"ISort.h"
#include"Windowsstopwatch.h"

class bubblesort :public ISort
{
public:

	WindowsStopwatch watch;

	void sort(std::vector<int>& vector)
	{

		std::cout << "\nenter the bubble sort for elements" << vector.size()<<"\n";
		watch.start();

		for (int i = 0; i < vector.size(); ++i)
		{

			for (int j = 0; j < vector.size() - i - 1; ++j)
			{
				if (vector[j] > vector[j + 1])
				{
					int temp = vector[j];
					vector[j] = vector[j + 1];
					vector[j + 1] = temp;
				}

			}

		}

		watch.stop();
		std::cout << "time for the above elements is" << watch.getTime();

	}

};
