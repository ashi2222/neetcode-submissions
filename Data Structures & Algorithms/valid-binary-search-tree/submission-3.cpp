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
    bool solve(TreeNode*root , long long int mini , long long int macs)
    {
        if(root == NULL)return true;
        if(root->val > mini && root->val < macs)
        {
            bool leftans = solve(root->left , mini , root->val);
            bool rightans = solve(root->right , root->val , macs);
            return (leftans && rightans);
        }
        return false;
    }
    bool isValidBST(TreeNode* root) {
        return solve(root , -1e11 , 1e11);
    }
};