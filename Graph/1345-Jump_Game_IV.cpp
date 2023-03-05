class Solution {
public:
    int minJumps(vector<int>&arr) 
    {
        vector<bool>reached_index(arr.size(),false);
        unordered_map<int,vector<int>>index_of_val;
        for(int i=0;i<arr.size();i++)
        {
            index_of_val[arr[i]].push_back(i);
        }
        queue<int>to_reach;
        to_reach.push(0);
        reached_index[0]=true;
        int steps=0;
        while(!to_reach.empty())
        {
            int n=to_reach.size();
            while(n--)
            {
                int x=to_reach.front();
                if(x==arr.size()-1)
                {
                    return steps;
                }
                to_reach.pop();
                for(auto j:index_of_val[arr[x]])
                {
                    if(!reached_index[j])
                    {
                        to_reach.push(j);
                        reached_index[j]=true;
                    }
                }
                if((x-1)>0 && !reached_index[x-1])
                {
                    to_reach.push(x-1);
                    reached_index[x-1]=true;
                }
                if((x+1)<arr.size() && !reached_index[x+1])
                {
                    to_reach.push(x+1);
                    reached_index[x+1]=true;
                }
                index_of_val[arr[x]].clear();
            }
            steps++;
        }
        return arr.size()-1;
    }
};