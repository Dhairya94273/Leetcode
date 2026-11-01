
class Solution {
public:
    int findSecondMinimumValue(TreeNode* root) {
        if(root == NULL){
            return -1;
        }

        if(root->left == NULL && root->right == NULL){
            return -1;
        }

        int left = root->left->val;
        int right = root->right->val;

        if(left > root->val && right > root->val){
            return min(left, right);
        }

        if(left == root->val){
            left = findSecondMinimumValue(root->left);
        }

        if(right == root->val){
            right = findSecondMinimumValue(root->right);
        }

        if(left == -1) return right;
        if(right == -1) return left;

        return min(left, right);
    }
};
