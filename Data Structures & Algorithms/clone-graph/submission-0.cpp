/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void solve(Node*ashu , Node*node , unordered_map<int,Node*>&st)
    {
        for(auto i : node->neighbors)
        {
            if(st.find(i->val)!=st.end()){
                ashu->neighbors.push_back(st[i->val]);
                continue;
            }
            Node*newnode = new Node(i->val);
            st[i->val]=newnode;
            ashu->neighbors.push_back(newnode);
            solve(newnode , i , st);
        }
    }
    Node* cloneGraph(Node* node) {
        if(node==nullptr)return nullptr;
        Node*ashu = new Node(node->val);
        Node*ptr = ashu;
        unordered_map<int,Node*>st;
        st[node->val]=ashu;
        solve(ashu , node , st);
        return ashu;
    }
};
