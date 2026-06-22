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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        string ans = "";
        while(!q.empty())
        {
            int n = q.size();
            for(int i = 0 ; i < n ; i++)
            {
                auto it = q.front();
                q.pop();
                if(it==NULL){
                    ans+="#";
                }
                else{
                    ans += to_string(it->val);
                    q.push(it->left);
                    q.push(it->right);
                }
                ans+=",";
            }
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string str) {
        string s ;
        int i = 0 ;
        stringstream data(str);
        getline(data , s , ',');
        if(s=="#")return NULL;
        TreeNode*root = new TreeNode(stoi(s));
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int n = q.size();
            {
                auto it = q.front();
                q.pop();
                getline(data , s ,',');
                if(s!="#")
                {
                    it->left = new TreeNode(stoi(s));
                    q.push(it->left);
                }
                getline(data, s , ',');
                if(s!="#")
                {
                    it->right = new TreeNode(stoi(s));
                    q.push(it->right);
                }
            }
        }
        return root;
    }
};
