#pragma once
#include"ISort.h"
#include"Windowsstopwatch.h"
class selectionsort :public ISort
{
public:

	//selection sort implementation
	void sort(std::vector<int>& vector)
	{
		long min, loc;
		long temp;
		
		WindowsStopwatch watch;

		std::cout << "\nenter the selection sort for elements" << vector.size() << "\n";

		watch.start();
		for (int i= 0; i<vector.size(); i++)
		{
			min = vector[i];
			loc = i;
			for (int j = i + 1; j<vector.size(); j++)
			{
				if (min>vector[j])
				{
					min = vector[j];
					loc = j;
				}
			}

			temp = vector[i];
			vector[i] = vector[loc];
			vector[loc] = temp;
		}

		watch.stop();
		std::cout << "time taken to sort the above elements" << watch.getTime();
		std::cout << "\n";


	}

};