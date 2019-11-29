#include <string>
#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <vector>
#include <cmath>
#include <cstdlib> //for abs

using namespace std;

class perceptron{
	public:
		perceptron();
		~perceptron();
		void predict(const vector<long> &address, const vector<string> &branchAction, int tableSize, int weightsPerPercept, int historyBits, int bitsPerDimension);
		int computeY(int* weightVector, int* globalHistoryVector, int weightsPerPercept);	
		void updateGhrVect(int ghr, int historyBits);
		//int hashFunction(long address);
		
		unsigned long long int instCount;
		unsigned long long int correctPredict;
		
		int **table; //table of perceptrons
		unsigned int ghr;
		int *ghrVector;
		
		double threshold;
};
