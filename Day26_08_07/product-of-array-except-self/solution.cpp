/*238. 除了自身以外数组的乘积
给你一个整数数组 nums，返回 数组 answer ，其中 answer[i] 等于 nums 中除了 nums[i] 之外其余各元素的乘积 。

题目数据 保证 数组 nums之中任意元素的全部前缀元素和后缀的乘积都在  32 位 整数范围内。

请 不要使用除法，且在 O(n) 时间复杂度内完成此题。
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n, 1);
        vector<int> prefix(n, 1);
        vector<int> suffix(n, 1);

        for (int i = 1; i < n; i++) 
        {
            prefix[i]=prefix[i-1]*nums[i-1];
        }
        for (int i = n-2; i >= 0;i--)
        {
            suffix[i] = suffix[i + 1] * nums[i + 1];
        }
        for(int i=0;i<n;i++)
        {
            answer[i]=prefix[i]*suffix[i];
        }
            return answer;
    }
};
int main()
{   
    Solution s;
    vector<int> nums={1,2,3,4};
    vector<int> answer = s.productExceptSelf(nums);
    for(int i=0;i<answer.size();i++)
    {
        cout<<answer[i]<<" ";
    }
    cout<<endl;
    return 0;
}