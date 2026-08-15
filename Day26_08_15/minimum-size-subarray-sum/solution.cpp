/*
209. 长度最小的子数组
中等
给定一个含有 n 个正整数的数组和一个正整数 target 。
找出该数组中满足其总和大于等于 target 的长度最小的 
子数组 [numsl, numsl+1, ..., numsr-1, numsr] ，
并返回其长度。如果不存在符合条件的子数组，返回 0 。
*/
#include <vector>
#include<iostream>
using namespace std;
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int size = nums.size();
        int left = 0, right = 0;
        int sum = 0;
        int res = INT_MAX;
        while(left <= right && right < size)
        {
            sum += nums[right];
            while(sum>=target)
            {
                res=min(res,right-left+1);
                sum -= nums[left];
                left++;
            }
            right++;
        }
        return res==INT_MAX?0:res;
}
};


int main(){

    Solution s;
    vector<int> nums = {2,3,1,2,4,3};
    cout<<s.minSubArrayLen(7,nums)<<endl;

    return 0;
}
/*
反思：滑动窗口
一直加right，直到sum>=target，然后一直加left，直到sum<target，然后right++，继续循环
*/