class Solution {
public:
    string buildSmallestString(long long targetFactor,int slots)
    {
        string result;
        for(int value=9;value>=2;value--)
        {
            while(targetFactor % value==0)
            {
                result.push_back(char(value+'0'));
                targetFactor/=value;
            }
        }
        while (result.size()<slots)
        {
            result.push_back('1');
        }
        reverse(result.begin(),result.end());
        return result;
    }
    string smallestNumber(string num,long long t)
    {
        int length=num.size();
        long long checkFactor=t;
        for(int prime:{2,3,5,7})
        {
            while(checkFactor%prime==0)
            {
                checkFactor/=prime;
            }
        }
        if(checkFactor!=1)
        {
            return "-1";
        }
        vector<long long> factorNeeded(length+1,t);
        for(int idx=0;idx<length;idx++)
        {
            int currentDigit=num[idx]-'0';
            if(currentDigit==0)
            {
                break;
            }
            factorNeeded[idx+1]=factorNeeded[idx]/gcd(factorNeeded[idx],(long long)currentDigit);
        }
        if(factorNeeded[length]==1)
        {
            return num;
        }
        int firstZero=num.find('0'),startIndex=length-1;
        if(firstZero!=-1)
        {
            startIndex=firstZero;
        }
        for(int pos=startIndex;pos>=0;pos--)
        {
            long long currentNeed=factorNeeded[pos];
            int remainingSlots=length-pos-1;
            for(int nextDigit=(num[pos]-'0')+1;nextDigit<=9;nextDigit++)
            {
                long long updatedNeed=currentNeed/gcd(currentNeed,(long long)nextDigit);
                string suffix=buildSmallestString(updatedNeed,remainingSlots);
                if(suffix.size()==remainingSlots)
                {
                    return num.substr(0,pos)+char(nextDigit+'0')+suffix;
                }
            }
        }
        return buildSmallestString(t,length+1);
    }
};
