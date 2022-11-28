class Solution {
public:
    int mostWordsFound(vector<string>& sentences) 
    {
        int count,mx=INT_MIN;
        for(auto s:sentences)
        {
            count=1;
            for(auto w:s)
            {
                if(w==' ')
                {
                    count++;
                }
            }
            mx=max(mx,count);
        }
        return mx;
    }
};
