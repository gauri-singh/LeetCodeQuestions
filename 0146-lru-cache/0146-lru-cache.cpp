class Node{
    public:
    int key,val;
    Node* prev;
    Node* next;
    Node(int k,int v): key(k),val(v),next(nullptr),prev(nullptr){}
};
class LRUCache {
private:
    int cap;
    unordered_map<int,Node*> cache;
    Node* left;
    Node* right;
    //remove from list
    void remove(Node* node){
        Node* next = node->next;
        Node* prev = node-> prev;
        // remove the current node
        next->prev = prev;
        prev->next = next;
    }
    //insert at right
    void insert(Node* node){
        Node* prev = right->prev;
        node->next = right; node->prev = prev; // connecting pointers of current node
        //inserting this current node between left and right
        prev->next = node;
        right->prev = node;
    }
public:
    LRUCache(int capacity) {
        cap=capacity;
        cache.clear();
        left= new Node(0,0); // dummy nodes for anchors
        right= new Node(0,0);
        left->next=right; // new nodes will be inserted between left and right
        right->prev= left;
    }
    
    int get(int key) {
        if(cache.count(key)){
            // make this node recently used again
            remove(cache[key]);
            insert(cache[key]);
            return(cache[key]->val);
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(cache.count(key)){
            //delete the existing node from list
            remove(cache[key]);
        }
        Node* node = new Node(key,value);
        cache[key]=node; // update ( or insert for the first time) the node to the hash map;
        insert(node);
        //after inserting if the size has gone out of bounds
        if(cache.size()>cap){
            Node* LRU= left->next;
            remove(LRU);
            cache.erase(LRU->key);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */