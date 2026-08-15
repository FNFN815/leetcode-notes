/*
3. 无重复字符的最长子串
中等
给定一个字符串 s ，请你找出其中不含有重复字符的 最长 子串 的长度。
示例 1:
输入: s = "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
注意 "bca" 和 "cab" 也是正确答案。
示例 2:
输入: s = "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
示例 3:
输入: s = "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
*/
#include <string>
#include<unordered_set>
#include<algorithm>
#include<iostream>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size = s.size();
        if(size == 0) return 0;
        int max = 0;
        int left = 0;
        int right = 0;
        unordered_set<char> set;
        while(left<=right&& right < size){
            if(set.find(s[right])==set.end())
            {
                set.insert(s[right]);
                right++;
            }
            else
            {
                set.erase(s[left]);
                left++;
            }
            max = std::max(max, right - left);
        }
        return max;
    }
};

int main(){
    Solution solution;
    cout<<solution.lengthOfLongestSubstring("abcabcbb")<<endl;
    return 0;
}
//反思：滑动窗口，unordered_set
//判断unordered_set中是否存在某个元素，使用find函数，返回值是迭代器，
//如果存在，则返回指向该元素的迭代器，否则返回unordered_set::end()
//left++
//不存在则插入，right++
//right-left就是当前窗口的大小，每次循环更新最大值
