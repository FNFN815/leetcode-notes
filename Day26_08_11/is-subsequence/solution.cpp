/*
392. 判断子序列
简单
给定字符串 s 和 t ，判断 s 是否为 t 的子序列。
字符串的一个子序列是原始字符串删除一些（也可以不删除）
字符而不改变剩余字符相对位置形成的新字符串。（例如，"ace"是"abcde"的一个子序列，
而"aec"不是）。
*/
#include <string>
#include<iostream>
using namespace std;
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0;
        int size_s = s.size();
        int size_t = t.size();
        while(i<size_s&&j<size_t)
        {
            if(s[i]==t[j])
            {
                i++;
                j++;
            }
            else
            {
                j++;
            }
        }
    return i==size_s;

    }
};
int main()
{   
    Solution s;
    string s1 = "abc";
    string s2 = "ahbgdc";
    cout<<s.isSubsequence(s1,s2)<<endl;
    
    return 0;
}