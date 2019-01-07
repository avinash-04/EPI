/*
 * DutchNationalFlagVariant2.cpp
 *
 *  Created on: Jan 6, 2019
 *      Author: Avinash
 */
#include <iostream>
#include <vector>
using namespace std;

//
// ReArrnage the array : Given four keys arrange the values are below
// k1k1k1k1k1k2k2k2k2k2k2k2k3k3k3k3k3k3k4k4k4k4k4k4k4
//
void reArrange(vector<int>& Arr,int K1, int K2, int K3, int K4)
{
	int sz = Arr.size();
	int k1 = 0;
	int k2 = 0;
	int k3 = 0;
	int k4 = sz-1;

	while(k3 <= k4)
	{
		if(Arr[k3] == K1) {
			swap(Arr[k3], Arr[k1++]);
			k2=k1;
			k3=k1;
		} else if (Arr[k3] == K2) {
			swap(Arr[k3], Arr[k2++]);
			k3=k2;
		} else if (Arr[k3] == K3){
			k3++;
		} else {
			swap(Arr[k3],Arr[k4--]);
		}
	}

}

#if 0
int main() {

	vector<int> Arr = { 0,1,2,3,0,1,3,1,2,2,2,2,0,0,3,0,1,2,1,2,3,3,3,0,1};
	reArrange(Arr,0,1,2,3);

	for(auto elem: Arr)
		cout << elem << " " ;
	return 0;
}
#endif






