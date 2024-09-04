class Solution {
public:
    static int robotSim(vector<int> &commands,vector<vector<int>> &obstacles) 
    {
        int i=0,j=0,ans=0,direction=1;
        set<pair<int,int>> st;
        for(auto &i:obstacles)
        {
            st.insert({i[0],i[1]});
        }
        for(auto &k:commands)
        {
            if(k==-1)
            {
                direction=(direction+1)%5;
                if(direction==0)
                {
                    direction=1;
                }
            }
            else if(k==-2)
            {
                direction=(direction-1);
                if(direction==0)
                {
                    direction=4;
                } 
            }
            else
            {
                int dist=k;
                while(dist>0)
                {
                    if(direction==1)
                    {
                        if(st.find({i,j+1})!=st.end())
                        {
                            break;
                        } 
                        j++;
                    }
                    else if(direction==2)
                    {
                        if(st.find({i+1,j})!=st.end())
                        {
                            break;
                        } 
                        i++;
                    }else if(direction==3)
                    {
                        if(st.find({i,j-1})!=st.end())
                        {
                            break;
                        } 
                        j--;
                    }
                    else
                    {
                        if(st.find({i-1,j})!=st.end())
                        {
                            break;
                        } 
                        i--;
                    }
                    ans=max(ans,i*i + j*j);
                    dist--;
                }
            }
        }
        return ans;
    }
};
