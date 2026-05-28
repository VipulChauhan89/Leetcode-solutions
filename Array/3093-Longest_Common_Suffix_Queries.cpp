class Solution {
public:
    struct Node
    {
        int bestIdx;
        array<int,26> children;
        Node():bestIdx(0)
        {
            fill(children.begin(),children.end(),-1);
        }
    };
    vector<Node> trie;
    vector<int> stringIndices(vector<string> &wordsContainer,vector<string> &wordsQuery)
    {
        trie.emplace_back();
        int rootIdx=0;
        for(int i=0;i<wordsContainer.size();i++)
        {
            const string &w=wordsContainer[i];
            int node=rootIdx;
            if(wordsContainer[trie[node].bestIdx].size()>w.size())
            {
                trie[node].bestIdx=i;
            }
            for(int j=w.size()-1;j>=0;j--)
            {
                int c=w[j]-'a';
                int next=trie[node].children[c];
                if(next==-1)
                {
                    next=trie.size();
                    trie.emplace_back();
                    trie[node].children[c]=next;
                    trie[next].bestIdx=i;
                }
                else
                {
                    if(wordsContainer[trie[next].bestIdx].size()>w.size())
                    {
                        trie[next].bestIdx=i;
                    }
                }
                node=next;
            }
        }
        vector<int> ans(wordsQuery.size());
        for(int i=0;i<wordsQuery.size();i++)
        {
            const string &q=wordsQuery[i];
            int node=rootIdx;
            for(int j=q.size()-1;j>=0;j--)
            {
                int c=q[j]-'a';
                int next=trie[node].children[c];
                if(next==-1)
                {
                    break;
                }
                node=next;
            }
            ans[i]=trie[node].bestIdx;
        }
        return ans;
    }
};
