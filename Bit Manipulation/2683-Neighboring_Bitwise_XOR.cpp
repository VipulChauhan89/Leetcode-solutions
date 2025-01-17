class Solution {
public:
    bool doesValidArrayExist(vector<int> &derived) 
    {
        int n=derived.size();
        bool valid=true;
        vector<int> original(n,derived[0]);
        for(int i=0;i<n-1;i++)
        {
            original[i+1]=derived[i]^original[i];
            if(original[i]>1)
            {
                valid=false;
            }
        }
        return ((original[n-1]^original[0]!=derived[n-1])?false:valid);
    }
};
