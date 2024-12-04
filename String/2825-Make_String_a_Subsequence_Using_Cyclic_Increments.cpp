class Solution {
public:
    bool canMakeSubsequence(string str1,string str2) 
    {
        int index=0,len=str2.length();
        for(auto i:str1)
        {
            if(index<len && (str2[index]-i+26)%26<=1)
            {
                index++;
            }
        }
        return index==len;
    }
};
