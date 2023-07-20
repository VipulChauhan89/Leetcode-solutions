class Solution {
public:
    vector<int> asteroidCollision(vector<int> &asteroids) 
    {
        vector<int> ans;
        int n=asteroids.size();
        stack<int> s;
        for(int i=0;i<n;i++)
        {
            if(s.empty() || asteroids[i]>0)
            {
                s.push(asteroids[i]);
            }
            else
            {
                while(!s.empty() && s.top()>0 && s.top()<abs(asteroids[i]))
                {
                    s.pop();
                }
                if(!s.empty() && s.top()==abs(asteroids[i]))
                {
                    s.pop();
                }
                else
                {
                    if(s.empty() || s.top()<0)
                    {
                        s.push(asteroids[i]);
                    }
                }
            }
        }
        int size=s.size();
        ans.resize(size,0);
        while(!s.empty()){
            ans[--size]=s.top();
            s.pop();
        }
        return ans;
    }
};
