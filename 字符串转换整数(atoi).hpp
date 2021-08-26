#include <iostream>
#include <string>
#include <sstream>

/*
	读入字符串并丢弃无用的前导空格
	检查下一个字符（假设还未到字符末尾）为正还是负号，读取该字符（如果有）。 确定最终结果是负数还是正数。 如果两者都不存在，则假定结果为正。
	读入下一个字符，直到到达下一个非数字字符或到达输入的结尾。字符串的其余部分将被忽略。
	将前面步骤读入的这些数字转换为整数（即，"123" -> 123， "0032" -> 32）。如果没有读入数字，则整数为 0 。必要时更改符号（从步骤 2 开始）。
	如果整数数超过 32 位有符号整数范围 [−231,  231 − 1] ，需要截断这个整数，使其保持在这个范围内。具体来说，小于 −231 的整数应该被固定为 −231 ，大于 231 − 1 的整数应该被固定为 231 − 1 。
	返回整数作为最终结果。
	注意：

	本题中的空白字符只包括空格字符 ' ' 。
	除前导空格或数字后的其余字符串外，请勿忽略 任何其他字符。
*/


using namespace std;
long long pow(int n, int y)
{
    long long m = 1;
    for(int i=1;i<=y;i++)
    {
        m = n * m;
    }
    return m;
}


bool CheckString(string &s)
{
    if((s[0]-48<0)||(s[0]-48>9))
    {
        cout<<"string[0]:"<<s[0]<<"\n";
        return false;
    }
    stringstream ss;
    for(string::iterator it = s.begin();it!=s.end();it++)
    {
        //std::cout<<(*it-48)*pow(10,_size)<<std::endl;
        if((*it-48>=0)&&(*it-48<=9))
            ss<<*it;
    }
    s = ss.str();
    return true;
}

int myAtoi(string s) 
{
    bool fushu = false;
    if(s[0]=='-')
    {
        s = s.substr(1);
        fushu = true;
    }
    if(!CheckString(s))
        return 0;
    
    long long number = 0;
    size_t _size = s.size()-1;
    for(string::iterator it = s.begin();it!=s.end();it++)
    {
        number +=(*it-48)*pow(10,_size);
        _size--;
    }
    if(number>pow(2,31))
        number = pow(2,31);
    
    if(fushu)
        number = -number;
        
    return number;
}