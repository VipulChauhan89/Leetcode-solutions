class Solution {
public:
    int minOperations(string s) 
    {
        vector<int> binary(2,0);
        for(int i=0;i<s.length();i++)
        {
            if(i%2==0)
            {
                binary[s[i]=='0']++;
            }
            else
            {
                binary[s[i]=='1']++;
            }
        }
        return min(binary[0],binary[1]);
    }
};
