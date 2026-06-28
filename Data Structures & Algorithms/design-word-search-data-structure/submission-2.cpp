class Trie{
    public:
    vector<Trie*>child;
    bool isend ;
    Trie(){
        child.resize(26 , nullptr);
        isend = false;
    }
};

class WordDictionary {
    Trie*node;
    Trie*ptr;
public:
    WordDictionary() {
        node = new Trie();
        ptr = node;
    }
    
    void addWord(string word) {
        node = ptr;
        for(auto i : word){
            if(node->child[i-'a'] == nullptr){
                node->child[i-'a'] = new Trie();
            }
            node = node->child[i-'a'];
        }
        node->isend = true;
    }
    bool solve(int i , int n , string &word){
        if(i>=word.size()){
            return node->isend;
        }
        if(word[i]=='.'){
            for(int j = 0 ; j < 26 ; j++){
                if(node->child[j]!=nullptr){
                    Trie*saveptr = node;                    
                    node = node->child[j];
                    bool ans = solve(i+1 , n , word);
                    node = saveptr;
                    if(ans)return ans;
                }
            }
        }
        else{
            if(node->child[word[i]-'a']==nullptr)return false;
            node = node->child[word[i]-'a'];
            return solve(i+1 , n , word);
        }
        return false;
    }
    bool search(string word) {
        node = ptr;
        int n =word.size();
        return solve(0 , n , word);
    }
};
