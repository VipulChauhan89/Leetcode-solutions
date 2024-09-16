class Solution {
public:
    int toMinutes(string s)
    {
        return stoi(s.substr(0,2))*60+stoi(s.substr(3));
    }
    int findMinDifference(vector<string> &timePoints) 
    {
        vector<int> a;
        for(auto &i:timePoints)
        {
            a.push_back(toMinutes(i));
        }
        sort(a.begin(),a.end());
        int ans=INT_MAX;
        for(int i=1;i<a.size();i++)
        {
            ans=min(a[i]-a[i-1],ans);
        }
        ans=min(ans,24*60-a.back()+a.front());
        return ans;
    }
};
