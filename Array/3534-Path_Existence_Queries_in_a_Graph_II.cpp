class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<pair<int,int>> nodes;
        nodes.reserve(n);
        for (int i=0;i<n;i++)
        {
            nodes.push_back({nums[i],i});
        }
        sort(nodes.begin(),nodes.end());
        vector<int> pos(n),values(n);
        for(int i=0;i<n;i++)
        {
            values[i]=nodes[i].first;
            pos[nodes[i].second]=i;
        }
        int LOG=1;
        while((1<<LOG)<=n)
        {
            ++LOG;
        }
        vector<vector<int>> jump(LOG,vector<int>(n));
        int r=0;
        for(int i=0;i<n;i++)
        {
            if(r<i)
            {
                r=i;
            }
            while(r+1<n && values[r+1]-values[i]<=maxDiff)
            {
                r++;
            }
            jump[0][i]=r;
        }
        for(int p=1;p<LOG;p++)
        {
            for(int i=0;i<n;i++)
            {
                jump[p][i]=jump[p-1][jump[p-1][i]];
            }
        }
        vector<int> answer;
        answer.reserve(queries.size());
        for(auto &query:queries)
        {
            int left=pos[query[0]],right=pos[query[1]];
            if(left>right)
            {
                swap(left,right);
            }
            if(left==right)
            {
                answer.push_back(0);
                continue;
            }
            int current=left,distance=0;
            for(int p=LOG-1;p>=0;p--)
            {
                if(jump[p][current]<right)
                {
                    current=jump[p][current];
                    distance+=(1<<p);
                }
            }
            if(jump[0][current]>=right)
            {
                answer.push_back(distance+1);
            }
            else
            {
                answer.push_back(-1);
            }
        }
        return answer;
    }
};
