/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 /**
 思路：关键是树的递归定义，遍历对其子树也成立

 关于遍历顺序，前中后是指的root位置，left和right的相对顺序不变，只改变root的位置
 前序遍历：root->left->right
 中序遍历: left->root->right
 后续遍历: left->right->root

 分治法：变为子问题，不断找出子树根节点
 **/
class Solution {
    private:
    unordered_map<int, int> indexMap;
    vector<int> *m_preorder;
    vector<int> *m_inorder;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //build hash map key-index
        for (int i=0; i<inorder.size(); i++)
        {
            indexMap.insert(make_pair(inorder[i], i));
        }
        m_preorder = &preorder;
        m_inorder = &inorder;
        return subTree(0, preorder.size()-1, 0, inorder.size()-1);
    }
    TreeNode* subTree(int preorder_left, int preorder_right, int inorder_left, int inorder_right)
    {
        const vector<int>& preorder = *m_preorder;
        const vector<int>& inorder  = *m_inorder;

        if (preorder_left > preorder_right) return NULL;

        TreeNode* root = new TreeNode(preorder[preorder_left]);//前序遍历第一个就是根节点
        //split preorder and inorder
        int inorder_root = indexMap[root->val];
        int size_left_subtree = inorder_root-inorder_left;//左子树大小

        root->left  = subTree(preorder_left+1, preorder_left+size_left_subtree, inorder_left, inorder_root-1);
        root->right = subTree(preorder_left+size_left_subtree+1, preorder_right, inorder_root+1, inorder_right);
        return root;
    }
};