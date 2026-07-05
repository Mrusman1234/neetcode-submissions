class Node {

public:

    int key;

    int value;

    Node* prev;

    Node* next;



    Node(int k, int v) {

        key = k;

        value = v;

        prev = nullptr;

        next = nullptr;

    }

};



class LRUCache {

private:

    int capacity;

    unordered_map<int, Node*> mp;

    Node* head;

    Node* tail;



    void removeNode(Node* node) {

        node->prev->next = node->next;

        node->next->prev = node->prev;

    }



    void insertFront(Node* node) {

        node->next = head->next;

        node->prev = head;



        head->next->prev = node;

        head->next = node;

    }



public:

    LRUCache(int capacity) {



        this->capacity = capacity;



        head = new Node(0, 0);

        tail = new Node(0, 0);



        head->next = tail;

        tail->prev = head;

    }



    int get(int key) {



        if (mp.find(key) == mp.end())

            return -1;



        Node* node = mp[key];



        removeNode(node);

        insertFront(node);



        return node->value;

    }



    void put(int key, int value) {



        if (mp.find(key) != mp.end()) {



            Node* node = mp[key];

            node->value = value;



            removeNode(node);

            insertFront(node);



            return;

        }



        if (mp.size() == capacity) {



            Node* lru = tail->prev;



            removeNode(lru);



            mp.erase(lru->key);



            delete lru;

        }



        Node* newNode = new Node(key, value);



        insertFront(newNode);



        mp[key] = newNode;

    }

};

