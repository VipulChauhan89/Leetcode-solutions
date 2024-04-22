class Solution {
public:
    int openLock(vector<string> &deadends,string target) 
    {
        unordered_set<string> dS(deadends.begin(),deadends.end());
        if(dS.count("0000"))
        {
            return -1;
        }
        queue<pair<string,int>> q;
        q.push({"0000",0});
        unordered_set<string> visited;
        visited.insert("0000");
        while(!q.empty())
        {
            auto current=q.front();
            q.pop();
            string curr=current.first;
            int m=current.second;
            if(curr==target)
            {
                return m;
            }
            for(int i=0;i<4;i++)
            {
                for(int d:{-1,1})
                {
                    int n=(curr[i]-'0'+d+10)%10;
                    string newCurr=curr;
                    newCurr[i]='0'+n;
                    if(visited.find(newCurr)==visited.end() && dS.find(newCurr)==dS.end())
                    {
                        visited.insert(newCurr);
                        q.push({newCurr,m+1});
                    }
                }
            }
        }
        return -1;
    }
};
