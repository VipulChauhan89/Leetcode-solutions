class Solution {
public:
    int robotSim(vector<int> &commands,vector<vector<int>> &obstacles)
    {
        unordered_set<string> st;
        for(auto &obs:obstacles)
        {
            st.insert(to_string(obs[0])+","+to_string(obs[1]));
        }
        vector<pair<int,int>> dir={{0,1},{1,0},{0,-1},{-1,0}};
        int x=0,y=0,d=0,maxDist=0;
        for(int cmd:commands)
        {
            if(cmd==-1)
            {
                d=(d+1)%4;
            }
            else if(cmd==-2)
            {
                d=(d+3)%4;
            }
            else
            {
                for(int i=0;i<cmd;i++)
                {
                    int nx=x+dir[d].first;
                    int ny=y+dir[d].second;
                    if(st.count(to_string(nx)+","+to_string(ny)))
                    {
                        break;
                    }
                    x=nx;
                    y=ny;
                    maxDist=max(maxDist,x*x+y*y);
                }
            }
        }
        return maxDist;
    }
};
