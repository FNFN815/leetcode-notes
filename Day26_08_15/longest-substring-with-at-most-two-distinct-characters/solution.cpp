/*
159. 至多包含两个不同字符的最长子串
中等
给你一个字符串 s ，请你找出 至多 包含 两个不同字符 的最长子串，并返回该子串的长度。
*/
#include <string>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int size = s.size();
        unordered_map<char, int> map;
        int left = 0, right = 0;
        int res = 0;
        while(left<=right&&right<size)
        {   
            map[s[right]]++;
            right++;
           while(map.size()>2)
            {
                map[s[left]]--;
                if(map[s[left]]==0)
                {
                    map.erase(s[left]);
                }
                left++;
                
            }
            res = max(res, right-left);
        }
        return res;
    }
};
int main()
{   
    Solution s;
    cout<<s.lengthOfLongestSubstringTwoDistinct("eceba")<<endl;
    return 0;
}
//反思：滑动窗口，用哈希表记录窗口内字符出现的次数，当哈希表大小大于2时，
//移动左指针，直到哈希表大小小于等于2