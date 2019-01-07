/*
 * Multiply.cpp
 *
 *  Created on: Jan 6, 2019
 *      Author: Avinash
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

//
// Multiply : multiply two ints  encoded in vector
//
vector<int> Multiply(vector<int> num1, vector<int> num2)
{
	vector<int> res(num1.size()+num2.size(), 0);

	int sign = num1.front()<0 ^ num2.front()<0 ? -1 : 1;
	num1.front() = abs(num1.front());
	num2.front() = abs(num2.front());
	for(int i=num1.size()-1; i>=0; i--){
		for(int j =num2.size()-1; j>=0 ; j--) {
			res[i+j+1] += num1[i]*num2[j];
			res[i+j] += res[i+j+1]/10;
			res[i+j+1] %=10;
		}
	}

	res = vector<int>{find_if_not(begin(res), end(res), [](int a) { return !a;}), end(res)};
	res.front() *= sign;
	return res;
}

#if 1
int main() {

	vector<int> A = { 1, 2, 9};

	vector<int> B = {-1};
	auto ret = Multiply(A, B);

	for(auto elem: ret)
		cout << elem << " " ;
	return 0;
}
#endif





