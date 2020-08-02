//思路：贪心。只要赚就立马卖掉，买入时机是，只要价格下降就买入，证明，价格下降买肯定比直接买更加赚
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 1) return 0;
       
        int get = 0;
        for (int i=0, j=prices.size(); i<j-1; i++)
        {
            if(prices[i] < prices[i+1]){
                get += prices[i+1] - prices[i];
            }
        }
        return get;
    }
};