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
        if(root==NULL)return -1e4;
        if(root->left == NULL && root->right == NULL) {
            sum = max(sum , root->val);
            return root->val;
        }
        
        int leftans = solve(root->left  , sum);
        int rightans = solve(root->right , sum);

        int maxsum = leftans ;
        maxsum=max(maxsum , leftans + root->val);
        maxsum = max(maxsum , leftans +  root->val + rightans);
        maxsum = max(maxsum , rightans + root->val);
        maxsum = max(maxsum , rightans);
        maxsum = max(maxsum , root->val);
        sum=max(maxsum , sum);
        if(max(leftans , rightans) > 0){
            return root->val + max(leftans , rightans);
        }
        return root->val;
    }
    int maxPathSum(TreeNode* root) {
        // if(root == NULL)return 0;
        int sum = root->val ;
        solve(root , sum);
        return sum;
    }
};