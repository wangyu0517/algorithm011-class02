class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
         vector<vector<string>> res;  
        int sub=0;  //结果vector的下标值
        string tmp; //临时string
        unordered_map<string,int> work; //判断排序后单词是否存在，即字母组成是否一致，string 代表排序过后的字符串，int代表下标计数，每次发现一个新字符串，会增加下标
        for(auto str:strs)
        {
            tmp=str;
            sort(tmp.begin(),tmp.end());//string 有容器操作
            if(work.count(tmp))
            {
               res[work[tmp]].push_back(str);
            }
            else
            {
                vector<string> vec(1,str);
                res.push_back(vec);
                work[tmp]=sub++;//记录下标，方便发现时记录到vec的对应位置
            }
        }
        return res;
    }
};