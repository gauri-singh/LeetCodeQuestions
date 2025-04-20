class Node{
    public:
    Node* next;
    int key;
    Node(int k): key(k), next(nullptr){}
};
class MyHashSet {
private:
int hashFunction(int key){
    return key%hashSet.size();
}
public:
vector<Node*> hashSet;
    MyHashSet() {
        hashSet.resize(10000);
        //initialize each bucket with a dummy node;
        for(auto& bucket : hashSet){
            bucket= new Node(0);
        }
    }
    
    void add(int key) {
        int hash=hashFunction(key);
        Node* curr= hashSet[hash];
        while(curr->next){
            if(curr->next->key==key){
                return;
            }
            curr=curr->next;
        }
        curr->next=new Node(key);
    }
    
    void remove(int key) {
        int hash=hashFunction(key);
        Node* curr= hashSet[hash];
        while(curr->next){
            if(curr->next->key==key){
                Node* temp = curr->next;
                curr->next = temp->next;
                delete temp;
                return;
            }
            curr=curr->next;
        }
    }
    
    bool contains(int key) {
        int hash=hashFunction(key);
        Node* curr= hashSet[hash];
        while(curr->next){
            if(curr->next->key==key){
                return true;
            }
            curr=curr->next;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */