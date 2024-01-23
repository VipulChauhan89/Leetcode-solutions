class Solution {
public:
    bool isValid(const string &current, const string &newCurrent)
    {
        unordered_set<char> s;
        for(auto i:newCurrent)
        {
            if(s.count(i)>0)
            {
                return false;
            }
            s.insert(i);
            if(current.find(i)!=string::npos)
            {
                return false;
            }
        } 
        return true;
    }
    void backtrack(vector<string> &arr,string current,int start,int &mxLen)
    {
        if(mxLen<current.length())
        {
            mxLen=current.length();
        }
        for(int i=start;i<arr.size();i++)
        {
            if(!isValid(current,arr[i]))
            {
                continue;
            }
            backtrack(arr,current+arr[i],i+1,mxLen);
        }
    }
    int maxLength(vector<string> &arr) {
        int ans=0;
        backtrack(arr,"",0,ans);
        return ans;
    }
};
