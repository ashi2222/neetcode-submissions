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
    int kthSmallest(TreeNode* root, int k) {
        if(root==NULL)return 0;
        stack<TreeNode*>st;
        st.push(root);
        TreeNode*curr = root;
        int count = 0 ;
        while(!st.empty())
        {
            TreeNode*dummy=curr;
            while(curr){
                st.push(curr);
                dummy=curr;
                curr=curr->left;
            }
            auto it = st.top();
            st.pop();
            count++;
            if(count == k)return it->val;
            curr=it->right;
        }
        return 0;
    }
};