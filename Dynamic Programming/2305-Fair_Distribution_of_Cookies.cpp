class Solution {
public:
    int k,res=INT_MAX;      
    vector<int> d;          
    void dfs(vector<int> &real,int index,int f) 
    {
        if(index==real.size()) 
        {   
            int iron_man=0;
            for(int i=0;i<k;i++) 
            {
                iron_man=max(iron_man,d[i]);
            }
            res=min(res,iron_man);
            return;
        }
        for(int i=0;i<f;i++) 
        {
            d[i]+=real[index];     
            dfs(real,index+1,f);
            d[i]-=real[index]; 
        }

        if(f<k) 
        {
            d[f]+=real[index];     
            dfs(real,index+1,f+1); 
            d[f]-=real[index];     
        }
    }
    int distributeCookies(vector<int> &real,int K) 
    {
        k=K;
        d.resize(K);
        dfs(real,0,0);
        return res;
    }
};
