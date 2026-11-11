class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit = 0;
        int runningmin = prices[0];

        for(int i = 1; i<prices.size(); i++){
            int profit = prices[i] - runningmin;
            if(profit > maxprofit){
                maxprofit = profit;
            }
            if(prices[i] < runningmin){
                //new buy candidate
                runningmin = prices[i];
            }

        }
        return maxprofit;
    }
};
