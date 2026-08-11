/*
125. 验证回文串
简单
如果在将所有大写字符转换为小写字符、并移除所有非字母、数字字符之后，
短语正着读和反着读都一样。则可以认为该短语是一个 回文串 。
字母和数字都属于字母数字字符。
给你一个字符串 s，如果它是 回文串 ，返回 true ；否则，返回 false 。
*/
#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
        string s1{};
        for(auto& c:s)
        {
            if(c>='A'&&c<='Z')
            {
                s1+=c-'A'+'a';
            }
            else if(c>='a'&&c<='z')
            {
                s1+=c;
            }
            else if(c>='0'&&c<='9')
            {
                s1+=c;
            }

        }
        int size1=s1.size();
        
        for (int i = 0; i < size1 / 2;i++)
        {
            if(s1[i]!=s1[size1-i-1])
            {
                return false;
            }
        }
        return true;
    }
};
int main()
{   
    Solution s;
    cout<<s.isPalindrome("0P")<<endl;
    return 0;
}