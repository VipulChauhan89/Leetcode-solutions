class Solution {
public:
    typedef struct Node
    {
        string name="";
        map<string,Node*> child;
        bool deleted=false;
        Node(string n)
        {
            name=n;
        }
    } Node;
    unordered_map<string,Node*> seen;
    void insert(Node *current,vector<string> &path)
    {
        for(int i=0;i<path.size();i++)
        {
            if(current->child.count(path[i])==0)
            {
                current->child[path[i]]=new Node(path[i]);
            }
            current=current->child[path[i]];
        }
    }
    void build(Node* root,vector<vector<string>> &paths)
    {
        for(int i=0;i<paths.size();i++)
        {
            insert(root,paths[i]);
        }
    }
    string traverse(Node *root)
    {
        string subfolder="";
        for(auto &i:root->child)
        {
            subfolder+=traverse(i.second);
        }
        if(subfolder!="")
        {
            if(seen.find(subfolder)==seen.end())
            {
                seen[subfolder]=root;
            }
            else
            {
                root->deleted=true;
                seen[subfolder]->deleted=true;
            }
        }
        return "("+root->name+subfolder+")";
    }
    void getPath(Node *root,vector<string> &path,vector<vector<string>> &ans)
    {
        if(root->deleted==true)
        {
            return;
        } 
        path.push_back(root->name);
        ans.push_back(path);
        for(auto &i:root->child)
        {
            getPath(i.second,path,ans);
        }
        path.pop_back();
    }
    vector<vector<string>> solve(Node *root)
    {
        vector<vector<string>> ans;
        vector<string> path;
        for(auto &i:root->child)
        {
            getPath(i.second,path,ans);
        }
        return ans;
    }
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>> &paths)
    {
        Node* root=new Node("");
        build(root,paths);
        traverse(root);
        return solve(root);
    }
};
