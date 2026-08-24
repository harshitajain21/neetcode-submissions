class Node {
public:
    int key;
    int val;
    Node* prev;
    Node* next;

    Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {
    }
};

class LRUCache {

private:
    int cap;
    unordered_map<int, Node*> cache; //hashmap
    Node* left;
    Node* right;

public:

    void remove(Node* node) {
        Node* prev = node->prev;
        Node* nxt = node->next;
        prev->next = nxt;
        nxt->prev = prev;
    }

    void insert(Node* node) {
        Node* prev = right->prev;
        prev->next = node;
        node->prev = prev;
        node->next = right;
        right->prev = node;
    }
    
    LRUCache(int capacity) {
        cap = capacity;
        cache.clear(); //remove anything from hashmap

        //initialize double linked list->
        left = new Node(0, 0); 
        right = new Node(0, 0);
        left->next = right;
        right->prev = left;
        
    }
    
    int get(int key) {

        if (cache.find(key) != cache.end()) { //if key found
            Node* node = cache[key];
            remove(node);
            insert(node);
            return node->val;
        }
        return -1;
    }
    
    void put(int key, int value) {

        if (cache.find(key) != cache.end()) { //if key found, just remove it from cache
            remove(cache[key]);
        }

        //make new key-value pair in cache..in both cases: whether key is found  or not
        Node* newNode = new Node(key, value);
        cache[key] = newNode;
        insert(newNode);

        if (cache.size() > cap) { //exceeding capacity : remove first key
            
            Node* lru = left->next; //left mtlb first
            remove(lru); //remove from linkedlist
            cache.erase(lru->key); //remove from hashmap
            delete lru; //delete this node
        }

        
    }
};
