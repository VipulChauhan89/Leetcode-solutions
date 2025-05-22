class Solution {
public:
    int maxRemoval(vector<int> &nums,vector<vector<int>> &queries) 
    {
        sort(queries.begin(),queries.end());
        priority_queue<int> a1;
        priority_queue<int,vector<int>,greater<int>> a2;
        int count=0;
        for(int i=0,k=0;i<nums.size();i++) 
        {
            while(!a2.empty() && a2.top()<i)
            {
                a2.pop();
            }
            while(k<queries.size() && queries[k][0]<=i)
            {
                a1.push(queries[k++][1]);
            } 
            while(a2.size()<nums[i] && !a1.empty() && a1.top()>=i) 
            {
                a2.push(a1.top());
                a1.pop();
                count++;
            }
            if(a2.size()<nums[i])
            {
                return -1;
            }
        }
        return queries.size()-count;
    }
};
