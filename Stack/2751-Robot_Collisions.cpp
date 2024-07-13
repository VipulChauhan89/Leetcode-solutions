class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int> &positions,vector<int> &healths,string directions) 
    {
        vector<int> ans,indices(positions.size());
        iota(indices.begin(),indices.end(),0);
        sort(indices.begin(),indices.end(),[&positions](int A,int B){
            return positions[A]<positions[B];
        });
        stack<int> st;
        for(int i:indices)
        {
            if(directions.at(i)=='R')
            {
                st.push(i);
            } 
            else 
            {
                if(st.empty())
                {
                    continue;
                } 
                while(!st.empty() && healths.at(st.top())<=healths.at(i))
                { 
                    if(healths.at(st.top())==healths.at(i))
                    {
                        healths.at(i)=-1;
                        healths.at(st.top())=-1;
                        st.pop();
                        break;
                    }
                    else
                    {
                        healths.at(st.top())=-1;
                        st.pop();
                        healths.at(i)--;
                    }
                }
                if(!st.empty() && healths.at(i)>0 && healths.at(st.top())> healths[i])
                {
                    healths.at(st.top())--;
                    healths.at(i)=-1;
                }
            }
        }
        for(int i:healths)
        {
            if(i>0)
            {
                ans.push_back(i);
            } 
        }
        return ans;
    }
};
