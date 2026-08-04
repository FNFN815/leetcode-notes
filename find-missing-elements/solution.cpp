/*3731. 找出缺失的元素
给你一个整数数组 nums ，数组由若干 互不相同 的整数组成。
数组 nums 原本包含了某个范围内的 所有整数 。但现在，其中可能 缺失 部分整数。
该范围内的 最小 整数和 最大 整数仍然存在于 nums 中。
返回一个 有序 列表，包含该范围内缺失的所有整数，并 按从小到大排序。如果没有缺失的整数，
返回一个 空 列表。
*/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
    public:
    vector<int> findMissingElements(vector<int>& nums) {
        int size=nums.size();
        if(size==0)
        {
            return {};
        }
        vector<int> res{};
        int minNum=nums[0],maxNum=nums[0];
        for(int i=0;i<size;i++){
            if(nums[i]<minNum)
            {
                minNum=nums[i];
            }
            if(nums[i]>maxNum)
            {
                maxNum=nums[i];
            }
        }
        for (int i = minNum;i<=maxNum;i++)
        {
            for (int j = 0; j < size;j++)
        {
            if(nums[j]==i)
            {
                break;
            }
            if(j==size-1)
            {
                res.push_back(i);
            }
        }
        }
        return res;
    }
};


int main() {
    Solution s;
    vector<int> nums{1,2,4,5,6,7,8,9};
    vector<int> res=s.findMissingElements(nums);
    for (int i = 0; i < res.size();i++)
    {
        cout<<res[i]<<" ";
    }
    cout<<endl;
    return 0;
}