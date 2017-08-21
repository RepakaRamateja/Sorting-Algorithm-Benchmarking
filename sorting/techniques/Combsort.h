/////////////////////////////////////////////////////////////////////
//  CombSort.h - implements comb sort technique                  //
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
class Combsort :public ISort
{
public:

	//main sort function for the comb sort
	void sort(std::vector<int>& vector)
	{
		WindowsStopwatch watch;

		std::cout << "\nenter the comb sort for elements" << vector.size() << "\n";

		watch.start();
		
		int gap = vector.size();
		int temp;

		
		bool swapped = true;

		
		while (gap != 1 || swapped == true)
		{
			
			gap = getNextGap(gap);

			
			swapped = false;

			
			for (int i = 0; i < vector.size() - gap; i++)
			{
				if (vector[i] > vector[i + gap])
				{
					temp = vector[i];
					vector[i] = vector[i + gap];
					vector[i + gap] = temp;
					swapped = true;
				}
			}
		}

		watch.stop();
		std::cout << "time taken to sort the above elements" << watch.getTime();
		std::cout << "\n";

	}


	//for the next gap to be calculated
	int getNextGap(int gap)
	{
		
		gap = (gap * 10) / 13;

		if (gap < 1)
			return 1;
		return gap;
	}



};
