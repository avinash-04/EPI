/*
 * RemoveDupsSortedArray.cpp
 *
 *  Created on: Jan 12, 2019
 *      Author: Avinash
 */


#include <iostream>
#include <vector>
#include <climits>
using namespace std;

/*
 * Removes Dups from Sorted array and returns count of unique items
 */
int RemoveDupsSortedArray(vector<int> &vec)
{
#ifdef ONE_WAY
	int n = 0;
	int sz = vec.size();
	int i = 0;

	while(i<sz)
	{
		while(i+1<sz && vec[i]==vec[i+1]) i++;
	    vec[n++] = vec[i];
	    i++;
	}
	return n;
#else
	int n = 0;
	int sz = vec.size();
	for(int i=0; i<sz; i++) {
		if(vec[n]!=vec[i]) {
			vec[++n] = vec[i];
		}
	}

	return n+1;
#endif
}

#if 1
int main()
{
	vector<int> vec = {2,2,2,3,5,5,5,6,7,7,7,7,1000,1001,1001,1001,1002};


	int n = RemoveDupsSortedArray(vec);

	for(int i=0; i<n; i++) {
		cout << vec[i] << " ";
	}
	return 1;
}
#endif




