#pragma once
#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>
using namespace std;

class lloydMax
{
public:
	lloydMax(stringstream& stream);
	void print();

private:
	void iterate();
	void calcReconstruct(int j);
	void calcBoundary(int j);
	int N;	// number of iterations
	int inputSize;	// number of y values entered
	vector<vector<long double>> b; //2D vectors; row represents level,
	vector<vector<long double>> y; // col represents values
};

