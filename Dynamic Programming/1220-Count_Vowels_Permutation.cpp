class Solution {
public:
    int countVowelPermutation(int n) 
    {
        const int MOD=1e9+7;
        vector<long long> vowels(5,1);
        vector<long long> temp(5,0);
        for(int i=1;i<n;i++)
        {
            temp[0]=vowels[1];
            temp[1]=(vowels[0]+vowels[2])%MOD;
            temp[2]=(vowels[0]+vowels[1]+vowels[3]+vowels[4])%MOD;
            temp[3]=(vowels[2]+vowels[4])%MOD;
            temp[4]=vowels[0];
            vowels[0]=temp[0],vowels[1]=temp[1],vowels[2]=temp[2],vowels[3]=temp[3],vowels[4]=temp[4];
        }
        return (vowels[0]+vowels[1]+vowels[2]+vowels[3]+vowels[4])%MOD;
    }
};
