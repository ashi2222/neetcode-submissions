class dll{
    public:
    int key;
    int val;
    dll*next;
    dll*prev;

    dll(int key , int val){
        this->key = key;
        this->val=val;
        this->next=NULL;
        this->prev=NULL;
    }
};


class LRUCache {
public:
    dll*front;
    dll*back;
    int size;
    unordered_map<int,dll*>mp;
    LRUCache(int capacity) {
        size = capacity;
        front=new dll(-1,-1);
        back=new dll(-1,-1);
        front->next=back;
        back->prev=front;
    }

    ~LRUCache() {
        dll* curr = front;
        while (curr != nullptr) {
            dll* nextNode = curr->next;
            delete curr;
            curr = nextNode;
        }
    }

    void insertatfirst(dll*node){
        dll*prevfirst = front->next;
        node->next=prevfirst;
        node->prev=front;
        front->next=node;
        prevfirst->prev=node;
    }

    void removenode(dll*node){
        dll*prevnode = node->prev;
        dll*nextnode= node->next;
        prevnode->next = nextnode;
        nextnode->prev=prevnode;
    }
    

    int get(int key) {
        if(mp.find(key)!=mp.end()){
            dll*node = mp[key];
            removenode(node);
            insertatfirst(node);
            return node->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end())
        {
            dll*removed = mp[key];
            removed->val = value;
            removenode(removed);
            insertatfirst(removed);
            return;
            // size++;
        }
        if(size == 0)
        {
            dll*removed = back->prev;
            mp.erase(removed->key);
            removenode(removed);
            delete removed;
            size++;
        }
        
        dll*node = new dll(key , value);
        insertatfirst(node);
        mp[key]=node;
        size--;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */