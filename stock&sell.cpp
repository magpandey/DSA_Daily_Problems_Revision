//Its the problem where the we are given the array containing the prices of the stocks at different dates or indexes our job requires us to 
//return the maximum profit that can be obtained .We are required to demostrate the dynamic programning through this question

#include <iostream>
#include <vector>
using namespace std;
int Sell_stock(vector<int>prices){
    int maxProfit = 0;
    int bestBuy = prices[0];
    for(int i = 1; i<prices.size();i++){
        int profit = prices[i] - bestBuy;
        maxProfit = max(maxProfit,profit);
        if(prices[i]<bestBuy){
            bestBuy = prices[i];
        }
    }
    return maxProfit;
}
int main() {
    vector<int>prices = {3,2,7,1,4};
    int maxProfit = Sell_stock(prices);
    cout << "The max Profit is :" <<maxProfit <<endl;
    return 0;
}

