/*
思路：要求用原地算法。不开辟其他空间。只能操作index，比较通用的就是指针法
右旋k，可以一次性右旋k，或者右旋1执行k次。右旋1执行k次算是暴力解法
*/

// class Solution {
// public:
//     void rotate(vector<int>& nums, int k) {
        
//         for (int i=0; i<k; i++)
//         {
//             rotateOneStep(nums);
//         }
//     }

//     void rotateOneStep(vector<int>& nums) {
//         if (nums.size() < 2)
//         return;

//         int temp = nums[nums.size()-1];
//         for (int i = nums.size()-2;  i>=0; i--)
//         {
//             nums[i+1] = nums[i];//右平移
//         }
//         nums[0] = temp;
//     }
// };


/*
因为之前写过环形数组，用于无锁队列。所以本题考查重点是数组的取模运算
思路：很明显是一个环形数组，可以联想到模运算计算所有元素右旋k后的新index
1、对k取模，避免不必要的重复环。k=nums.size()时原地不动。k = k%nums.size();

2、从倒数第k个开始，remove元素到stack中。在将stack中的元素取出push_forward。
   空间复杂度有要求，只能手动移动元素了。
   
从新审视，前面已经简化了k，使得k一定小于数组大小。
那么问题的关键在于如何进行元素交换（不使用辅助结构，只能元素交换）。对于元素交换
大多数都有规律可循。所以元素交换。分为2种：1、暴力交换，使用遍历。2、结果论，直接拿正确结果和原始数据进行对比，找到变换规律

[1,2,3,4,5,6,7] k=10为例
等价于[1,2,3,4,5,6,7] k=3
最终结果为[5,6,7,1,2,3,4]
每个元素的最终位置都是可计算的，原始位置在index，最终应该在(index+k)%size()这个新位置，而原本
这个位置的元素，我们需要把它保存起来，用同样的公式计算它应该去的位置。
1、第0个元素开始，移动到（0+3）%7 = 3的位置。
2、计算原来index=3应该去的地方，（3+3）%7 = 6，移动到index = 6的位置
3、计算原来index=6应该去的地方，同理去2，
4、计算原来index=2应该去的地方，同理去5，
5、计算原来index=5应该去的地方，同理去1，
6、计算原来index=1应该去的地方，同理去4，
7，计算原来index=4应该去的地方，同理去0.
这个移动顺序也成为一个环状。猜测从任意一个位置startPos开始，不断按照公式newindex = (index+k)%size()进行递推计算
最终一定能递推回开始的位置StartPos。即递推或者说循环结束条件是newIndex = startPos，完成所有元素的移动

验证：nums.size()%k=0时，无法一次闭环。因为被整除了，只能完成k/nums.size()部分数据替换
以[1,2,3,4,5,6,7,8,9] k=3为例，9/3=3，整除了
理想结果是[7,8,9,1,2,3,4,5,6]
实际上以0为开始
0->3
3->6
6->0
只完成了1/3部分
那么需要优化。当整除时，添加一个k/nums.size()次的循环
第一次循环，从0开始
0->3
3->6
6->0
第一次循环，从1开始
1->4
4->7
7->1
第一次循环，从2开始
2->5
5->8
8->2

优化需要多次循环，需要增加count计数保证count==nums.size,确保所有元素都计算了新的位置
*/
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (nums.size() < 2)
            return;//原地不动
        k = k%nums.size();
        if (k == 0)
            return;//原地不动        
       
        int count = 0;
        for (int startPos=0; count<nums.size(); startPos++)
        {
            int freeIndex = startPos;
            int freeData = nums[freeIndex];//保存游离数据
            do
            {
                int newIndex = (freeIndex+k)%nums.size();//计算oldIndex的元素应该放到哪个位置
                swap(freeData, nums[newIndex]);//交换newIndex和游离数据，原来的游离数据到newindex，原来newindex的数据成为新的游离数据
                count++;
                // printf("nums[%d] moveto nums[%d], count=%d\r\n",freeIndex, newIndex, count);//调试信息，对比上面的推导过程，所有元素计算一次新位置，复杂度O(n)
                freeIndex = newIndex;//下次循环，计算这次被顶掉的元素newIndex的新位置
            }while(freeIndex != startPos);
        }
    }
};

//总结：最终完成，需要不断找规律，修复代码。属于经验题，没做过就会花费大量时间找规律推导，甚至做不出来