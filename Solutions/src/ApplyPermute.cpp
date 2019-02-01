/*
 * ApplyPermute.cpp
 *
 *  Created on: Jan 16, 2019
 *      Author: Avinash
 */

#include<iostream>
#include<vector>
#include <cmath>

using namespace std;

void ApplyPermute(vector<int>& vec, vector<int>& perm) {

	for(int i=0; i<vec.size(); i++) {

		int next = i;

		while(perm[next] >= 0) {

			swap(vec[i], vec[perm[next]]);
            int temp = perm[next];
			perm[next] -= vec.size();
			next = temp;
		}
	}
}

void cyclicPermute(int start,vector<int> &vec, vector<int> &perm)
{
	int i = start;
    int temp = vec[start];


	do{
		int next_i = perm[i];
		int next_temp = vec[next_i];

		vec[next_i] = temp;
		temp = next_temp;

		i = next_i;
       }while(i!=start);

}

void ApplyPermute2(vector<int> &vec, vector<int> &perm)
{
   for(int i=0; i< vec.size(); i++) {
	   bool isMin = true;
	   int j=perm[i];

	   while(j != i){
		   if(j < i) {
			   isMin = false;
			   break;
		   }

		   j = perm[j];
	   }


	   if(isMin) cyclicPermute(i, vec, perm);
   }

}

#if 0
int main()
{

	vector<int> vec = { 1,2,3,4};
	vector<int> perm = { 3,0,1,2};
	ApplyPermute2(vec, perm);

	for(auto a:vec)
	{
		cout << a << " ";
	}

	return 0;
}
#endif




