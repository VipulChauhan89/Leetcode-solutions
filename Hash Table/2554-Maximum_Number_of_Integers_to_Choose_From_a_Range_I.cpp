class Solution {
public:
    int maxCount(vector<int> &banned,int n,int maxSum) 
    {
        unordered_set<int> s(banned.begin(),banned.end());
        int sum=0,count=0;
        for(int i=1;i<=n;i++)
        {
            if(s.count(i))
            {
                continue;
            }
            sum+=i;
            if(sum>maxSum)
            {
                break;
            }
            count++;
        }
        return count;
    }
};
