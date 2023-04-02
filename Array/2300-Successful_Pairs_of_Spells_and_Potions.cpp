class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells,vector<int>& potions,long long success) 
    {
        int n=potions.size();
        vector<int> v;
        sort(potions.begin(),potions.end());
        for(int i=0;i<spells.size();i++)
        {
            int l=0,h=n-1;
            while(l<=h)
            {
                int mid=l+(h-l)/2;
                if((long long int)spells[i]*(long long int)potions[mid]>=success)
                {
                    h=mid-1;
                }
                else
                {
                    l=mid+1;
                }
            }
            v.push_back(n-1-h);
        }
        return v;
    }
};
