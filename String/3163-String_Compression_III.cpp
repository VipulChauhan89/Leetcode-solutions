class Solution {
public:
    string compressedString(string word) 
    {
        string ans="";
        int count=1,n=word.size();
        char c=word[0];
        for(int i=1;i<n;i++)
        {
            if(word[i]==c && count<9)
            {
                count++;
            }
            else
            {
                ans.push_back(count+'0');
                ans.push_back(c);
                c=word[i];
                count=1;
            }
        }
        ans.push_back(count+'0');
        ans.push_back(c);
        return ans;
    }
};
