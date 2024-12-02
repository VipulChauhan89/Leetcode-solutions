class Solution {
public:
    int isPrefixOfWord(string sentence,string searchWord) 
    {
        int n=searchWord.size(),i=1,ans=-1;
        stringstream ss(sentence);
        string sen;
        while(ss>>sen)
        {
            string s=sen.substr(0,n);
            if(s==searchWord)
            {
                ans=i;
                break;
            }
            i++;
        }
        return ans;
    }
};
