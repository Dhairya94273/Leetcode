/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void inOrder(TreeNode* root, vector<int>& ans) {
        if (root == NULL)
            return;

        inOrder(root->left, ans);
        ans.push_back(root->val);
        inOrder(root->right, ans);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inOrder(root, ans);
        return ans;
    }
    
    TreeNode* increasingBST(TreeNode* root) {   
         vector<int> ans = inorderTraversal(root);

        TreeNode* head = NULL;
        TreeNode* current = NULL;

        for(int i = 0; i < ans.size(); i++) {

            TreeNode* newNode = new TreeNode(ans[i]);

            if(head == NULL) {
                head = newNode;
                current = newNode;
            }
            else {
                current->right = newNode;
                current = newNode;
            }
        }

        return head;
    }
};