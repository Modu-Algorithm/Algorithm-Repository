/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    map<int, int> val_idx_map;
    int idx = 0;
    TreeNode* find(vector<int>& preorder, vector<int>& inorder, int left, int right) {
        if (left > right) {
            return nullptr;
        }
        int i_idx = val_idx_map[preorder[idx]];
        TreeNode* parent = new TreeNode(preorder[idx]);
        idx++;
        parent->left = find(preorder, inorder, left, i_idx-1);
        parent->right = find(preorder, inorder, i_idx+1, right);
        return parent;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int idx = 0;
        for (auto ele : inorder) {
            val_idx_map[ele] = idx;
            idx++;
        }
        return find(preorder, inorder, 0, inorder.size()-1);
    }
};
