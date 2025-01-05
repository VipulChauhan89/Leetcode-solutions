class Solution {
public:
    string shiftingLetters(string s,vector<vector<int>> &shifts)   
    {
        int n=s.size(),cur=0;
        vector<int> A(n+1,0);
        for(auto &i:shifts)
        {
            int start=i[0],end=i[1],dir=i[2];
            A[start]+=(dir==1?1:-1);
            A[end+1]-=(dir==1?1:-1);
        }
        for(int i=0;i<n;i++)
        {
            cur+=A[i];
            A[i]=cur;
        }
        for(int i=0;i<n;i++)
        {
            int sh=(A[i]%26+26)%26;
            s[i]='a'+(s[i]-'a'+sh)%26;
        }
        return s;
    }
};
