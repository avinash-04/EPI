/*
 * DutchNationalFlagVariant1.cpp
 *
 *  Created on: Jan 6, 2019
 *      Author: Avinash
 */
#include <iostream>
#include <vector>
using namespace std;

//
// ReArrnage the array : Given three keys arrange the values are below
// k1k1k1k1k1k2k2k2k2k2k2k2k3k3k3k3k3k3
//
void reArrange(vector<int>& Arr,int K1, int K2, int K3)
{
	int sz = Arr.size();
	int k1 = 0;
	int k2 = 0;
	int k3 = sz-1;

	while(k2 <= k3)
	{
		if(Arr[k2] == K1) {
			swap(Arr[k2++], Arr[k1++]);
		} else if (Arr[k2] == K2) {
			k2++;
		} else {
			swap(Arr[k2],Arr[k3--]);
		}
	}

}

#if 0
int main() {

	vector<int> Arr = { 0,1,2,0,1,1,2,2,2,2,0,0,0,1,2,1,2,0,1};
	reArrange(Arr,0,2,1);

	for(auto elem: Arr)
		cout << elem << " " ;
	return 0;
}
#endif



