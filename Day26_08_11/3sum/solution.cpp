/*
15. 三数之和
中等
相关标签
给你一个整数数组 nums ，判断是否存在三元组
 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，
 同时还满足 nums[i] + nums[j] + nums[k] == 0 。
 请你返回所有和为 0 且不重复的三元组。
注意：答案中不可以包含重复的三元组。
*/
#include <vector>
#include <algorithm>
#include<iostream>
using namespace std;
class Solution {
public:
    vector<vector<int>> twoSum(vector<int>& numbers,int start,int end, int target,int val) {
      
        int left=start,right=end;
        vector<vector<int>> res;

        while(left<right)
        {
            int diff = target - numbers[left];
            if(diff==numbers[right])
            {
                vector<int> result;
                result.push_back(val);
                result.push_back(numbers[left]);
                result.push_back(numbers[right]);
                res.push_back(result);
                while(left<right&&numbers[left]==numbers[left+1])
                {
                    left++;
                }
                left++;
                while(left<right&&numbers[right]==numbers[right-1])
                {
                    right--;
                }
                right--;
            }
            else if(diff<numbers[right])
            {
                while(left<right&&numbers[right]>diff)
                {
                    right--;
                }
            }
            else
            {
                while(left<right&&numbers[left]<target-numbers[right])
                {
                    left++;
                }
            }
        }
        return res;
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for(int i=0;i<nums.size();i++)
        {
            if(i>0&&nums[i]==nums[i-1])
            {
                continue;
            }
            auto twoSumRes = twoSum(nums,i+1,nums.size()-1,0-nums[i],nums[i]);
            res.insert(res.end(),twoSumRes.begin(),twoSumRes.end());

        }
        return res;
    }
     
};
int main()
{   
    Solution s;
    vector<int> nums = {-1,0,1,2,-1,-4};
    auto res = s.threeSum(nums);
    for(auto& v:res)
    {
        for(auto& i:v)
        {
            cout<<i<<" ";
        }
        cout<<endl;
    }

    return 0;
}