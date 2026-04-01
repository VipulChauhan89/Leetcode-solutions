class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int> &positions,vector<int> &healths,string directions)
    {
        int n=positions.size();
        vector<int> order(n),st,ans;
        iota(order.begin(),order.end(),0);
        sort(order.begin(),order.end(),[&](int a,int b){ return positions[a]<positions[b]; });

        vector<bool> alive(n,true);
        for(int idx:order)
        {
            if(directions[idx]=='R')
            {
                st.push_back(idx);
            }
            else
            {
                while(!st.empty())
                {
                    int top=st.back();
                    if(healths[top]<healths[idx])
                    {
                        alive[top]=false;
                        st.pop_back();
                        healths[idx]--;
                    }
                    else if(healths[top]>healths[idx])
                    {
                        alive[idx]=false;
                        healths[top]--;
                        break;
                    }
                    else
                    {
                        alive[top]=false;
                        alive[idx]=false;
                        st.pop_back();
                        break;
                    }
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            if(alive[i])
            {
                ans.push_back(healths[i]);
            }

        }
        return ans;
    }
};
