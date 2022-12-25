#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
vector<int> v;
void traverse(TreeNode* n) {
    if (n) {
        traverse(n->left);
        if (v.empty() || v.back() < n->val)
            v.push_back(n->val);
        traverse(n->right);
    }
}
int main() {
    TreeNode *root;
    traverse(root);
    return 0;
}