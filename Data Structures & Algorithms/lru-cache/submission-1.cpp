class LRUCache {
public:
    class Node{
 public:
        int key,val;
         Node*left;
         Node*right;
        //  public:
         Node(int k,int v)
         {
         key=k;
         val=v;
         left=NULL;
         right=NULL;
         }
    };
    int cap;
    unordered_map<int,Node*>cache;
     Node*first=new Node(0,0);
        Node*last=new Node(0,0);
    LRUCache(int capacity) {
        cap=capacity;
       
        first->right=last;
        last->left=first;
        cache.clear();
    }
    void removeNode(Node*curr)
    {
         Node*rightNode=curr->right;
         Node*leftNode=curr->left;
         leftNode->right=rightNode;
         rightNode->left=leftNode;
    }
    void insertNode(Node*curr)
    {
        Node*secondNode=first->right;
        first->right=curr;
        curr->right=secondNode;
        secondNode->left=curr;
        curr->left=first;
    }
    int get(int key) {
        int ans=-1;
     if(cache.find(key)!=cache.end())
     {
        Node*curr=cache[key];
         ans=curr->val;
        removeNode(curr);
        insertNode(curr);
     }   
      return ans;
        
    }
    
    void put(int key, int value) {
        
        if(cache.find(key)!=cache.end())
        {
            removeNode(cache[key]);
          
        }
        Node*newNode= new Node(key,value);
        cache[key]=newNode;
        insertNode(newNode);
        if(cache.size()>cap)
        {
            Node*lru=last->left;
            removeNode(lru);
            cache.erase(lru->key);
            delete lru;
        }
    }
};
