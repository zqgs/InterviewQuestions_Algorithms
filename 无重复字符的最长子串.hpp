#include <iostream>

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