/*26. 删除有序数组中的重复项
给你一个 非严格递增排列 的数组 nums ，请你 原地
删除重复出现的元素，使每个元素只出现一次 , 返回删除后数组的新长度。元素的
相对顺序 应该保持 一致 。然后返回 nums 中唯一元素的个数。 考虑 nums
的唯一元素的数量为 k。去重后，返回唯一元素的数量 k。 nums 的前 k 个元素应包含
排序后 的唯一数字。下标 k - 1 之后的剩余元素可以忽略。
*/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int> &nums)
    {
        int size = nums.size();
        int i = 0;
        for (int j = 0; j < size; j++) {

            int next = j + 1;
            while (next < size && nums[next] == nums[j]) {
                next++;
            }
            if (next < size && next == j + 1 && nums[next] != nums[j]) {
                nums[i] = nums[j];
                i++;
            } else if (next == size && next == j + 1) {
                nums[i] = nums[j];
                i++;
            } else {
                nums[i] = nums[j];
                j = next - 1;
                i++;
            }
        }
        return i;
    }
};
  
int main()
{
  Solution s;
  vector<int> nums = {1, 1, 2};
  for (int i = 0; i < nums.size(); i++) {
    cout << nums[i] << " ";
  }
  cout << endl;
  int size = s.removeDuplicates(nums);
  for (int i = 0; i < size; i++) {
    cout << nums[i] << " ";
  }
  cout << endl;
    return 0;
}