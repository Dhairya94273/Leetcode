#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

static int idx = -1;
Node* buildTree(vector<int>& preorder) {//O(n)
    idx++;
    if (preorder[idx] == -1) {
        return NULL;
    }
    Node* root = new Node(preorder[idx]);
    root->left = buildTree(preorder);
    root->right = buildTree(preorder);
    return root;
}

int height(Node* root){//O(n)
    if(root == NULL){
        return 0;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return max(leftHeight, rightHeight) + 1;
}

int countNode(Node* root){//O(n)
    if(root == NULL){
        return 0;
    }
    int leftCount = countNode(root->left);
    int rightCount = countNode(root->right);
    return leftCount + rightCount + 1;
}

int main() {
    vector<int> preorder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root = buildTree(preorder);

    cout << "Height of the tree: " << height(root) << endl;
    cout << "Number of nodes in the tree: " << countNode(root) << endl;
    return 0;
}
