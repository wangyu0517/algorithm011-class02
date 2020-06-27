/**
思路:原地移动，考的基本是规律，和指针操作。避免不必要的操作
双指针：1个遍历位置指针，1个写入位置指针。和第一题排序数组去重一样
**/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int writePos = -1;//-1代表没有写入位置，即没有找到0
        for (int i = 0; i<nums.size(); i++)
        {
            if(nums[i]==0 && writePos < 0)//特殊初始化写入位置，只会执行一次
            {
                writePos = i;
            }
            else
            {
                if(writePos>=0 && nums[i] !=0 )
                {
                    // printf("swap(nums[%d], nums[%d]\r\n)",writePos, i);
                    swap(nums[writePos++], nums[i]);//写入
                }
            }
            
        }
    }
};