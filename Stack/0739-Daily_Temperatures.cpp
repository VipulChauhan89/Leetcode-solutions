class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) 
    {
        int n=temperatures.size();
        vector<int> ans(n,0);
        stack<int> s;
        for(int i=0;i<n;i++)
        {
            while(s.empty()==false && temperatures[s.top()]<temperatures[i])
            {
                int j=s.top();
                s.pop();
                ans[j]=i-j;
            }
            s.push(i);
        }
        return ans;
    }
};
