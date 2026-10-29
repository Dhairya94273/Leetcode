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
    //left -> left means left child of the current left Node
    bool mirror(TreeNode *left , TreeNode *right){//O(n)
        if(left == NULL && right == NULL){//left and right both nodes are NULL
            return true;
        }
        if(left == NULL || right == NULL){//Left or Right Any One Node is NULL
            return false;
        }
        if(left->val != right->val){//left and Right values Are Different
            return false;
        }
        return mirror(left->left , right->right) && mirror(left->right , right->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root == NULL){//root is NULL
            return true;
        }
        return mirror(root->left , root->right);
    }
};