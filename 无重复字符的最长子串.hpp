#include <iostream>
/*
示例 1:

输入: s = "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
示例 2:

输入: s = "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
示例 3:

输入: s = "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
示例 4:

输入: s = ""
输出: 0
*/


bool ifStringCheck(const std::string &str,int &num)
{
    int checker = 0;
    for (int i = 0; i < str.length(); i++)
    {
        int val = str[i] - 'a'; //把a-z的字符, 转换成 0-25的数字
        if ((checker & (1<<val)) > 0)  // (1<<val)即得到对于bit位上的mask.  然后与 checker的位相与, 看是否为1
        {
            num = i;
            return false;
        }
        checker |= (1<<val);  //否则把这一位 置1
    }
    num = str.length();
    return true;
}

int lengthOfLongestSubstring(std::string s) 
{

    int MaxNum = 0;
    for (int i = 0; i < s.length(); i++)
    {
         for (int j = 0; j < s.length(); j++)
         {
             
            std::string temp = s.substr(j,i);
            int num;
            bool ret = ifStringCheck(temp,num); 
            std::cout<<"ret:"<<ret<<",num:"<<num<<"\n";
            if(num>MaxNum)
                MaxNum = num;
        }
    }
    return MaxNum;
}