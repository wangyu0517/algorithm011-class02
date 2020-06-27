/**
暴力枚举
hash
sort后夹逼
**/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::map<int, int> record;
        int i=0;
        int expect; 
        for (; i<nums.size(); i++)
        {
            record.insert(pair<int, int>(nums[i], i));
            expect = target - nums[i];//期望得到
            if(record.find(expect)!=record.end() && record[expect] != i)//查看记录有没有这个元素,并且不能重复
            {
                break;
            }
        }
        return vector<int>{i, record[expect]};

    }
};