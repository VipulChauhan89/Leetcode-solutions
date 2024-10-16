class Solution {
public:
    string longestDiverseString(int a,int b,int c) 
    {
        priority_queue<pair<int,char>> pq;
        if(a>0)
        {
            pq.push({a,'a'});
        }
        if(b>0)
        {
            pq.push({b,'b'});
        } 
        if(c>0)
        {
            pq.push({c,'c'});
        } 
        string ans="";
        while(!pq.empty()) 
        {
            auto [count1,char1]=pq.top();
            pq.pop();
            if(ans.size()>=2 && ans.back()==char1 && ans[ans.size()-2]==char1) 
            {
                if(pq.empty())
                {
                    break;
                } 
                auto [count2,char2]=pq.top();
                pq.pop();
                ans+=char2;
                count2--;
                if(count2>0)
                {
                    pq.push({count2,char2});
                } 
                pq.push({count1,char1});
            } 
            else 
            {
                ans+=char1;
                count1--;
                if(count1>0)
                {
                    pq.push({count1,char1});
                } 
            }
        }
        return ans;
    }
};
