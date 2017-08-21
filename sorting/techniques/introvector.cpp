
#include<iostream>
#include<vector>
#include <fstream>
#include<string>
#include<sstream>
#include"TestIntro.h"


void introsplit(const std::string &s, std::string sep, std::vector<std::string> &read)
{

	char* cstr = const_cast<char*>(s.c_str());
	char* current;

	current = strtok(cstr, sep.c_str());
	while (current != NULL) {
		read.push_back(current);
		current = strtok(NULL, sep.c_str());
	}


}


void  intovectortest()
{
	std::cout << "hello starting of introtestprogram for testing random text file\n";
	std::ifstream infile("../../sorting/random.txt");
	std::string str;
	std::vector<std::string> read;
	std::vector<int> elems;
	while (std::getline(infile, str))
	{
		introsplit(str, "-", read);
	}

	for (long i = 0; i < read.size(); i++)
	{
		int num = atoi(read.at(i).c_str());
		elems.push_back(num);
	}

	IntrosSort sort;


	for (long i = 1000; i < elems.size(); i *= 2)
	{
		std::vector<int> dummy;

		for (long j = 0; j < i; j++)
		{

			dummy.push_back(elems[j]);
		}

		sort.sort(dummy);

	}

	sort.sort(elems);

	std::cout << "the element first after sorting" << elems[0];

	std::cout << "hello starting of introtestprogram for testing ascending text file\n";
	std::ifstream ascendingfile("../../sorting/ascending.txt");
	std::string astr;
	std::vector<std::string> aread;
	std::vector<int> aelems;
	while (std::getline(ascendingfile, astr))
	{
		introsplit(astr, "-", aread);
	}

	for (long i = 0; i < aread.size(); i++)
	{
		int num = atoi(aread.at(i).c_str());
		aelems.push_back(num);
	}



	for (long i = 1000; i < aelems.size(); i *= 2)
	{
		std::vector<int> dummy;

		for (long j = 0; j < i; j++)
		{

			dummy.push_back(aelems[j]);
		}

		sort.sort(dummy);

	}

	sort.sort(aelems);



	std::cout << "hello starting of introtestprogram for testing descending text file\n";
	std::ifstream decendingfile("../../sorting/decsending.txt");
	std::string dstr;
	std::vector<std::string> dread;
	std::vector<int> delems;
	while (std::getline(decendingfile, dstr))
	{
		introsplit(dstr, "-", dread);
	}

	for (long i = 0; i < dread.size(); i++)
	{
		int num = atoi(dread.at(i).c_str());
		delems.push_back(num);
	}



	for (long i = 1000; i < delems.size(); i *= 2)
	{
		std::vector<int> dummy;

		for (long j = 0; j < i; j++)
		{

			dummy.push_back(delems[j]);
		}

		sort.sort(dummy);

	}

	sort.sort(delems);


}
