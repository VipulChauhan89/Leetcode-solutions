class Solution {
public:
    string toDecimal(string &digits,int k) 
    {
        long long val=0;
        for(auto &i:digits)
        {
            val=val*k+(i-'0');
        }
        return to_string(val);
    }
    string nextSymmetric(string digits,int k) 
    {
        int n=digits.size(),half=digits.size()/2;
        for(int i=half;i<n;i++) 
        {
            if(digits[i]-'0'+1<k) 
            {
                char nextDigit='0'+(digits[i]-'0'+1);
                digits[i]=digits[digits.size()-1-i]=nextDigit;
                for(int j=half;j<i;j++)
                {
                    digits[j]=digits[digits.size()-1-j]='0';
                }
                return digits;
            }
        }
        return "1"+string(digits.size()-1,'0')+"1";
    }
    long long kMirror(int k,int n) 
    {
        string digits="0";
        long long sum=0;
        for(int i=0;i<n;) 
        {
            digits=nextSymmetric(digits,k);
            long long val=stoll(toDecimal(digits,k));
            string s=to_string(val);
            if(s==string(s.rbegin(),s.rend()))
            {
                sum+=val;
                i++;
            }
        }
        return sum;
    }
};
