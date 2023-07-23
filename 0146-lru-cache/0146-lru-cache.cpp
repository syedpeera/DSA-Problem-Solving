class LRUCache {
private:
    struct Node{
        int key;
        int value;
        Node* next;
        Node* prev;
        Node(int k, int v){
            key = k;
            value = v;
            next = nullptr;
            prev = nullptr;
        }
    };
    
    unordered_map<int, Node*> cache;
    int capacity;
    Node* head;
    Node* tail;
    
    void addToFront(Node* node){
        node->next = head->next;
        node->prev = head;
        head->next = node;
        node->next->prev = node;
    }
    
    void removeNode(Node* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    
public:
    
    LRUCache(int cap) {
        capacity = cap;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(cache.find(key) != cache.end()){
            Node* node = cache[key];
            removeNode(node);
            addToFront(node);
            return node->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(cache.find(key) != cache.end()){
            Node* node = cache[key];
            node->value = value;
            removeNode(node);
            addToFront(node);
        }
        else{
            if(cache.size() >= capacity){
                Node* nodeToRemove = tail->prev;
                removeNode(nodeToRemove);
                cache.erase(nodeToRemove->key);
                delete nodeToRemove;
            }
            Node* newNode = new Node(key, value);
            addToFront(newNode);
            cache[key] = newNode;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */