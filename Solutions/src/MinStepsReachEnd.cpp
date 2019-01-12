/*
 * MinStepsReachEnd.cpp
 *
 *  Created on: Jan 8, 2019
 *      Author: Avinash
 */

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int jump(vector<int> A) {
	int n = A.size();
	 if(n<2)return 0;
	 int level=0,currentMax=0,i=0,nextMax=0;

	 while(currentMax-i+1>0){		//nodes count of current level>0
		 level++;
		 for(;i<=currentMax;i++){	//traverse current level , and update the max reach of next level
			nextMax=max(nextMax,A[i]+i);
			if(nextMax>=n-1)return level;   // if last element is in level+1,  then the min jump=level
		 }
		 currentMax=nextMax;
	 }
	 return 0;
 }
int minReachEnd(vector<int> &vec)
{
	int sz = vec.size();
    int i = 0;
    int nextMax = 0;
    int steps = 0;
    int curMax = 0;
    while(i<=curMax) {
        steps++;

		for(;i<=curMax;i++) {
		    nextMax = max(nextMax, vec[i]+i);
		    if(nextMax >= sz-1) return steps;
		}

		curMax = nextMax;
	}

	return  0;
}

int minReachEnd2(vector<int> &vec)
{
	int sz = vec.size();
	vector<unsigned int> minSteps(sz, INT_MAX);

	minSteps[sz-1] = 0;

	for(int i=sz-2; i>=0;i--) {

		int steps = vec[i];
		for(int curStep=1;curStep<=steps; curStep++){
			if(curStep+i >=sz-1) minSteps[i]=1;
			else
			minSteps[i] = min(minSteps[i], minSteps[curStep+i]+1);
		}
	}

	return minSteps[0];
}

#if 1
int main()
{
	vector<int> vec = {3,3,1,0,2,0,1};


	int minSteps = minReachEnd(vec);

	if (minSteps == INT_MAX)
		cout << "cannot reach end" << endl;
	else
		cout << "Min steps to reach end: " << minSteps << endl;

	minSteps = minReachEnd2(vec);

	cout << "2nd " << minSteps <<endl;
	return 1;
}
#endif


