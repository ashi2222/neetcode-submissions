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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>vec;
        if(root==NULL)return vec;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            vector<int>ans;
            int n = q.size();
            for(int i = 0 ; i < n ; i++)
            {
                auto j = q.front();
                q.pop();
                ans.push_back(j->val);
                if(j->left){
                    q.push(j->left);
                }
                if(j->right){
                    q.push(j->right);
                }
            }
            vec.push_back(ans);
        }
        return vec;
    }
};
