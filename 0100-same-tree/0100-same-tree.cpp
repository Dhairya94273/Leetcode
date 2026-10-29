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
    bool isSameTree(TreeNode* p, TreeNode* q) {//Any One Node is NULL
        if((p==NULL && q!= NULL ) || (p!=NULL && q==NULL)){ 
            return false;
        }
        if(p==NULL && q==NULL){//both nodes are NULL
            return true;
        }
        bool isLaft = isSameTree(p->left , q->left); 
        bool isRight = isSameTree(p->right , q->right);
        return p->val == q->val && isLaft && isRight;
    }
};