class Solution {
public:
    // Inorder Successor
    // Left-most node in the right subtree
    TreeNode* getInorderSuccessor(TreeNode* root) {
        while (root != NULL && root->left != NULL) {
            root = root->left;
        }

        return root;
    }

    // Delete node from BST
    TreeNode* deleteNode(TreeNode* root, int key) {

        if (root == NULL) {
            return NULL;
        }

        // Key is in left subtree
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        }

        // Key is in right subtree
        else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        }

        // Key is at current node
        else {

            // 0 or 1 child
            if (root->left == NULL) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }

            // 0 or 1 child
            else if (root->right == NULL) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            // 2 children
            else {
                TreeNode* IS = getInorderSuccessor(root->right);

                root->val = IS->val;

                root->right = deleteNode(root->right, IS->val);
            }
        }

        return root;
    }
};