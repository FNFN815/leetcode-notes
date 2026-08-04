/*189. 轮转数组
给定一个整数数组 nums，将数组中的元素向右轮转 k 个位置，其中 k 是非负数。
*/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
    public:
    void rotate(vector<int>& nums, int k) {
        int size=nums.size();
        if(size==1||k==0)
        {
            return;
        }
        vector<int> temp{};
        int move = k % size;
        for (int i = 0; i < size;i++)
        {
            temp.push_back(nums[(i-move+size)%size]);
        }
        nums = temp;
    }
};
int main(){
    Solution s;
    vector<int> nums{1,2,3,4,5,6,7};
    s.rotate(nums,3);
    for (int i = 0; i < nums.size();i++)
    {
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    return 0;
}