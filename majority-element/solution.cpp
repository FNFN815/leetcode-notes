/*169. 多数元素
给定一个大小为 n 的数组 nums ，返回其中的多数元素。多数元素是指在数组中出现次数 大于 ⌊ n/2 ⌋ 的元素。
你可以假设数组是非空的，并且给定的数组总是存在多数元素。
*/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
    public:
    int majorityElement(vector<int>& nums) {
        int size=nums.size();
        int record[2] = {nums[0], 1};
        for (int i = 1; i < size;i++)
        {
            if(nums[i]==record[0])
            {
                record[1]++;
            }
            else
            {
                record[1]--;
                if(record[1]==0)
                {
                    record[0]=nums[i];
                    record[1]=1;
                }
            }
        }
        return record[0];
    }
};
int main(){
    Solution s;
    vector<int> nums={2,2,1,1,1,2,2};
    cout<<s.majorityElement(nums)<<endl;
    return 0;
}