#pragma once
#include<iostream>
using namespace std;

class signal {
public:
	//constructor(simple)
	signal() {
		startP = effectiveSize = 0;
		for (int n = 0; n < 25; n++) {
			value[n] = 0;
		}
	}

	//memberdata

	//signal starting point ex) for u(t-3), starting point is t = 3.
	int startP;

	//signal value
	//signal can be as long as 25

	int value[25];

	// effective size is defined by the signal length.
	// it is used to execute convolution efficiently.
	int effectiveSize;

	//memberfunction

	//inputting signal via array 
	void setSig(int x[], int size, int sp) {
		effectiveSize = size;
		startP = sp;
		for (int i = 0; i < effectiveSize; i++) {
			value[i] = x[i];
		}
	}
	
	void show() {
		for (int n = 0; n < effectiveSize; n++) {
			cout << "n = " << startP+n << ", " << value[n] << endl;
		}
	}
};
