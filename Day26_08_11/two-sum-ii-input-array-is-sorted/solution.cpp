/*
167. 两数之和 II - 输入有序数组
中等
给你一个下标从 1 开始的整数数组 numbers ，该数组已按 非递减顺序排列  ，
请你从数组中找出满足相加之和等于目标数 target 的两个数。
如果设这两个数分别是 numbers[index1] 和 numbers[index2] ，
则 1 <= index1 < index2 <= numbers.length 。
以长度为 2 的整数数组 [index1, index2] 的形式返回这两个整数的下标 index1 和 index2。
你可以假设每个输入 只对应唯一的答案 ，而且你 不可以 重复使用相同的元素。
你所设计的解决方案必须只使用常量级的额外空间。
*/
#include <vector>
#include<iostream>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
      
        int left=0,right=numbers.size()-1;
        while(left<right)
        {
            int diff = target - numbers[left];
            if(diff==numbers[right])
            {
                return {left+1,right+1};
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
        return {};
    }
};
int main()
{   
    Solution s;
    vector<int> nums={5,25,75};
    vector<int> res = s.twoSum(nums,100);
    for(auto i:res)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}