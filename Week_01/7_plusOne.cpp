/**
思路:进位循环，模运算
1、暴力转为数字，运算后转回数组，会有溢出问题
2、进位循环，循环条件怎么设置？考虑到是返回一个新的数组，这个数组大小一定大于等于原数组。最高位发生进位时，多出1个
3、能否通过2进制或者其他进制规律来算？
**/
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int overFlow = 1;//进位
        list<int> result;
        for (int i=digits.size()-1; i>=0; i--)
        {
            result.push_front((digits[i]+overFlow)%10);
            overFlow = (digits[i]+overFlow)/10;
        }
        if(overFlow >0)
        {
            result.push_front(1);
        }
        vector<int> re;
        for(auto &i: result)
        {
            re.push_back(i);
        }
        return re;
    }
};