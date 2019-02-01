/*
 * NextPermutation.cpp
 *
 *  Created on: Jan 31, 2019
 *      Author: Avinash
 */

#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;

//
// Return the next largest number formed by vector reading from right to left (lsb to msb)
//
void NextPermutation(vector<int>& vec) {

	int k = vec.size()-2;

	while (k>=0 && vec[k] >= vec[k+1]) k--;

	if (k<0) return;

	for(int i=vec.size()-1; i>=0 && i>k; i--) {
		if(vec[i] > vec[k]) {
			swap(vec[i], vec[k]);
			break;
		}
	}

	reverse(vec.begin()+k+1, vec.end());
}

#if 0
int main()
{

	vector<int> vec = { 6,2,1,5,4,3,0};
	NextPermutation(vec);

	for(auto a:vec)
	{
		cout << a << " ";
	}

	return 0;
}
#endif








