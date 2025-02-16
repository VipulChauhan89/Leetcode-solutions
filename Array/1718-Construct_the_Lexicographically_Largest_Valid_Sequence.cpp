class Solution {
public:
    bool backtrack(vector<int> &ans,vector<bool> &visited,int n,int index)
    {
        int sz=ans.size();
        while(index<sz && ans[index]!=0)
        {
            index++;
        }
        if(index==sz)
        {
            return true;
        }
        for(int i=n;i>=1;i--)
        {
            if(visited[i])
            {
                continue;
            }
            if(i==1)
            {
                ans[index]=1;
                visited[1]=true;
                if(backtrack(ans,visited,n,index+1))
                {
                    return true;
                }
                ans[index]=0;
                visited[1]=false;
            }
            else if(index+i<sz && ans[index+i]==0)
            {
                ans[index]=i;
                ans[index+i]=i;
                visited[i]=true;
                if(backtrack(ans,visited,n,index+1))
                {
                    return true;
                }
                ans[index]=0;
                ans[index+i]=0;
                visited[i]=false;
            }
        }
        return false;
    }
    vector<int> constructDistancedSequence(int n) 
    {
        vector<int> ans(2*n-1,0);
        vector<bool> visited(n+1,false);
        backtrack(ans,visited,n,0);
        return ans;
    }
};
