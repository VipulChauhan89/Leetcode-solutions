class Solution {
public:
    vector<int> sequentialDigits(int low,int high) 
    {
        vector<int> ans;
        int l=floor(log10(low)+1),h=floor(log10(high)+1)+1;
        string digits="123456789";
        for(int i=l;i<h;i++)
        {
            for(int j=0;j<=9-i;j++)
            {
                int num=stoi(digits.substr(j,i));
                if(num>=low && num<=high)
                {
                    ans.push_back(num);
                }
            }
        }
        return ans;
        
    }
};
