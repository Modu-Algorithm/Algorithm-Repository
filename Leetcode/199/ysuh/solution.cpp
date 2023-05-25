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
    int val_arr[100] = {0,};
    void f(TreeNode* node, int depth){
        if(node == NULL) return;
        val_arr[depth] = node -> val;
        f(node -> left, depth + 1);
        f(node -> right, depth + 1);
    }

public:
    vector<int> rightSideView(TreeNode* root) {
        for (int i=0; i<100; i++) {
            val_arr[i] = -101;
        }
        f(root, 0);
        vector <int> result;
        for (int i=0; i<100; i++) {
            if (val_arr[i] >= -100) {
                result.push_back(val_arr[i]);
            }
            else {
                break;
            }
        }
        return result;
    }
};
