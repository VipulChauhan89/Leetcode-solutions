class Solution {
public:
    long long dividePlayers(vector<int> &skill) 
    {
        sort(skill.begin(),skill.end());
        int n=skill.size(),totalSkill=skill[0]+skill[n-1];
        long long sum=0;
        for(int i=0;i<n/2;i++) 
        {
            if(skill[i]+skill[n-i-1]!=totalSkill) 
            {
                return -1;
            }
            sum+=(long long)skill[i]*skill[n-i-1];
        }
        return sum;
    }
};
