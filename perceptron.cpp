#include "perceptron.h"
	
perceptron::perceptron(){
	this->instCount = 0;
	this->correctPredict = 0;
	this->ghr = 0;
}
	
perceptron::~perceptron(){
	//delete[] this->table;
	//probably  need to change how i Delete the table because its now 2-d
	// currently causes seg
}


void perceptron::predict(const vector<long> &address, const vector<string> &branchAction, int tableSize, int weightsPerPercept, int historyBits, int bitsPerDimension){
	// note weightsPerPercept = historyBits....I will keep them separate for clarity
	// which should be between 12-62 inclusive
	
	int dimensionMod = pow(2, (bitsPerDimension-1));	
	//cout << dimensionMod << endl;
		
	this->ghrVector = new int[historyBits]; // im going to have to figure out a way to update ghrVector from ghr
	for(int k = 0; k < historyBits; k++){ //initialize to 1, the values should only ever be 1 or -1;
		ghrVector[k] = 1;
	}	
	
	this->table = new int*[tableSize];
	
	// create the table structure
	for(int i = 0; i < tableSize; i++){
		table[i] = new int[weightsPerPercept];
	}
	
	// populate entier structure with initial value
	for(int j = 0; j < tableSize; j++){
		for(int k = 0; k < weightsPerPercept; k++){
			table[j][k] = 0;
		}
	}
	
	this->threshold = (1.9 * historyBits) + 14;
	
	// the logic
	this->instCount = address.size();
	unsigned int newGhr = 0;	
	unsigned int indexIntoTable;
	int mod = pow(2, historyBits);	
	long y;
	int t;	
	for(unsigned int i = 0; i < this->instCount; i++){
		indexIntoTable = (address[i]) % tableSize; // for now mod into table until i figure out hash
		y = this->computeY(table[indexIntoTable], this->ghrVector, weightsPerPercept);
		//cout << "y: " << y << endl;		
		if(y<0 && branchAction[i] == "NT"){
			correctPredict++;
			//t = -1;
		}
		if(y>=0 && branchAction[i] == "T"){
			correctPredict++;
			//t = 1;
		}
		
		if(branchAction[i] == "T"){
			t = 1;
		}	
		if(branchAction[i] == "NT"){
			t = -1;
		}	
		
		if(((t<0 && y>=0) || (t>=0 && y<0)) || (abs(y) < this->threshold)){
			for(int z = 0; z < weightsPerPercept; z++){
				if(((t*ghrVector[z]) < 0 && (table[indexIntoTable][z] > -dimensionMod)) || (((t*ghrVector[z]) > 0) && (table[indexIntoTable][z] < dimensionMod))){	
					
					table[indexIntoTable][z] += (t*ghrVector[z]);
					//cout << table[indexIntoTable][z] << endl;
				}
			}
			//cout << "X" << endl;
			//cout << "thresh: " << this->threshold << endl;
			//cout << "Y: " << y << endl;
		}
		
		newGhr = ghr << 1;
		newGhr = newGhr % mod;
		if(branchAction[i] == "T"){
			newGhr++;
		}
		
		this->ghr = newGhr;
		//cout << this->ghr << endl;
		this->updateGhrVect(this->ghr, historyBits);
	}
	for(int g = 0; g < tableSize; g++){
		for(int h = 0; h < weightsPerPercept; h++){
			if(table[g][h] > dimensionMod || table[g][h] < -dimensionMod){			
				cout << table[g][h] << endl;
			}
		}
	}	
		
	// for line
	// hash line to index into perceptron table
	// computeY which is the dot product of perceptron and and ghr vector       // I have to create a ghr array ....possibly by populating it with right shifts of ghr
	// if y is negative predict nt
	// if y is positice predict t
	// t = -1 if actual NT
	// t = 1 if actual T
	// theta = threshold
	// if condition is met...train perceptron
		
}
	
int perceptron::computeY(int* weightVector, int* globalHistoryVector, int weightsPerPercept){
	// w0 is the bias weight of 1	
	int w0 = 1;	
	int retVal = 0;
	retVal+=w0;
	int product;
	for(int i = 0; i < weightsPerPercept; i++){
		//cout <<	"P" << weightVector[i] << endl;
		//cout <<	"xi" << globalHistoryVector[i] << endl;
		product = weightVector[i] * globalHistoryVector[i];
		retVal += product;
	}
	return retVal;
	
}
/*	
int hashFunction(long address){
	int h1 = 

}


*/

void perceptron::updateGhrVect(int ghr, int historyBits){
	int bitInQuestion;	
	int tempGhr = ghr;	
	for(int x = (historyBits-1); x >= 0; x--){
		bitInQuestion =	tempGhr & 1;
		if(bitInQuestion){
			this->ghrVector[x] = 1;
		}
		else{
			this->ghrVector[x] = -1;
		}
		tempGhr = tempGhr >> 1;
	}
}








