class Solution {
public:
    int height(TreeNode* root) {
        if (root == NULL)
            return 0;

        int left = height(root->left);//height of a left subtree
        if (left == -1) return -1;

        int right = height(root->right);//height of a right subtree
        if (right == -1) return -1;

        if (abs(left - right) > 1)//Difference between left and right subtree heights must be at most 1.
            return -1;

        return max(left, right) + 1;
    }

    bool isBalanced(TreeNode* root) {
        return height(root) != -1;//height of root is not equal to -1 then true  otherwise false
    }
};





