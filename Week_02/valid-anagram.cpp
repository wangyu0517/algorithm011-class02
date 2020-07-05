//思路哈希表
//s和t大小一样，先确定外层循环，每次遍历一个元素。 k 代表字符， v代表字符出现的次数

class Solution {
public:
    bool isAnagram(string s, string t) {
        std::map<int, int> map;
        for (int i =0; i<s.size(); i++)
        {
            map[s[i]]++;
        }

        for (int i =0; i<t.size(); i++)
        {
            map[t[i]]--;
        }
        auto iter = map.begin();
        while(iter!=map.end())
        {
            if(iter->second != 0)
                return false;
            iter++;
        }
        return true;

    }
};