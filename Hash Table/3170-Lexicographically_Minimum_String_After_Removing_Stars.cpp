class Solution {
public:
    string clearStars(string s) 
    {
        string ans;
        priority_queue<pair<char,int>,vector<pair<char,int>>,greater<pair<char,int>>> pq;
        unordered_map<int,bool> m;
        for(int i=0;i<s.size();i++) 
        {
            if(s[i]=='*') 
            {
                m[-pq.top().second]=true;
                pq.pop();
            } 
            else 
            {
                pq.push({s[i],-i});
            }
        }
        for(int i=0;i<s.size();i++) 
        {
            if(m.count(i) || s[i]=='*')
            {
                continue;
            } 
            ans+=s[i];
        }
        return ans;
    }
};
