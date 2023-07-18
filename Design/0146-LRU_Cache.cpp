class Node{
public:
    int key,val;
    Node *next,*prev;
    Node(int key,int val)
    {
        this->key=key;
        this->val=val;
        next=NULL;
        prev=NULL;
    }
};
class LRUCache {
public:
    unordered_map<int,Node*> m;
    Node *head=new Node(-1,-1);
    Node *tail=new Node(-1,-1);
    int capacity;
    LRUCache(int capacity) 
    {
        this->capacity=capacity;
        head->next=tail;
        tail->prev=head;
    }
    void deleteNode(Node *node)
    {
        Node *prev=node->prev;
        Node *next=node->next;
        prev->next=next;
        next->prev=prev;
    }
    void addNode(Node * node)
    {
        Node *temp=head->next;
        head->next=node;
        node->prev=head;
        node->next=temp;
        temp->prev=node;
    }
    int get(int key) 
    {
        if(m.find(key)==m.end())
        {
            return -1;
        }
        Node *p=m[key];
        deleteNode(p);
        addNode(p);
        m[key]=head->next;
        return head->next->val;
    }
    
    void put(int key,int value) 
    {
        if(m.find(key)!=m.end())
        {
            Node *c=m[key];
            deleteNode(c);
            c->val=value;
            addNode(c);
            m[key]=head->next;
        }
        else
        {
            if(m.size()==capacity)
            {
                Node *prev=tail->prev;
                deleteNode(prev);
                Node *l=new Node(key,value);
                addNode(l);
                m.erase(prev->key);
                m[key]=head->next;
            }
            else
            {
                Node *l=new Node(key,value);
                addNode(l);
                m[key]=head->next; 
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
