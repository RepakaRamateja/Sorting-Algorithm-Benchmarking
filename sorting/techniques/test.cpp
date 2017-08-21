/*
#include<iostream>
#include<vector>
#include <fstream>
#include<string>
#include<sstream>
#include"insertion.h"
#include"Selection.h"
#include"BubbleSort.h"
#include"Combsort.h"
#include"ShellSort.h"
#include"Counting.h"
#include"RadixSort.h"
#include <string.h>
#include"Heapsort.h"
#include"quicksort.h"
#include"MergeSort.h"
#include"IntroSort.h"
#include"TestIntro.h"


void split(const std::string &s, std::string sep, std::vector<std::string> &read)
{
	
	char* cstr = const_cast<char*>(s.c_str());
	char* current;
	
	current = strtok(cstr, sep.c_str());
	while (current != NULL) {
		read.push_back(current);
		current = strtok(NULL, sep.c_str());
	}

	
	}


int main()
{
	std::cout << "hello starting of program";	
	std::ifstream infile("C:\\adsproject2\\sorting\\demos.txt");
	std::string str;
	std::vector<std::string> read;
	std::vector<int> elems;
	while (std::getline(infile, str))
	{
		split(str, "-", read);
	}

	for (int i = 0; i < read.size(); i++)
	{
		int num = atoi(read.at(i).c_str());
		elems.push_back(num);
	}
	

	for (int i=0;i<elems.size();i++)
	{
		std::cout << elems[i]<<"\n";
	}


	//selectionsort sorting;
	//sorting.sort(elems);
	//insertionsort insert;
	//insert.sort(elems);
	//bubblesort bubble;
	//bubble.sort(elems);
	//Combsort sort;
	//sort.sort(elems);
	//Shellsort sort;
	//sort.sort(elems);
	//Countingsort csort;
	//csort.sort(elems);
	//Radixsort sort;
	//sort.sort(elems);
	//quicksort sort;
	//sort.sort(elems);
	//Mergesort sort;
	//sort.sort(elems);
	//HeapSort sort;
	//sort.sort(elems);
	//IntroSort sort;
	//sort.sort(elems);
	IntrosSort sort;
	sort.sort(elems);
for (int i = 0; i<elems.size(); i++)
	{
		std::cout << elems[i] << "\n";
	}
	
	std::cin.get();
      
return 0;
}
*/