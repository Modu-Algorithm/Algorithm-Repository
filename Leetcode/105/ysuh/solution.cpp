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
    TreeNode root;
    TreeNode* root_pointer = &root;
    
    int findRight(int pivot, vector<int>& preorder, vector<int>& inorder) {
        int start_idx = 2;
        while (true) {
            if (start_idx == preorder.size()) return -1;
            for (int idx=0; idx<inorder.size(); idx++) {
                if (pivot == inorder[idx]) {
                    start_idx++;
                    continue;
                }
                if (preorder[start_idx] == inorder[idx]) {
                    return start_idx;
                }
            }
        }
    }
    TreeNode* traverseTree(TreeNode* parent, vector<int>& preorder, vector<int>& inorder) {
        
        // parent->val = preorder[0];
        // parent->val = 0;
        // if (preorder.size() > 1) {
        //     for (int i=0; i<inorder.size(); i++) {
        //         if (preorder[1] == inorder[i]) {
        //             TreeNode left(preorder[1]);
        //             parent->left = &left;
        //             if (preorder.size() > 2) {
        //                 int right_idx = findRight(preorder[0], preorder, inorder);
        //                 if (right_idx == -1) {
        //                     parent->right = NULL;
        //                 } else {
        //                     TreeNode right(preorder[right_idx]);
        //                     parent->right = &right;
        //                 }
        //             } else {
        //                 parent->right = NULL;
        //             }
        //             preorder.erase(preorder.begin());
        //             inorder.erase(inorder.begin()+i);
        //         }
        //         if (preorder[0] == inorder[i]) {
        //             parent->left = NULL;
        //             TreeNode right(preorder[1]);
        //             parent->right = &right;
        //             preorder.erase(preorder.begin());
        //             inorder.erase(inorder.begin()+i);
        //             break;
        //         }
        //     }
        // }
        // if (parent->left != NULL) {
        //     traverseTree(parent->left, preorder, inorder);
        // }
        // if (parent->right != NULL) {
        //     traverseTree(parent->right, preorder, inorder);
        // }
        return parent;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        traverseTree(root_pointer, preorder, inorder);
        return root_pointer;
    }
};
