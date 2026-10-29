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
    int createNumber(TreeNode *root , int num){
        if(root == NULL){
            return 0;
        }
        //Add Current Digit
        num = num*10 + root->val;
        //leaf Node
        if(root->left == NULL && root->right == NULL){
            return num;
        }
        int left = createNumber(root->left , num);
        int right = createNumber(root->right,num);
        return left+right;
    }
    int sumNumbers(TreeNode* root) {
        return createNumber(root,0);
    }
};