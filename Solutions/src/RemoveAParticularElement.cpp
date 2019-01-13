/*
 * RemoveAParticularElement.cpp
 *
 *  Created on: Jan 13, 2019
 *      Author: Avinash
 */
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

/*
 * Removes a particular key and left the other elements
 * return the final elements
 */
int RemoveAParticularElement(vector<int> &vec, int elem)
{
	int actual_index = 0;
	int sz = vec.size();

	for(int i=0; i<sz;i++) {
		if(vec[i] != elem){
			vec[actual_index++] = vec[i];
		}
	}

	return actual_index;

}

#if 1
int main()
{
	vector<int> vec = {1,1,2,3,4,2,5,2,2,2,7,8,9,10,2,2};


	int n = RemoveAParticularElement(vec,2);

	for(int i=0; i<n; i++) {
		cout << vec[i] << " ";
	}
	return 1;
}
#endif








