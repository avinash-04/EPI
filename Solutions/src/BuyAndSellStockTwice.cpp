/*
 * BuyAndSellStockTwice.cpp
 *
 *  Created on: Jan 13, 2019
 *      Author: Avinash
 */
#include<iostream>
#include<vector>
#include<limits>

using namespace std;

/*
 * Return the Max profit that can be made with two transaction.
 */
int BuyAndSellStockTwice(vector<int> &prices)
{
	int K =2;
	int maxProfit = 0;
	int tempMax = 0;
	vector<vector<int>> Profit(K+1, vector<int>(prices.size()+1, 0));

	for(int k=1; k<=K; k++) {
		int tempMax = Profit[k-1][0] - prices[0];
		for(int i=1; i<prices.size();i++)
		{
			int maxi = prices[i]+tempMax;
            Profit[k][i] = max(Profit[k][i-1], maxi);
            tempMax = max(tempMax, Profit[k-1][i]-prices[i]);
            maxProfit = max(maxProfit, Profit[k][i]);
		}
	}

	return maxProfit;
}


int BuyAndSellStockTwice2(vector<int> &prices)
{
    vector<int> res(4, 0);
    res[0] = numeric_limits<int>::min();
    res[2] = numeric_limits<int>::min();
    for(int i = 0; i < prices.size(); ++i) {
        res[3] = max(res[3], res[2] + prices[i]);  // Transaction 2: sell
        res[2] = max(res[2], res[1] - prices[i]);  // Transaction 2: buy
        res[1] = max(res[1], res[0] + prices[i]);  // Transaction 1: sell
        res[0] = max(res[0], -prices[i]);          // Transaction 1: buy
    }
    return max(res[1], res[3]);
}

#if 0
int main()
{
	vector<int> prices = {310, 315, 275, 295, 260, 270, 290, 230, 255, 250};

	cout << "MaxProfit:" << BuyAndSellStockTwice(prices) << endl;

	cout << "MaxProfit2:" << BuyAndSellStockTwice2(prices) << endl;
	return 0;
}
#endif



