#pragma once
#include"ISort.h"
#include"Windowsstopwatch.h"
class Shellsort :public ISort
{
public:

	//shell sort implementation
	void sort(std::vector<int>& vector)
	{
		WindowsStopwatch watch;

		std::cout << "\nenter the shell sort for elements" << vector.size() << "\n";

		watch.start();
		long size = vector.size();
		int i, j, k, tmp;
		for (i = size / 2; i > 0; i = i / 2)
		{
			for (j = i; j < size; j++)
			{
				for (k = j - i; k >= 0; k = k - i)
				{
					if (vector[k + i] >= vector[k])
						break;
					else
					{
						tmp = vector[k];
						vector[k] = vector[k + i];
						vector[k + i] = tmp;
					}
				}
			}
		}
		watch.stop();
		std::cout << "time taken to sort the above elements" << watch.getTime();
		std::cout << "\n";
	}
};
