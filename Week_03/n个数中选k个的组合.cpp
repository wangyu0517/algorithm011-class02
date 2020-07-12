/**
思路：不断求子问题，递归解
元素n个的数组，取其中k个元素，的所有组合
每个元素分为取和不取2种，各自走分支，一直到递归退出条件
退出条件：k取完，不符合的分支，提前结束，回溯，回溯条件，剩余的数就算全选也不能满足k个了

**/
class Solution {
    private:
    vector<vector<int>> m_res;
public:
    vector<vector<int>> combine(int n, int k) 
    {
        vector<vector<int>> res;
        vector<int> stack;
        dfs(1, n, k, stack);
        return m_res;

    }
    void dfs(int start, int n, int k, vector<int>& temp)
    {
        if(temp.size() == k)
        {
            m_res.push_back(temp);
            return;//到达指定个数
        }
        if(n - start + 1 < k-temp.size()) return; //剩余的元素，就算全选也无法满足指定个数

        for (int i=start; i<=n; i++)
        {
            temp.push_back(i);
            dfs(i+1, n, k, temp);
            temp.pop_back();//回溯到开始状态
        }
        
    }
    vector<vector<int>> combine1(int n, int k) {
        vector<int> map(n,0);
        vector<vector<int>> res;
        for(int i=0;i<k;i++)//map大小为n, 其中k个是1，转换为求0,1数组的全排列
            map[i]=1;
        vector<int> tmp;
        do
        {
            for(int i=0;i<n;i++)
                if(map[i])  tmp.push_back(i+1);
            res.push_back(tmp);
            tmp.clear();
        }while(prev_permutation(map.begin(),map.end()));//求全排列
    return res;
    }
};