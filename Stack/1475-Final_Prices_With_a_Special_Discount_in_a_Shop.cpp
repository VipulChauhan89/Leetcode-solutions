class Solution {
public:
    vector<int> finalPrices(vector<int> &prices) 
    {
        int n=prices.size();
        stack<int> st;
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && prices[i]<=prices[st.top()])
            {
                int ind=st.top();
                st.pop();
                prices[ind]-=prices[i];
            }
            st.push(i);
        }
        return prices;
    }
};
