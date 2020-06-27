/*

1、暴力：从左向右遍历，找到第一个不同的元素位置，将这个位置及它后面的所有元素都平移
2、以暴力为基础，找到第一个不同元素后只需要把它移动到前面指定的位置。需要维护写入位置，和遍历位置。双指针方法
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0)
        return 0;
        int pos = 0;//起始位置是0
        for (int i = 1; i < nums.size(); i++)//快指针位置初始为1
        {
            if (nums[i] != nums[pos])
            {
                pos ++;//写入下个位置
                nums[pos] = nums[i];
            }
        }
       return pos+1;        //返回的是写入位置，慢指针的位置


    }
};