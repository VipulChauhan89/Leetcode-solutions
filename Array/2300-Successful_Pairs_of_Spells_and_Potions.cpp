class Solution {
public:
    vector<int> successfulPairs(vector<int> &spells,vector<int> &potions,long long success)
    {
        sort(potions.begin(),potions.end());
        vector<int> ans(spells.size());
        for(int i=0;i<spells.size();i++)
        {
            long long sp=spells[i],s=0,e=potions.size()-1;
            int ind=-1;
            while(s<=e)
            {
                int mid=(s+e)/2;
                if(potions[mid]*sp>=success)
                {
                    ind=mid;
                    e=mid-1;
                }
                else
                {
                    s=mid+1;
                }
            }
            ans[i]=(ind==-1)?0:(potions.size()-ind);
        }
        return ans;
    }
};
