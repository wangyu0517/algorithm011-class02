/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 /*
 思路：节点没有保存parent，无法自己从子节点访问父节点
 首先肯定是遍历，树考虑递归
 递归形式，节点找到p，或者q，直接返回

返回值 TreeNode*为true 表示root下至少有一个p或者q，
当左子树返回值和右子树返回值都不是空时，说明，当前root就是lca
否则lca在左右子树中的一个，

 
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL || root == p || root == q) return  root;
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        if(left && right) return root;//当前就是
        else if(left) return left;//在左边
        else if(right) return right;//在右边
        else return NULL;
    }
};