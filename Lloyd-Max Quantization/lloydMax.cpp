#include "lloydMax.h"

lloydMax::lloydMax(stringstream& stream)
	:N(0), inputSize(0)
{
	stream >> N; // first input value is N
	long double temp;
	vector<long double> tempVec;
	tempVec.push_back(0); // y[0] will be purposefully empty, operate from y[1]

	// Push y values and record amount, then resize the y vector to store these values
	while (stream >> temp) {
		tempVec.push_back(temp);
		inputSize++;
	}
	if (inputSize > 3) {
		cerr << "ERROR: Entered more than 3 y values.\n\n";
		return;
	}
	vector<long double> yWidth(inputSize+1); //y0...y3 (if inputSize == 3 for example)
	vector<long double> bWidth(4); //b0...b3 hardcoded according to assignment details
	y = vector<vector<long double>>(N+1, yWidth); //row represents iterated level
	b = vector<vector<long double>>(N+1, bWidth); 
	y[0] = tempVec; //copy input to 0th level of y
	
	for (int i = 0; i <= N; i++) { // set b0 & b3 values according to assignment 
		b[i][0] = -0.5;
		b[i][3] = 0.5;
	}
	iterate();
}

void lloydMax::print()
{
	cout.precision(7);
	if (y.empty()) {
		return;
	}
	for (int i = 1; i <= inputSize; i++) {
		std::cout << "y" << i << ": " << y[N][i] << " ";
	}
	std::cout << std::endl;
}

// implementation of pseudocode from textbook
void lloydMax::iterate()
{
	for (int i = 0; i < N; i++) {
		calcBoundary(i);
		calcReconstruct(i+1);
	}
}

// Get Yj row from a given Bj-1 row
void lloydMax::calcReconstruct(int j)
{
	for (int i = 1; i <= inputSize; i++) { // ignore y0
		long double numerator = (pow(b[j-1][i], 2) / 2) - (pow(b[j-1][i-1], 2) / 2);
		long double denominator = b[j-1][i] - b[j-1][i-1];
		if (denominator != 0) {
			y[j][i] = numerator / denominator;
		}
		else {
			y[j][i] = 0; //avoid NaN
		}
	}
	return;
}

// Get Bj row from a given Yj row
void lloydMax::calcBoundary(int j)
{
	for (int i = 1; i < inputSize; i++) { //ignore b0, b3
		b[j][i] = (y[j][i] + y[j][i+1]) / 2;
	}
	return;
}
