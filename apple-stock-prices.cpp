#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int getMaxProfit(vector <int> stockPrices)
{
   // make sure we have at least 2 prices
    if (stockPricesYesterday.size() < 2) {
        throw invalid_argument("Getting a profit requires at least 2 prices");
    }
	
	int sellIndex, sellValue = 0;
	int buyIndex = stockPrices.size() - 1;
	int buyValue = 9999999;
	int profit, maxProfit = 0;

	for (int i = 0; i < stockPrices.size(); i++)
	{
		if (stockPrices[i] < buyValue)
		{
			buyIndex = i;
			buyValue = stockPrices[i];
		}
        else if (stockPrices[i] > buyValue)
        {
            profit = stockPrices[i] - buyValue;
            if (profit > maxProfit)
            {
                maxProfit = profit;
                sellIndex = i;
                sellValue = stockPrices[i];
            }
        }
	}
    
    if (maxProfit == 0)
        cout << "Don't buy or sell today, market is down" << endl;
    else
    {
        cout << "Buy: " << buyValue << endl;
        cout << "Sell: " << sellValue << endl;
        cout << "Profit: " << maxProfit << endl;
    }
	return maxProfit;
}

int main() {
	vector<int> stockPricesYesterday{10, 7, 5, 11, 8, 9};
    getMaxProfit(stockPricesYesterday);
	// returns 6 (buying for $5 and selling for $11)
}