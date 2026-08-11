/*
11. 盛最多水的容器
中等
给定一个长度为 n 的整数数组 height 。有 n 条垂线，
第 i 条线的两个端点是 (i, 0) 和 (i, height[i]) 。
找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
返回容器可以储存的最大水量。
*/
#include <vector>
#include<iostream>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int size = height.size();
        int left = 0;
        int right = size - 1;
        
        int maxArea = 0;
        while(left<right)
        {   int len=right-left;
            int area= min(height[left],height[right])*len;
            maxArea = max(maxArea,area);
            if(height[left]<height[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        return maxArea;
    }
};
int main()
{
    Solution s;
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    cout<<s.maxArea(height)<<endl;
    return 0;
}