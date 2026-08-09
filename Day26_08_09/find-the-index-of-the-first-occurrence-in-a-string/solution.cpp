/*
28. 找出字符串中第一个匹配项的下标
简单
给你两个字符串 haystack 和 needle ，
请你在 haystack 字符串中找出 needle 字符串的
第一个匹配项的下标（下标从 0 开始）。如果 needle 不是 haystack 的一部分，
则返回  -1 。
*/
#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();
        if (m == 0) {
            return 0;
        }
        for (int i = 0; i < n - m + 1;i++)
        {
            if(haystack.substr(i,m) == needle)
            {
                return i;
            }
        }
        return -1;
    }
};
int main() {
    Solution s;
    cout<<s.strStr("sadbutsad","sad");
    return 0;
}