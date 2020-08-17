Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).

Example 1:

Input: [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
             Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
Example 2:

Input: [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
             Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are
             engaging multiple transactions at the same time. You must sell before buying again.
Example 3:

Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.

class Solution {
    int maxprofit=0;
public:
    int getProfit(vector<int>& prices, bool buyOrSell, int transaction, int index){
        if(index == prices.size() || transaction == 0)
            return 0;
          
        if(!buyOrSell){
            int buy = getProfit(prices,true,transaction,index+1) - prices[index];
            int noBuy = getProfit(prices,false,transaction,index+1);
        
            maxprofit = max(buy,noBuy);
        }else{
            int sell = getProfit(prices,false,transaction-1,index+1) + prices[index];
            int noSell = getProfit(prices,true,transaction,index+1);
        
            maxprofit = max(sell,noSell);
        }
        return maxprofit;
    }
    
    int maxProfit_recursive(vector<int>& prices) {
        
        getProfit(prices,false,2,0);
        return maxprofit;
    }
    /*This is a tougher problem than it looks, since it has several tricky edge cases that might have an otherwise working solution collapse (I hit my nose against several of them), so I finally ended up tackling it keeping its complexity (in cognitive/structure terms) to a minimum, also to get better control of it.

I start declaring a number of variables, initialising them as firstBuy = INT_MAX, secondBuy = INT_MAX, firstProfit = 0, secondProfit = 0; I think I do not have to comment about their usage since the name should be rather self-explanatory, so let's move to the rest of the logic.

I start iterating through the array taking each value as currPrice and then starting a series of comparisons:

I want firstBuy to be the minimum between its current value and currPrice;
I want firstProfit to be the maximum between its current value and currPrice - firstBuy;
I want secondBuy to be the minimum between its current value and currPrice;
I want secondProfit to be the maximum between its current value and currPrice - secondBuy.
I guess the least intuitive part is the jump from firstProfit to secondBuy, but if you try a few mental/pen and paper examples, it should make more sense.

Eventually.

It might also help checking my solution to another problem of this group that considered local minima and maxima.

Keeping this invariant, I can make sure that at the end secondProfit will yield the maximum achievable profit, so I can just return it.*/
    int maxProfit(vector<int>& prices) {
        int firstBuy = INT_MAX, secondBuy = INT_MAX, firstProfit = 0, secondProfit = 0;
        for(int currPrice: prices) {
            firstBuy = min(firstBuy, currPrice);
            firstProfit = max(firstProfit, currPrice - firstBuy);
            secondBuy = min(secondBuy, currPrice - firstProfit);
            secondProfit = max(secondProfit, currPrice - secondBuy);
        }
        return secondProfit;
    }
};
