
#pragma once
#include"ISort.h"
#include"Windowsstopwatch.h"
class Radixsort :public ISort
{
public:
	WindowsStopwatch watch;

	//radix sort implementation which calls counting sort internally
	void sort(std::vector<int>& vector)
	{
		std::cout << "\nenter the radix sort for elements" << vector.size() << "\n";
		watch.start();
		long n = vector.size();
		long largest = vector[0];
		

		

		for (long i = 0; i < n; i++)
		{


			if (vector[i] > largest)
			{
				largest = vector[i];
			}

		}

		
		
		for (long exp = 1; largest / exp > 0; exp *= 10)
			countSort(vector, n, exp);

		watch.stop();
		std::cout << "time taken to sort the above elements" << watch.getTime();
		std::cout << "\n";

	}

	//counting sort implementation
	void countSort(std::vector<int>& vector, long n, long exp)
	{
		long *output = new long[n];
		
	
		long i;

		long *count = new long[n];
		
		for (long i = 0; i < n; i++)
		{
			count[i] = 0;
		}
		
		
		for (i = 0; i < n; i++)
			count[(vector[i] / exp) % 10]++;

		
		for (i = 1; i < n; i++)
			count[i] += count[i - 1];


		
		for (i = n - 1; i >= 0; i--)
		{
			output[count[(vector[i] / exp) % 10] - 1] = vector[i];
			count[(vector[i] / exp) % 10]--;
		}

		
		for (i = 0; i < n; i++)
			vector[i] = output[i];
		
	}

};
