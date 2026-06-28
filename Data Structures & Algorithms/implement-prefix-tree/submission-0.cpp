class Trie{
    public:
    vector<Trie*>child;
    bool isend ;
    Trie(){
        child.resize(26 , nullptr);
        isend = false;
    }
};


class PrefixTree {
    private:
    Trie*node;
    Trie*ptr ;
public:
    PrefixTree() {
        node = new Trie();
        ptr = node;
    }
    
    void insert(string word) {
        node = ptr;
        for(auto i : word)
        {
            if(node->child[i-'a']==nullptr){
               node->child[i-'a'] = new Trie();
            }
            node = node->child[i-'a'];
        }
        node->isend = true;
   }
    
    bool search(string word) {
        node = ptr;
        for(auto i : word){
            if(node->child[i-'a'] == nullptr)return false;
            node = node->child[i-'a'];
        }
        return node->isend;
    }
    
    bool startsWith(string prefix) {
        node = ptr;
        for(auto i : prefix){
            if(node->child[i-'a'] == nullptr)return false;
            node = node->child[i-'a'];
        }
        return true;
    }

    virtual ~PrefixTree()=default;
};
