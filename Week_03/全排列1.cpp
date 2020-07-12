/**
思路：排列组合，一般用回溯解
**/
class Solution {
    private:
    vector<vector<int>> result;
public:
    vector<vector<int>> permute(vector<int>& nums) {
       vector<int> subRes = nums;
       dfs(0, nums.size(), subRes);//每取出nums中的一个元素，放进subres中
       return result;
    }

    void dfs(int start_index, int n,  vector<int> &temp)
    {
        if (start_index == n)
        {
            result.push_back(temp);
            return;
        }
        for (int i=start_index; i<n; i++) //最外层循环
        {
           swap(temp[i], temp[start_index]);
           dfs(start_index+1, n, temp);//start_index作为已选元素的分界点，在temp中，start_index左边是已经选择的元素
           swap(temp[i], temp[start_index]);//子分类完成后，回溯到开始状态
        }

    }

};