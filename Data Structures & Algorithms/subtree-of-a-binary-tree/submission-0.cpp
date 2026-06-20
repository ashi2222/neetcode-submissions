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
    bool isEqual(TreeNode*a , TreeNode*b)
    {
        if(a==NULL && b==NULL)return true;
        if(a!=NULL && b==NULL)return false;
        if(a==NULL && b!=NULL)return false;
        bool leftans = isEqual(a->left , b->left);
        bool rightans= isEqual(a->right, b->right);
        if(a->val == b->val && leftans && rightans)return true;
        return false;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL && subRoot == NULL)return true;
        if(root==NULL && subRoot != NULL)return false;
        if(root!=NULL && subRoot==NULL)return true;
        bool leftans = isSubtree(root->left , subRoot);
        bool rightans = isSubtree(root->right , subRoot);
        if(leftans or rightans)return true;
        return isEqual(root,subRoot);
    }
};
