/**
思路:有重复数据，怎么去重？结果用map存，去重
判断过程中去重
使用数组保存被使用的元素
重复条件，nums[i] = nums[i-1] && used[i-1] = false
**/

class Solution {
    private:
    vector<vector<int>> result;
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());//排序去重复
        vector<bool> used(nums.size(), false);
        vector<int> temp;//缓存每一个结果
        dfs(nums, used, temp);
        return result;
    }

    void dfs(vector<int>&nums, vector<bool>& used, vector<int>& temp)
    {
        if (temp.size() == nums.size())//所有元素被选择
        {
            result.push_back(temp);
            return;
        }

        for (int i = 0; i<nums.size(); i++)
        {
            if(used[i]) continue;//该index的元素已经使用过

            //去重复
            if (i>0 && nums[i-1]==nums[i] && used[i-1] ==false) continue;

            used[i] = true;
            temp.push_back(nums[i]);
            dfs(nums, used, temp);
            temp.pop_back();
            used[i] = false;
        }
    }
};