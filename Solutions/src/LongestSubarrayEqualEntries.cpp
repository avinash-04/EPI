/*
 * LongestSubarrayEqualEntries.cpp
 *
 *  Created on: Jan 13, 2019
 *      Author: Avinash
 */
#include<iostream>
#include<vector>
#include<limits>
using namespace std;

/*
 * Return length of longest subarray whose entries are equal
 */
int LongestSubarrayEqualEntries(vector<int> &vec)
{
	int longestLength = 0;
	int curLength = 1;
	for(int i=0; i<vec.size(); i++) {
		if(vec[i] == vec[i-1])
			curLength++;
		else
			curLength=1;

		longestLength = max(longestLength, curLength);
	}

	return longestLength;

}

#if 0
int main()
{
	vector<int> vec = { 1,1,2,3,4,5,5, 4,4,6,6,6,6,7,6,6,6,6,6,8,8,8,8};
	cout << "LongestSubarrayEqualEntries: " << LongestSubarrayEqualEntries(vec) <<endl;
}
#endif
