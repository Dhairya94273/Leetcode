#include <iostream>
#include <vector>
#include <queue>
#include <map>
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
Node* buildTree(vector<int>& preorder) {
    idx++;
    if (preorder[idx] == -1) {
        return NULL;
    }
    Node* root = new Node(preorder[idx]);
    root->left = buildTree(preorder);
    root->right = buildTree(preorder);
    return root;
}

//top view of binary tree
void topView(Node* root) {//O(nlogn)
    queue<pair<Node* , int>>q;//(node , HD)
    map<int,int> m;//<HD , node val>
    q.push({root,0});

    while(q.size()>0){
        Node* current = q.front().first;
        int currHD = q.front().second; 

        if(m.find(currHD) == m.end()){
            m[currHD] = current->data; 
        }
        q.pop();
        
        if(current->left != NULL){
            q.push({current->left,currHD-1});
        }

        if(current->right != NULL){
            q.push({current->right,currHD+1});
        }
    }

    for(auto i : m){
        cout << i.second << " ";
    }
    cout << endl;
}

void bottomView(Node *root){
    queue<pair<Node* , int>>q;//(node , HD)
    map<int,int> m;//<HD , node val>
    q.push({root,0});
    while(q.size()>0){
        Node* current = q.front().first;
        int currHD = q.front().second; 

        m[currHD] = current->data; 
        q.pop();
        
        if(current->left != NULL){
            q.push({current->left,currHD-1});
        }

        if(current->right != NULL){
            q.push({current->right,currHD+1});
        }
    }

    for(auto i : m){
        cout << i.second << " ";
    }
    cout << endl;
}

int main(){
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node* root = buildTree(preorder);
    topView(root);
    bottomView(root);
    return 0;
}