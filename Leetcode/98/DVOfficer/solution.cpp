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

struct NodeValid{
    int mx, mn, valid;
};

class Solution {
public:
    NodeValid find(TreeNode* root){
        NodeValid ret;
        ret.valid = 1;
        ret.mx = root -> val;
        ret.mn = root -> val;
        if(root -> right != nullptr){
            NodeValid r = find(root -> right);
            ret.valid *= r.valid;
            if(!ret.valid)
                return ret;
            if(root->val >= r.mn){
                ret.valid = 0;
            }
            ret.mx = r.mx;
        }
        if(!ret.valid)
            return ret;
        if(root -> left != nullptr){
            NodeValid r = find(root -> left);
            ret.valid *= r.valid;
            if(!ret.valid)
                return ret;
            
            if(root->val <= r.mx){
                ret.valid = 0;
            }
            ret.mn = r.mn;
        }

        return ret;
    }


    bool isValidBST(TreeNode* root) {
        return find(root).valid == 1;
    }
};
