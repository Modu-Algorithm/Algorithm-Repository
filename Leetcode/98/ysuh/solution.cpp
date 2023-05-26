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
private:
    long int left_max_ = LONG_MAX;
    long int right_min_ = LONG_MIN;
    bool treeWalker(TreeNode* parent, long int left_max, long int right_min) {
        if(parent == NULL) return true;
        if(parent->val >= left_max || parent->val <= right_min){
            return false;
        }
        return treeWalker(parent->left, parent->val, right_min) && treeWalker(parent->right, left_max ,parent->val);
    }

public:
    bool res = true;
    bool isValidBST(TreeNode* root) {
        return treeWalker(root, left_max_, right_min_);
    }
};
