#pragma once
#include<vector>
#include<iostream>
struct ISort {
	ISort() {}
	virtual ~ISort() {}
	virtual void sort(std::vector<int>& vector) = 0;
};