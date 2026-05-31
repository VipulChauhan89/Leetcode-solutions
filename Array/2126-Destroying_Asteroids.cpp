class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        int maxasteroid=0;
        for(int a:asteroids)
        {
            if(a>maxasteroid)
            {
                maxasteroid=a;
            }
        }
        vector<int> freq(maxasteroid+1,0);
        for(int a:asteroids)
        {
            freq[a]++;
        }
        long long currentmass=mass;
        for(int i=1;i<=maxasteroid;i++)
        {
            if(freq[i]>0)
            {
                if(i>currentmass)
                {
                    return false;
                }
                currentmass+=(long long)i*freq[i];
            }
        }
        return true;
    }
};
