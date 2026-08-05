/*55. 跳跃游戏
给你一个非负整数数组 nums ，你最初位于数组的 第一个下标 。
数组中的每个元素代表你在该位置可以跳跃的最大长度。
判断你是否能够到达最后一个下标，如果可以，返回 true ；否则，返回 false 。
*/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
    public:
    bool canJump(vector<int>& nums) {
       int size= nums.size();
        int max = nums[0];
        for (int i = 1; i < size;i++)
        {
           max--;
           if(max<0){return false;}
           if(nums[i]>max){max=nums[i];}
            
        }
      return max>=0;
    }
};
int main() {
    Solution s;
    vector<int> nums = {2,3,1,1,4};
    cout << s.canJump(nums) << endl;
    return 0;
}