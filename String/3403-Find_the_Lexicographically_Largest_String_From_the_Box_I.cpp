class Solution {
public:
    string answerString(string word,int numFriends) 
    {
        if(numFriends==1)
        {
            return word;
        } 
        string ans="";
        int n=word.length();
        for(int i=0;i<n;i++)
        {
            ans=max(ans,word.substr(i,n-numFriends+1));
        }
        return ans;
    }
};
