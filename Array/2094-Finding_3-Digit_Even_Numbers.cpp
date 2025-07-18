class Solution {
public:
    vector<int> findEvenNumbers(vector<int> &digits) 
    {
        set<int> s;
        int n=digits.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                for(int k=0;k<n;k++)
                {
                    if(i==j || i==k || j==k)
                    {
                        continue;
                    }
                    int num=digits[i]*100+digits[j]*10+digits[k];
                    if(digits[i]!=0 && num%2==0)
                    {
                        s.insert(num);
                    }
                }
            }
        }
        vector<int> ans(s.begin(),s.end());
        return ans;
    }
};
