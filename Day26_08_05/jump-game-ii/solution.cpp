/*45. 跳跃游戏 II
给定一个长度为 n 的 0 索引整数数组 nums。初始位置在下标 0。
每个元素 nums[i] 表示从索引 i 向后跳转的最大长度。换句话说，如果你在索引 i 处，
你可以跳转到任意 (i + j) 处：
0 <= j <= nums[i] 且
i + j < n
返回到达 n - 1 的最小跳跃次数。测试用例保证可以到达 n - 1。
*/
#include <vector>
#include <iostream>
using namespace std;
class Solution {
    public:
    int jump(vector<int>& nums) {
        int size = nums.size();
        int max = 0;
        int step = 0;
        int end = 0;
        for (int i = 0; i < size - 1;i++)
        {
            if (i <= max)
            {
                max= max > i + nums[i] ? max : i + nums[i];
                if (i == end)
                {
                    end = max;
                    step++;
                }
            }
            
        }
        return step;
    }
};
int main(){
    return 0;
}