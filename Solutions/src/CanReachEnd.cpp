/*
 * CanReachEnd.cpp
 *
 *  Created on: Jan 8, 2019
 *      Author: Avinash
 */
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

bool canReachEnd(vector<int> &vec)
{

	int sz = vec.size();
	int maxReach = 0;

	for(int i=0; i<=maxReach && maxReach <sz-1; i++) {

		maxReach = max(maxReach, vec[i]+i);
	}

	return maxReach >= sz-1;
}

#if 0
int main()
{
	vector<int> vec = {3,3,1,0,2,0,1};

	cout << canReachEnd(vec) << endl;

	return 1;
}
#endif
