class Node{

public:
  int key;
  int val;
  Node*prev;
  Node*next;
  Node(int k,int v)
  {
       key=k;
       val=v;
       prev=NULL;
       next=NULL;
  }
};

class LRUCache {
    int cap;
    unordered_map<int,Node*>cache;
    Node*left;
    Node*right;
public:
    
    // umordered_map<int,int>mp;   

    LRUCache(int capacity) {
       
       cap=capacity;
       cache.clear();
       left=new Node(0,0);
       right=new Node(0,0);
       left->next=right;
       right->prev=left;
         
    }
    
    int get(int key) {
        
        if(cache.find(key)!=cache.end())
        {
            Node*node=cache[key];
            remove(node);
            insert(node);
            return node->val;
        }

        return -1;

    }
    void insert(Node*node)
    {
        Node*mru=right->prev;
        mru->next=node;
        node->prev=mru;
        right->prev=node;
        node->next=right;
    }
    void remove(Node*node)
    {
        Node*node1=node->prev;
        Node*node2=node->next;
        node1->next=node2;
        node2->prev=node1;
    }    
    void put(int key, int value) {
        
        if(cache.find(key)!=cache.end())
        {
            remove(cache[key]);
        }
        Node*newNode=new Node(key,value);
        cache[key]=newNode;
        insert(newNode);
        if(cache.size()>cap)
        {
            Node*lru=left->next;
            remove(lru);
            cache.erase(lru->key);
            delete lru;
        }
    }
};
