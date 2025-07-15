class LRUCache {
public:
    class Node {
    public:
        int key, value;
        Node* prev;
        Node* next;
        Node(int k, int v) {
            key = k;
            value = v;
            prev = next = nullptr;
        }
    };
   Node* head=new Node(-1,-1);
   Node* tail=new Node(-1,-1);

   unordered_map<int, Node*> mp;

   int limit;

    LRUCache(int capacity) {
        limit=capacity;
        head->next=tail;
        tail->prev=head;
    }

    void insert(Node* node){
        node->next=head->next;
        node->prev=head;
        head->next->prev=node;
        head->next=node;
    }
    void remove(Node* node){
        node->prev->next=node->next;
        node->next->prev=node->prev;
    }

    int get(int key) {

        if(mp.find(key)!=mp.end()){
             Node* node=mp[key];
             remove(node);
             insert(node);

           return node->value;
        }
        else
        return -1;


    }

    void put(int key, int value) {
    
      if(mp.find(key)!=mp.end()){
        Node* oldNode=mp[key];
        remove(oldNode);
        mp.erase(key);

      }
      if(mp.size()==limit){
 
         mp.erase(tail->prev->key);
         remove(tail->prev);

      }

       Node* node=new Node(key,value);
       insert(node);
       mp[key]=node;

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */