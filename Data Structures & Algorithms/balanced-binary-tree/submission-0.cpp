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
    int solve(TreeNode*root , bool& ans)
    {
        if(!ans)return 0;
        if(root==NULL)return NULL;
        if(root->left == NULL && root->right == NULL)return 1;
        int leftans = solve(root->left , ans);
        int rightans = solve(root->right , ans);
        if(abs(leftans - rightans) > 1)ans = false;
        return max(leftans , rightans)+1;
    }
    bool isBalanced(TreeNode* root) {
        int height = 0;
        bool ans = true;
        solve(root,ans);
        return ans;
    }
};
