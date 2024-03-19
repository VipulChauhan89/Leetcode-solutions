class Solution {
public:
    int leastInterval(vector<char> &tasks,int n) 
    {
        vector<int> f(26,0);
        for(auto i:tasks)
        {
            f[i-'A']++;
        }    
        sort(f.begin(),f.end(),greater<int>());
        int mxF=f[0];
        int it=(mxF-1)*n;
        for(int i=1;i<f.size() && f[i]>0;i++)
        {
            it-=min(f[i],mxF-1);
        }
        it=max(0,it);
        return tasks.size()+it;
    }
};
