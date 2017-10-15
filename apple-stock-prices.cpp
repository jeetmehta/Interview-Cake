#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int getMaxProfit(vector <int> stockPrices)
{
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
        for (int j = i+1; j < stockPrices.size(); j++)
        {
            profit = stockPrices[j] - buyValue;

            if (profit > maxProfit)
            {
                sellValue = stockPrices[j];
                maxProfit = profit;
                sellIndex = j;
            }
        }
	}
    cout << "Buy: " << buyValue << endl;
    cout << "Sell: " << sellValue << endl;
    cout << "Profit: " << maxProfit << endl;
	return maxProfit;
}

int main() {
	vector<int> stockPricesYesterday{10, 7, 5, 8, 11, 9};
	cout << getMaxProfit(stockPricesYesterday) << endl;
	// returns 6 (buying for $5 and selling for $11)
}