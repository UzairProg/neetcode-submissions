class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /* 
        if prices[i] is selling price all lhs to prices[i] can be buying
        and min of the lhs can be buying.. so we can get the max profit
        good thing we need only one pass for this
        */
        
        int buy = prices[0];
        int profit = 0;

        for(int i=1; i<prices.size(); i++){
            int sell = prices[i];
            buy = min(buy, prices[i-1]);
            profit = max(profit, sell-buy);
        }
        return profit;
    }
};
