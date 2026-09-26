class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for(int i=0; i<prices.size(); i++){
            int buy = prices[i];
            int sold = 0;
            for(int j=i+1; j<prices.size(); j++){
                if(prices[j] > buy){
                    sold = max(sold, prices[j]);
                }
            }
            profit = max(profit, (sold-buy));
        }
        return profit;
    } // brute force
};
