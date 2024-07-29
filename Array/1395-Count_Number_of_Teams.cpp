class Solution {
public:
    int numTeams(vector<int> &rating) 
    {
        int n=rating.size(),count=0;
        for(int i=1;i<n-1;i++) 
        {
            vector<int> L(2,0),R(2,0);
            for(int j=0;j<i;j++)
            {
                L[rating[j]<rating[i]]++;
            } 
            for(int j=i+1;j<n;j++) 
            {
                R[rating[j]<rating[i]]++;
            }
            count+=L[0]*R[1]+L[1]*R[0];
        }
        return count;
    }
};
