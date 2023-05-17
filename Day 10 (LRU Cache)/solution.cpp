/*
We use doubly linked list and update it to figure out the least recently used key.
We use a hash table with node as a value so we can access that node in linked list in O(1) time
*/

class Node {
    public:
        int key, value;
        Node *prev, *next;

        Node(int key, int value)
        {
            this->key = key;
            this->value = value;
            prev = next = NULL;
        }
};


class LRUCache {
private:
    unordered_map<int, Node *> m;
    Node *head, *tail;
    int capacity;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(-1, -1); //dummy head and tail to prevent edge cases
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    void append(Node *newNode)
    {
        newNode->prev = tail->prev;
        newNode->next = tail;
        tail->prev->next = newNode;
        tail->prev = newNode;
    }

    void remove(Node *node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    
    int get(int key) {
        if (m.find(key) != m.end())
        {
            remove(m[key]);
            append(m[key]);
            return m[key]->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        
        if (m.find(key) != m.end())
        {
            remove(m[key]);
            m[key]->value = value;
            append(m[key]);
            
        }
        else
        {
            if (m.size() == capacity)
            {
                m.erase(head->next->key);
                remove(head->next);
            }

            Node *newNode = new Node(key, value);
            append(newNode);
            m[key] = newNode;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */