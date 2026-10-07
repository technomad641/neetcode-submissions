struct node {
    int val;
    node* prev;
    node* next;

    node(int x) {
        val = x;
        prev = NULL;
        next = NULL;
    }
};

class LRUCache {
public:

    map<int, int> m;
    map<int, node*> mapping;

    node* head;
    node* tail;

    int c;

    LRUCache(int capacity) {

        c = capacity;

        head = new node(-1);
        tail = new node(-1);

        head->next = tail;
        tail->prev = head;
    }

    // Insert immediately after head
    void insertLL(node* p) {

        p->next = head->next;
        p->prev = head;

        head->next->prev = p;
        head->next = p;
    }

    // Remove node
    void deleteLL(node* p) {

        p->prev->next = p->next;
        p->next->prev = p->prev;

        delete p;
    }

    int get(int key) {

        if (m.find(key) == m.end()) {
            return -1;
        }

        int val = m[key];

        // Remove old node
        node* p = mapping[key];
        deleteLL(p);

        // Insert it at MRU position
        node* newNode = new node(key);
        insertLL(newNode);

        mapping[key] = newNode;

        return val;
    }

    void put(int key, int value) {

        // Key already exists
        if (m.find(key) != m.end()) {

            // Update value
            m[key] = value;

            // Remove old node
            node* p = mapping[key];
            deleteLL(p);

            // Move to MRU
            node* newNode = new node(key);
            insertLL(newNode);

            mapping[key] = newNode;

            return;
        }

        // Cache is full
        if (m.size() == c) {

            // LRU is immediately before tail
            node* lru = tail->prev;

            int evictedKey = lru->val;

            deleteLL(lru);

            m.erase(evictedKey);
            mapping.erase(evictedKey);
        }

        // Insert new key
        m[key] = value;

        node* newNode = new node(key);
        insertLL(newNode);

        mapping[key] = newNode;
    }
};