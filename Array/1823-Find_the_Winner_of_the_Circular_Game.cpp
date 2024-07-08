class Solution {
public:
    int findTheWinner(int n,int k) 
    {
        vector<int> ans;
        for(int i=1;i<=n;i++)
        {
            ans.push_back(i);
        }
        int currentIndex=0;
        while(ans.size()>1)
        {
            int nextToRemove=(currentIndex+k-1)%ans.size();
            ans.erase(ans.begin()+nextToRemove);
            currentIndex=nextToRemove;
        }
        return ans[0];
    }
};
