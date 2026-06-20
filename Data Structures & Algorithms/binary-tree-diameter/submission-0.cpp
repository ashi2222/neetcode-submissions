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
    int solve(TreeNode*root,int &dm){
        if(root == NULL)return 0;
        if(root->left == NULL && root->right == NULL)return 1;
        int leftans = solve(root->left , dm);
        int rightans = solve(root->right , dm);
        dm = max(dm,leftans + rightans);
        return max(leftans , rightans)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int dm = 0;
        solve(root,dm);
        return dm;
    }
};