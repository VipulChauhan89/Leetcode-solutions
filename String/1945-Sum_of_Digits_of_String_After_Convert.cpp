class Solution {
public:
    int getLucky(string s,int k) 
    {
        string number="";
        for(auto i:s)
        {
            number+=to_string(i-'a'+1);
        }
        while(k>0)
        {
            int temp=0;
            for(auto i:number)
            {
                temp+=i-'0';
            }
            number=to_string(temp);
            k--;
        }
        return stoi(number);
    }
};
