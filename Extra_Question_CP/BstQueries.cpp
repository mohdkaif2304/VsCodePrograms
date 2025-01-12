#include <iostream>
#include <unordered_set>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr){}
};

class BST {
private:
    TreeNode* root;
    TreeNode* insert(TreeNode* node, int val) {
        if (node == nullptr)
            return new TreeNode(val);
        
        if (val < node->val)
            node->left = insert(node->left, val);
        else if (val > node->val)
            node->right = insert(node->right, val);
        
        return node;
    }

    bool search(TreeNode* node, int val) {
        if (node == nullptr)
            return false;
        if (node->val == val)
            return true;
        if (val < node->val)
            return search(node->left, val);
        else
            return search(node->right, val);
    }

    TreeNode* remove(TreeNode* node, int val) {
        if (node == nullptr)
            return nullptr;
        
        if (val < node->val)
            node->left = remove(node->left, val);
        else if (val > node->val)
            node->right = remove(node->right, val);
        else {
            if (node->left == nullptr) {
                TreeNode* temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == nullptr) {
                TreeNode* temp = node->left;
                delete node;
                return temp;
            }
            TreeNode* temp = minNode(node->right);
            node->val = temp->val;
            node->right = remove(node->right, temp->val);
        }
        return node;
    }

    TreeNode* minNode(TreeNode* node) {
        TreeNode* current = node;
        while (current->left != nullptr)
            current = current->left;
        return current;
    }

public:
    BST() : root(nullptr) {}

    void insert(int val) {
        root = insert(root, val);
    }

    bool search(int val) {
        return search(root, val);
    }

    void remove(int val) {
        root = remove(root, val);
    }
};

void processQueries(int Q, int queries[][2]) {
    BST bst;
    unordered_set<int> removed;

    for (int i = 0; i < Q; ++i) {
        int X = queries[i][0];
        int Y = queries[i][1];

        if (X == 0) {
            if (removed.find(Y) == removed.end())
                bst.insert(Y);
        } else if (X == 1) {
            if (bst.search(Y)) {
                cout << 1 << endl;
                bst.remove(Y);
                removed.insert(Y);
            } else {
                cout << 0 << endl;
            }
        }
    }
}

int main() {
    int Q = 5;
    int queries[5][2] = {{0, 1}, {1, 1}, {0, 2}, {1, 2}, {1, 1}}; 
    processQueries(Q, queries);
    return 0;
}