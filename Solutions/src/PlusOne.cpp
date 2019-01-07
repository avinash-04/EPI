/*
 * PlusOne.cpp
 *
 *  Created on: Jan 6, 2019
 *      Author: Avinash
 */

#include <iostream>
#include <vector>
using namespace std;

//
// PlusOne : Add one to number encoded in vector
// vector<int> A = { 1, 2, 9}
// return { 1, 3, 0}
//
vector<int> plusOne(vector<int> A)
{
	int sz = A.size();
	int carry = 1;
	int curIndex = sz-1;

	while((carry == 1) && curIndex >=0) {
		A[curIndex]++;
		if(A[curIndex] > 9) {
			A[curIndex] = 0;
			carry = 1;
			curIndex--;
		} else {
			carry = 0;
		}
	}

	if(curIndex < 0 && carry) A.insert(A.begin(), 1);
	return A;
}

#if 0
int main() {

	vector<int> A = { 1, 2, 9};

	auto ret = plusOne(A);

	for(auto elem: ret)
		cout << elem << " " ;

	cout << endl;

	vector<int> B = { 9, 9, 9};
	auto ret2 = plusOne(B);

	for(auto elem: ret2)
		cout << elem << " " ;
	return 0;
}
#endif


