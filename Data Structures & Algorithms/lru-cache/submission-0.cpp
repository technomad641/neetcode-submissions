class LRUCache {
public:
    struct Node {
        Node* next;
        Node* prev;
        int key;
        int val;

        Node(int k, int v) {
            key = k;
            val = v;
            next = NULL;
            prev = NULL;
        }
    };

    int C;
    Node* head;
    Node* tail;
    unordered_map<int, Node*> cache;

    LRUCache(int capacity) {
        C = capacity;

        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        head->prev = NULL;

        tail->prev = head;
        tail->next = NULL;
    }

    // Remove node from linked list
    void remove_update(Node* A) {
        Node* N = A->next;
        Node* P = A->prev;

        P->next = N;
        N->prev = P;

        cache.erase(A->key);

        delete A;
    }

    // Put node immediately after head
    void update_head(Node* A) {
        Node* N = head->next;

        head->next = A;
        A->prev = head;

        A->next = N;
        N->prev = A;
    }

    int get(int key) {
        if (cache.find(key) == cache.end())
            return -1;

        Node* reference = cache[key];
        int value = reference->val;

        // Remove old node
        remove_update(reference);

        // Create new MRU node
        Node* newNode = new Node(key, value);
        update_head(newNode);

        cache[key] = newNode;

        return value;
    }

    void put(int key, int value) {

        // Case 1: key already exists
        if (cache.find(key) != cache.end()) {

            Node* oldNode = cache[key];

            remove_update(oldNode);

            Node* newNode = new Node(key, value);
            update_head(newNode);

            cache[key] = newNode;

            return;
        }

        // Case 2: cache is full
        if (cache.size() == C) {

            Node* lru = tail->prev;

            // Remove LRU key from hashmap
            cache.erase(lru->key);

            // Remove LRU node from linked list
            remove_update(lru);
        }

        // Add new node as MRU
        Node* newNode = new Node(key, value);
        update_head(newNode);

        cache[key] = newNode;
    }
};