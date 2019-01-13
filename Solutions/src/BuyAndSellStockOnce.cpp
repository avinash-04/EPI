/*
 * BuyAndSellStockOnce.cpp
 *
 *  Created on: Jan 13, 2019
 *      Author: Avinash
 */

#include<iostream>
#include<vector>
#include<limits>

using namespace std;

/*
 * Return the Max profit that can be made with one transaction.
 */
int BuyAndSellStockOnce(vector<int> &prices)
{

	int maxProfit = 0;
	int profit = 0;
	for(int i=1; i<prices.size(); i++) {

		if(prices[i] >= prices[i-1]) {
			profit += prices[i]-prices[i-1];
		} else {
			profit = 0;
		}

		maxProfit = max(maxProfit, profit);
	}

	return maxProfit;
}


int BuyAndSellStockOnce2(vector<int> &prices)
{

	int maxProfit = 0;
	int minPriceSoFar = numeric_limits<int>::max();

	for(auto p :prices) {
        maxProfit = max(maxProfit, p-minPriceSoFar);
        minPriceSoFar = min (minPriceSoFar, p);
	}

	return maxProfit;
}

#if 0
int main()
{
	vector<int> prices = {310, 315, 275, 295, 260, 270, 290, 230, 255, 250};

	cout << "MaxProfit:" << BuyAndSellStockOnce(prices) << endl;
	return 0;
}
#endif

