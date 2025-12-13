class Solution {
public:
    vector<string> categories={"electronics","grocery","pharmacy","restaurant"};
    static bool isValidCode(const string &s)
    {
        if(s.empty())
        {
            return false;
        }
        for(char c:s)
        {
            if(!isalnum(c) && '_'!=c)
            {
                return false;
            }
        }
        return true;
    }
    vector<string> validateCoupons(vector<string> &code,vector<string> &businessLine,vector<bool> &isActive)
    {
        int n=code.size();
        vector<int> valid;
        for(int i=0,cid=-1;i<n;i++)
        {
            if(isActive[i] && (cid=find(categories.begin(),categories.end(),businessLine[i])-categories.begin())<4 && isValidCode(code[i]))
            {
                valid.push_back(i | cid<<8);
            }
        }
        sort(valid.begin(),valid.end(),[&code](int a,int b) {
            const int dcat=(a>>8)-(b>>8);
            return dcat?dcat<0:code[a&255]<code[b&255];
        });
        vector<string> validCodes;
        int m=valid.size();
        for(int i=0;i<m;i++)
        {
            validCodes.push_back(code[valid[i]&255]);
        }
        return validCodes;
    }
};
