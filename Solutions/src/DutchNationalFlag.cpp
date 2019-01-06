/*
 * DutchNationalFlag.cpp
 *
 *  Created on: Jan 6, 2019
 *      Author: Avinash
 */
#include <iostream>
#include <vector>
using namespace std;

//
// ReArrnage the array : Dutch National flag way
// LLLLLEEEEEGGGG -> L : less
//                   E : Equal
//                   G : Greater
//
void reArrange(vector<int>& Arr, int index)
{
	int sz = Arr.size();
	int nextL = 0;
	int nextE = 0;
	int nextG = sz-1;

	int pivot = Arr[index];
	while(nextE <= nextG)
	{
		if(Arr[nextE] < pivot) {
			swap(Arr[nextE++], Arr[nextL++]);
		} else if (Arr[nextE] == pivot) {
			nextE++;
		} else {
			swap(Arr[nextE],Arr[nextG--]);
		}
	}

}

#if 0
int main() {

	vector<int> Arr = { 11,1,3,6,3,4,5,6,3,8,9,4,3,0,4};
    int pivot  = 3;
	cout << "pivot elem " << Arr[pivot] << endl;
	reArrange(Arr,pivot);

	for(auto elem: Arr)
		cout << elem << " " ;
	return 0;
}
#endif



