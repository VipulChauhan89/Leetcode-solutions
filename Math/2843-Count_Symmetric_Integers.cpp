class Solution {
public:
    int countSymmetricIntegers(int low,int high) 
    {
        int count=0;
        for(int i=low;i<=high;i++)
        {
            string s=to_string(i);
            int n=s.size();
            if(n%2==0 && (accumulate(s.begin(),s.begin()+n/2,0)==accumulate(s.begin()+n/2,s.end(),0)))
            {
                count++;
            }
        }
        return count;
    }
};
