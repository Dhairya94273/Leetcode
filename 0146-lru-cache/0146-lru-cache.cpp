class LRUCache {
public:
    class Node {
    public:
        int key, val;
        Node *prev, *next;

        Node(int k, int v) {
            key = k;
            val = v;
            prev = next = NULL;
        }
    };

    Node *head, *tail;
    unordered_map<int, Node*> m;
    int capacity;
    
    void addNode(Node *newNode) {//O(1)
        Node *temp = head->next;

        //Add Node after head because it is the Most Recently Used(MRU)
        newNode->next = temp;
        newNode->prev = head;

        head->next = newNode;
        temp->prev = newNode;
    }
    
    void delNode(Node *node) {//O(1)
        Node *prevNode = node->prev;
        Node *nextNode = node->next;

        //Connect previous node with next node
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    LRUCache(int capacity) {
        this->capacity = capacity;

        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {//O(1)

        //If key is not present then return -1
        if (m.find(key) == m.end())
            return -1;

        Node *node = m[key];

        //When we access any key it becomes Most Recently Used(MRU)
        delNode(node);
        addNode(node);

        return node->val;
    }

    void put(int key, int value) {//O(1)

        //If key already exists then delete the old node
        if (m.find(key) != m.end()) {

            Node *existing = m[key];

            delNode(existing);
            m.erase(key);
            delete existing;
        }

        //If cache is full then remove Least Recently Used(LRU) node
        if (m.size() == capacity) {

            Node *lru = tail->prev;

            m.erase(lru->key);
            delNode(lru);
            delete lru;
        }

        //Insert new node at front because it is now MRU
        Node *newNode = new Node(key, value);

        addNode(newNode);

        m[key] = newNode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */