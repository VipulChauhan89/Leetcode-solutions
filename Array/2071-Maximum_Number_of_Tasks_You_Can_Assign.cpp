class Solution {
public:
    int maxTaskAssign(vector<int> &tasks,vector<int> &workers,int pills,int strength) 
    {
        int l=0,r=min(tasks.size(),workers.size());
        sort(tasks.begin(),tasks.end());
        sort(workers.begin(),workers.end());
        while(l<r)
        {
            int mid=(l+r+1)/2,used=0;
            multiset<int> workersF(workers.end()-mid,workers.end());
            bool canAssign=true;
            for(int i=mid-1;i>=0;i--)
            {
                auto it=prev(workersF.end());
                if(*it<tasks[i])
                {
                    it=workersF.lower_bound(tasks[i]-strength);
                    if(it==workersF.end())
                    {
                        canAssign=false;
                        break;
                    }
                    ++used;
                    if(used>pills)
                    {
                        canAssign=false;
                        break;
                    }
                }
                workersF.erase(it);
            }
            if(canAssign)
            {
                l=mid;
            }
            else
            {
                r=mid-1;
            }
        }
        return l;
    }
};
