#include <iostream>
#include <vector>
using namespace std;

// function that checks for the best price of the stock from the list of prices
void MaximizeProfit(vector<int> price)
{
    int maxProfit = 0, bestBuy = price[0];
    for (int i = 1; i < price.size(); i++)
    {
        if (price[i] > bestBuy)
        {
            maxProfit = max(maxProfit, (price[i] - bestBuy));
        }
        bestBuy = min(bestBuy, price[i]);
    }
    cout << "the best time to buy stock is : " << bestBuy << " with maximum profit : " << maxProfit <<  endl;
}

int main()
{ 
    vector<int> vec = {7, 1, 5, 3, 6, 4};
    MaximizeProfit(vec);
}


