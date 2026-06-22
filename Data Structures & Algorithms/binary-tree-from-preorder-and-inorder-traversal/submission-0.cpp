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
    TreeNode*solve(vector<int>&preorder , unordered_map<int,int>&mp, int &ind , int left , int right)
    {
        if(left > right)return NULL;
        int val = preorder[ind++];
        TreeNode*curr = new TreeNode(val);
        int mid = mp[val];
        // int diff = ind - mid;
        curr->left = solve(preorder , mp , ind , left, mid-1);
        curr->right = solve(preorder , mp, ind , mid+1 , right);
        return curr;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>mp;
        int n = preorder.size();
        for(int i = 0 ; i < n ; i++)
        {
            mp[inorder[i]]=i;
        }
        int ind = 0;
        int left = 0 ;
        int right = n-1;
        return solve(preorder , mp ,  ind , left , right);
    }
};