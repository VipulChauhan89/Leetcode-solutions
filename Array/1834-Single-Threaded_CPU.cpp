class Solution {
public:
    static int comp(vector<int>& v1,vector<int>& v2)
    {
        return v1[0]<v2[0];
    }
    typedef pair<int,int> pr;
    vector<int> getOrder(vector<vector<int>>& tasks) 
    {
        vector<int>ans;
        long long int prestime=1;
        priority_queue<pr,vector<pr>,greater<pr>> pq;
        int n=tasks.size();
        if(n==0)
        {
            return ans;
        }
        for(int i=0;i<n;i++) 
        {
            tasks[i].push_back(i);   
        }   
        sort(tasks.begin(),tasks.end(),comp);
        int i=0;
        while(i<n || !pq.empty())
        {
            int flag1=0,flag2=0;
            while(i<n && prestime>=tasks[i][0])  
            {                                   
                pq.push(make_pair(tasks[i][1],tasks[i][2])); 
                i++;                                         
                flag1=1;
            }
            if(!pq.empty())     
            {                   
                auto it=pq.top();
                pq.pop();
                prestime+=it.first;
                flag2=1;
                ans.push_back(it.second);
            }
            if(!flag1 && !flag2) 
            {
                prestime=tasks[i][0]; 
            } 
        }
        return ans;
    }
};
