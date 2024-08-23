class Solution {
public:
    string reduce(long long num,long long den) 
    {
        long long g=gcd(abs(num),den);
        return to_string(num/g)+"/"+to_string(den/g);
    }
    string fractionAddition(string exp) 
    {
        long long  n=exp.size(),i=0;
        vector<long long> nums,dens;
        while(i<n) 
        {
            long long num=0,den=0,sign=1;
            if(exp[i]=='-' || exp[i]=='+') 
            {
                sign=(exp[i]=='-')?-1:1;
                i++;
            }
            while(i<n && isdigit(exp[i])) 
            {
                num=num*10LL+(exp[i]-'0');
                i++;
            }
            num*=sign;
            i++;
            while(i<n && isdigit(exp[i])) 
            {
                den=den*10LL+(exp[i]-'0');
                i++;
            }
            nums.push_back(num);
            dens.push_back(den);
        }
        long long commonDen=dens[0];
        for(long long i=1;i<nums.size();i++) 
        {
            commonDen=commonDen*dens[i]/gcd(commonDen,dens[i]);
        }
        long long sumNum=0;
        for(long long i=0;i<nums.size();i++) 
        {
            sumNum+=nums[i]*(commonDen/dens[i]);
        }
        return reduce(sumNum,commonDen);
    }
};
