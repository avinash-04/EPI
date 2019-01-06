//============================================================================
// Name        : EvenOdd.cpp
// Author      : 
// Version     :
// Copyright   :
// Description : Rearaange the elements in an array such that even elements
//               are at the begining
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

void reArrange(vector<int>& Arr)
{
	int nextEven = 0;
	int sz = Arr.size();

	for(int i=0; i<sz; i++) {

		if(!(Arr[i] & 1)) {
			//elem is even
			//put it into nextEven location

			swap(Arr[i],Arr[nextEven]);
			nextEven++;
		}
	}

}

int main() {

	vector<int> Arr = { 1,3,3,4,5,6,3,8,9};

	reArrange(Arr);

	for(auto elem: Arr)
		cout << elem << " " ;
	return 0;
}
