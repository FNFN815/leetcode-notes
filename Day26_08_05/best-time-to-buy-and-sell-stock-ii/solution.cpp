/*122. 买卖股票的最佳时机 II
给你一个整数数组 prices ，其中 prices[i] 表示某支股票第 i 天的价格。
在每一天，你可以决定是否购买和/或出售股票。你在任何时候 最多 只能持有 一股 股票。
然而，你可以在 同一天 多次买卖该股票，但要确保你持有的股票不超过一股。
返回 你能获得的 最大 利润 。
*/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
    public:
    int maxProfit(vector<int>& prices) {
        int maxprofit=0;
        int size=prices.size();
        for (int i = 0; i < size-1;i++)
        {
           if(prices[i]<prices[i+1])
           {
               maxprofit += prices[i + 1] - prices[i];
           }
        }
        return maxprofit;
       
    }
};
int main(){
    Solution s;
    vector<int> prices={7,1,5,3,6,4};
    cout<<s.maxProfit(prices)<<endl;
    return 0;
}