class Solution {
public:
    int numberOfAlternatingGroups(vector<int> &colors,int k) 
    {
        colors.insert(colors.end(),colors.begin(),colors.begin()+(k-1));
        int ans=0,l=0,n=colors.size();
        for(int i=0;i<n;i++)
        {
            if(i>0 && colors[i]==colors[i-1])
            {
                l=i;
            }
            if(i-l+1>=k)
            {
                ans++;
            }
        }
        return ans;
    }
};
