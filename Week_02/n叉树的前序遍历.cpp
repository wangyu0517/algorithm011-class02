/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
        if(!root)
            return vector<int>();
        vector<int> vec;
        _PreOrder(root, vec);
        return vec;
    }

    void _PreOrder(Node* subRoot, vector<int>& vec)
    {
        vec.emplace_back(subRoot->val);
        for(int i=0; i<subRoot->children.size(); i++)
        {
            Node* node = subRoot->children[i];
            if(node)
            {
                _PreOrder(node, vec);
            }
        }
    }
};