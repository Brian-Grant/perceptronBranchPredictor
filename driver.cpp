#include "driver.h"

using namespace std;

int main(int argc, char **argv){
	
	


	string inputFileName;
	string outputFileName;
	
	unsigned long instCount = 0;

	long perceptRes12; //NEW
	long perceptRes22; //NEW
	


	//long perceptRes12_16; //NEW
	//long perceptRes22_16; //NEW
	

	
	if(argc != 3){
		cout << "Must be ran with two command line arguments" << endl;
		cout << "as: ./predictors <input_trace.txt> <output.txt>" << endl;
		return -1;
	}
	
	// grab file names 
	istringstream buf1(argv[1]);
	buf1 >> inputFileName;	
	istringstream buf2(argv[2]);
	buf2 >> outputFileName;
	
	//--------------------------------------------------------------------------
	// holds the addy from each line	
	vector<long> address;
	// holds the branch action from each line
	vector<string> branchAction;	

	string line;		
	long arg1;
	string arg2;	
	ifstream trace(inputFileName);
	if(trace.is_open()){
		cout << "File successfully opened" << endl; 
		while(getline(trace, line)){
			instCount++;
			stringstream lineStream(line);
			lineStream >> hex >> arg1;
			lineStream >> arg2;
			address.push_back(arg1);
			branchAction.push_back(arg2);
		}
		trace.close();
		cout << "File successfully read" << endl;
	}else{
		cout << "Unable to open input file" << endl;
		return -1;
	}

	// perceptron---------------------------------------------------------------
		
	perceptron *per12 = new perceptron();
	per12->predict(address, branchAction, 128, 15, 15, 6);
//	cout << "perceptron 128 15 6" << endl;
//	cout << per12->instCount << endl;
//	cout << per12->correctPredict << endl;
	perceptRes12 = per12->correctPredict;

	perceptron *per22 = new perceptron();
	per22->predict(address, branchAction, 256, 22, 22, 6);
//	cout << "perceptron 256 22 6" << endl;
//	cout << per22->instCount << endl;
//	cout << per22->correctPredict << endl;
	perceptRes22 = per22->correctPredict;



	//--------------------------------------------------------------------------	
	long perceptRes1;
	perceptron *per1 = new perceptron();
	per1->predict(address, branchAction, 128, 18, 18, 5);
//	cout << "perceptron 128 18 5" << endl;
//	cout << per1->instCount << endl;
//	cout << per1->correctPredict << endl;
	perceptRes1 = per1->correctPredict;

	long perceptRes2;
	perceptron *per2 = new perceptron();
	per2->predict(address, branchAction, 128, 23, 23, 4);
//	cout << "perceptron 128 12 4" << endl;
//	cout << per2->instCount << endl;
//	cout << per2->correctPredict << endl;
	perceptRes2 = per2->correctPredict;

	long perceptRes3;
	perceptron *per3 = new perceptron();
	per3->predict(address, branchAction, 256, 11, 11, 4);
//	cout << "perceptron 256 11 4" << endl;
//	cout << per3->instCount << endl;
//	cout << per3->correctPredict << endl;
	perceptRes3 = per3->correctPredict;
	
	long perceptRes4;
	perceptron *per4 = new perceptron();
	per4->predict(address, branchAction, 256, 9, 9, 5);
//	cout << "perceptron 256 9 5" << endl;
//	cout << per4->instCount << endl;
//	cout << per4->correctPredict << endl;
	perceptRes4 = per4->correctPredict;
	
	long perceptRes5;
	perceptron *per5 = new perceptron();
	per5->predict(address, branchAction, 256, 7, 7, 6);
//	cout << "perceptron 256 7 6" << endl;
//	cout << per5->instCount << endl;
//	cout << per5->correctPredict << endl;
	perceptRes5 = per5->correctPredict;
	
	long perceptRes6;
	perceptron *per6 = new perceptron();
	per6->predict(address, branchAction, 256, 8, 8, 6);
//	cout << "perceptron 256 8 6" << endl;
//	cout << per6->instCount << endl;
//	cout << per6->correctPredict << endl;
	perceptRes6 = per6->correctPredict;

	long perceptRes7;
	perceptron *per7 = new perceptron();
	per7->predict(address, branchAction, 256, 15, 15, 8);
//	cout << "perceptron 256 15 8" << endl;
//	cout << per7->instCount << endl;
//	cout << per7->correctPredict << endl;
	perceptRes7 = per7->correctPredict;

	long perceptRes8;
	perceptron *per8 = new perceptron();
	per8->predict(address, branchAction, 128, 13, 13, 7);
//	cout << "perceptron 256 15 8" << endl;
//	cout << per8->instCount << endl;
//	cout << per8->correctPredict << endl;
	perceptRes8 = per8->correctPredict;

	long perceptRes9;
	perceptron *per9 = new perceptron();
	per9->predict(address, branchAction, 128, 11, 11, 8);
//	cout << "perceptron 256 15 8" << endl;
//	cout << per9->instCount << endl;
//	cout << per9->correctPredict << endl;
	perceptRes9 = per9->correctPredict;

	long perceptRes10;
	perceptron *per10 = new perceptron();
	per10->predict(address, branchAction, 2048, 36, 36, 16);
//	cout << "perceptron 2048 36 16" << endl;
//	cout << per10->instCount << endl;
//	cout << per10->correctPredict << endl;
	perceptRes10 = per10->correctPredict;
	
	double perceptAcc12 = static_cast<double>(perceptRes12) / static_cast<double>(instCount);
	double perceptAcc22 = static_cast<double>(perceptRes22) / static_cast<double>(instCount);
	

	double perceptAcc1 = static_cast<double>(perceptRes1) / static_cast<double>(instCount);
	double perceptAcc2 = static_cast<double>(perceptRes2) / static_cast<double>(instCount);
	double perceptAcc3 = static_cast<double>(perceptRes3) / static_cast<double>(instCount);
	double perceptAcc4 = static_cast<double>(perceptRes4) / static_cast<double>(instCount);
	double perceptAcc5 = static_cast<double>(perceptRes5) / static_cast<double>(instCount);
	double perceptAcc6 = static_cast<double>(perceptRes6) / static_cast<double>(instCount);
	double perceptAcc7 = static_cast<double>(perceptRes7) / static_cast<double>(instCount);
	double perceptAcc8 = static_cast<double>(perceptRes8) / static_cast<double>(instCount);
	double perceptAcc9 = static_cast<double>(perceptRes9) / static_cast<double>(instCount);
	double perceptAcc10 = static_cast<double>(perceptRes10) / static_cast<double>(instCount);
	
	
	cout << "perceptron 256 15 8: " << perceptAcc7 << endl;
	cout << "perceptron 256 22 6: " << perceptAcc22 << endl;
	cout << "perceptron 128 15 6: " << perceptAcc12 << endl;
	
	//cout << "perceptron 256 36 6: " << perceptAccX << endl;
	//cout << "perceptron 256 36 8: " << perceptAcc1 << endl;
	cout << "perceptron 128 18 5: " << perceptAcc1 << endl;
	cout << "perceptron 128 23 4: " << perceptAcc2 << endl;
	cout << "perceptron 256 11 4: " << perceptAcc3 << endl;
	cout << "perceptron 256 9 5: " << perceptAcc4 << endl;
	cout << "perceptron 256 7 6: " << perceptAcc5 << endl;
	cout << "perceptron 256 8 6: " << perceptAcc6 << endl;
	cout << "perceptron 256 15 8: " << perceptAcc7 << endl;
	cout << "perceptron 128 13 7: " << perceptAcc8 << endl;
	cout << "perceptron 128 11 8: " << perceptAcc9 << endl;
	cout << "perceptron 2048 36 16: " << perceptAcc10 << endl;

	// data WRITE------------------------------------------------------------


	ofstream output(outputFileName);
	if(output.is_open()){
		cout << "Writing to outFile" << endl;
		output << "perceptron 256 15 8: " << perceptAcc7 << endl;
		output << "perceptron 256 22 6: " << perceptAcc22 << endl;
		output << "perceptron 128 15 6: " << perceptAcc12 << endl;
		
		//output << "perceptron 256 36 6: " << perceptAccX << endl;
		//output << "perceptron 256 36 8: " << perceptAcc1 << endl;
		output << "perceptron 128 18 5: " << perceptAcc1 << endl;
		output << "perceptron 128 23 4: " << perceptAcc2 << endl;
		output << "perceptron 256 11 4: " << perceptAcc3 << endl;
		output << "perceptron 256 9 5: " << perceptAcc4 << endl;
		output << "perceptron 256 7 6: " << perceptAcc5 << endl;
		output << "perceptron 256 8 6: " << perceptAcc6 << endl;
		output << "perceptron 256 15 8: " << perceptAcc7 << endl;
		output << "perceptron 128 13 7: " << perceptAcc8 << endl;
		output << "perceptron 128 11 8: " << perceptAcc9 << endl;
		output << "perceptron 2048 36 16: " << perceptAcc10 << endl;

		cout << "Finished writing to outFile" << endl;
		output.close();	
	}
	else{
		cout << "Problem writing to file" << endl;
	}		




	
	
	return 0;
}

