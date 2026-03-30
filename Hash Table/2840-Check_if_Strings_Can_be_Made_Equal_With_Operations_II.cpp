class Solution {
public:
    bool checkStrings(string s1,string s2)
    {
        vector<int> freq(52,0);
        int n=s1.size();
        for(int i=0;i<n;i++)
        {
            bool iOdd=i&1;
            freq[iOdd*26+(s1[i]-'a')]++;
            freq[iOdd*26+(s2[i]-'a')]--;
        }
        return all_of(freq.begin(),freq.end(),[](int x) { return x==0; });
    }
};
