class dsu{
    vector<int>parent;
    int n;
    vector<int>rank;
    public:
    dsu(int n)
    {
        this->n = n;
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i =1 ; i <= n ; i++)
        {
            parent[i]=i;
        }
    }

    bool unionparent(int u , int v)
    {
        int pu = findparent(u);
        int pv = findparent(v);
        if(pu == pv)return false;
        if(rank[pu] == rank[pv])
        {
            rank[pu]++;
            parent[pv] = pu;
        }
        else if(rank[pu] > rank[pv])
        {
            parent[pv] = pu;
        }
        else{
            parent[pu]=pv;
        }
        return true;
    }
    int findparent(int u)
    {
        int v = u ;
        while(parent[v]!=v)
        {
            v = parent[v];
        }
        return parent[u] = v;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        dsu*ds= new dsu(n);
        for(auto i : edges)
        {
            if(!(ds->unionparent(i[0] , i[1])))return {i[0] , i[1]};
        }
        delete ds;
        return {0,0};
    }
};
