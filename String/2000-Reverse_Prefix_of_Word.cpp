class Solution {
public:
    string reversePrefix(string word,char ch) 
    {
        int c=0;
        for(int i=0;i<word.length();i++)
        {
            if(word[i]==ch)
            {
                c=i;
                break;
            }
        }
        string st=word.substr(0,c+1);
        reverse(st.begin(),st.end());
        st=st+word.substr(c+1,word.length());
        return st;
    }
};
