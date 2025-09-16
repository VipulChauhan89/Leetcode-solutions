class Solution {
public:
    int gcd(int a,int b)
    {
        return b==0?a:gcd(b,a%b);
    }
    vector<int> replaceNonCoprimes(vector<int> &nums)
    {
        vector<int> st;
        for(auto &i:nums)
        {
            while(!st.empty())
            {
                int top=st.back(),g=gcd(top,i);
                if(g==1)
                {
                    break;
                }
                st.pop_back();
                long long merged=(long long)top/g*i;
                i=(int)merged;
            }
            st.push_back(i);
        }
        return st;
    }
};
