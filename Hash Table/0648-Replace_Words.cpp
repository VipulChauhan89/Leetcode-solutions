class Solution {
public:
    struct TrieNode 
    {
        bool flag;
        unordered_map<char,TrieNode*> children;
        TrieNode():flag(false) {}
    };
    void insert(TrieNode *root,const string &word) 
    {
        TrieNode *cur=root;
        for(auto c:word) 
        {
            if(cur->children.find(c)==cur->children.end())
            {
                cur->children[c]=new TrieNode();
            } 
            cur=cur->children[c];
        }
        cur->flag=true;
    }
    string replace(TrieNode *root,const string &word) 
    {
        TrieNode *cur=root;
        string res="";
        for(auto c:word) 
        {
            if(cur->children.find(c)==cur->children.end())
            {
                return word;
            }
            cur=cur->children[c];
            res+=c;
            if(cur->flag==true)
            {
                return res;
            }
        }
        return word;
    }
    string replaceWords(vector<string> &dictionary,string sentence) 
    {
        TrieNode *root=new TrieNode();
        for(auto word:dictionary)
        {
            insert(root,word);
        } 
        string res="";
        stringstream iss(sentence);
        string word;
        while(iss>>word) 
        {
            if(!res.empty())
            {
                res+=" ";
            } 
            res+=replace(root,word);
        }
        return res;   
    }
};
