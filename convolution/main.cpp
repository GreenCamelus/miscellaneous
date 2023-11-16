#include<iostream>
#include<fstream>
#include "signal.h"
using namespace std;

signal convolution(signal, signal);
//array for problem 1
int x[5] = { 1,1,1,1,1 };
int h[3] = { 1,1,1 };
int y[7];

//array for problem 2
int x2[7] = { 1,1,1,1,1,1,1 };
int z2[9] = { 1,1,1,1,2,2,2,2,2 };

//arrray for problem 3
int y3[8] = { 1,1,1,1, -1, -1, -1, -1 };
int w3[9] = { -1, 0, 1, 2, 3, 2, 1, 0, -1 };
int result = 0;

void main() {
	//problem 1
	y[0] = x[0] * h[0];
	for (int n = 0; n < 7; n++) {
		for (int k = 0; k < 5; k++) {
			if (n - k < 0 || n - k>3) result += 0;
			else result += x[k] * h[n - k];
		}
		y[n] = result;
		cout << "y[" << n << "] = " << y[n] << endl;
		result = 0;
	}
	cout << "otherwise, y[n] = 0" << endl;

	signal xx, hh, yy;

	cout << endl << "Problem 2" << endl;
	xx.setSig(x2, sizeof(x2) / 4, -5);
	hh.setSig(z2, sizeof(z2) / 4, 0);

	yy = convolution(xx, hh);
	yy.show();

	cout << endl << "Problem 3" << endl;
	xx.setSig(y3, sizeof(y3) / 4, -3);
	hh.setSig(w3, sizeof(w3) / 4, -4);

	yy = convolution(xx, hh);
	yy.show();

	
}

//generalized convolution executing function
signal convolution(signal xx, signal hh) {
	signal y;
	int temp = 0;

	int effectiveOutputSize;
	effectiveOutputSize = xx.effectiveSize + hh.effectiveSize - 1;

	for (int n = 0; n < effectiveOutputSize; n++) {
		for (int k = 0; k < xx.effectiveSize; k++) {
			if (n - k<0 || n - k> hh.effectiveSize) temp += 0;
			else temp += xx.value[k] * hh.value[n - k];
		}
		y.value[n] = temp;
		temp = 0;
	}
	y.startP = xx.startP + hh.startP;
	y.effectiveSize = effectiveOutputSize;
	return y;
}
