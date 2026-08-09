/*
151. 反转字符串中的单词
中等
给你一个字符串 s ，请你反转字符串中 单词 的顺序。
单词 是由非空格字符组成的字符串。s 中使用至少一个空格将字符串中的 单词 分隔开。
返回 单词 顺序颠倒且 单词 之间用单个空格连接的结果字符串。
注意：输入字符串 s中可能会存在前导空格、尾随空格或者单词间的多个空格。
返回的结果字符串中，单词间应当仅用单个空格分隔，且不包含任何额外的空格。
*/
#include <string>
#include<stack>
#include<iostream>
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        stack<char> st{};
        string res{""};
        int size = s.size();
        for (int i = size - 1; i>= 0;i--)
        {   
            if(s[i]!=' ')
            {
                st.push(s[i]);
            }
            else if(s[i]==' '&&!st.empty())
            {   
                while(!st.empty())
                {
                    res+=st.top(); 
                    st.pop();
                }
                res+=" ";
            }
            else
            {
                continue;
            }
        }
        while(!st.empty())
        {
            res+=st.top(); 
            st.pop();
        }
        if(!res.empty()&&res.back()==' ')
        {
            res.pop_back();
        }
        return res;
    }
};
int main()
{   
    Solution s;
    cout<<s.reverseWords("the sky is blue")<<endl;
    return 0;
}