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
    int rm[100] = {-111,};


public:

    void find(TreeNode* node, int level){
        if(node == nullptr)
            return;
        rm[level] = node -> val;
        
        find(node -> left, level + 1);
        find(node -> right, level + 1);
    }


    vector<int> rightSideView(TreeNode* root) {
        vector<int> ret;
        for(int i=0;i<100;i++)
            rm[i] = -999;
        find(root, 0);

        for(int i=0;i<100;i++){
            if(rm[i] >= -100)
                ret.push_back(rm[i]);
            else break;
        }

        return ret;
        
    }
};
