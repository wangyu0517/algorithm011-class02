
/**
思路：
1、数组插入不方便，可以转换为对应的链表结构，改成合并有序链表。需要将数组转化为链表，要开辟额外的空间
2、不使用辅助内存，只做元素移动。1、递归形式。 2、递归展开转换为循环形式

nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

从后往前，双指针

**/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int total= m+n;//总数
        int reverseIndex = total - 1;
        int index1 = m-1;
        int index2 = n-1;
        for (; reverseIndex >= 0; reverseIndex--)//一次循环填一个元素
        {
            if(index1<0 || index2 <0)
                break;
            if(nums1[index1] > nums2[index2] )
            {
                nums1[reverseIndex] = nums1[index1];//找出最大的元素
                index1--;
            }else
            {
                nums1[reverseIndex] = nums2[index2];//找出最大的元素
                index2--;
            } 
                    
        }
    
        while(index2 >= 0)
        {
            nums1[reverseIndex--] = nums2[index2--];
        }
       
        while(index1 >= 0)//原地自己给自己赋值
        {
            nums1[reverseIndex--] = nums1[index1--];
        }

    }
};
//和合并有序链表一样的思路。3指针，1个写入位置指针，2个有序栈的栈顶指针（把2个数组看成2个有序栈，每次pop较大的元素，放到写入位置。因为逆序，不会有地址冲突）
//优化nums2为空时不需要移动，避免原地自己给自己赋值