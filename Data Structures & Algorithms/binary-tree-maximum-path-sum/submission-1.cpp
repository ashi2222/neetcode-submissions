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
    int solve(TreeNode*root , int &sum)
    {
        if(root==NULL)return 0;
        
        
        int leftans = max(solve(root->left  , sum) , 0);
        int rightans = max(solve(root->right , sum) , 0);
        
        sum = max((leftans + rightans + root->val) , sum);
        return max(leftans , rightans)+root->val;
    }
    int maxPathSum(TreeNode* root) {
        if(root == NULL)return 0;
        int sum = root->val ;
        int ans = solve(root , sum);
        return max(ans, sum);
    }
};