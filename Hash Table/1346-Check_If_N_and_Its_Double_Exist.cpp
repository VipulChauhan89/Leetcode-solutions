class Solution {
public:
    bool checkIfExist(vector<int> &arr) 
    {
        unordered_map<int,int> m;
        for(int i=0;i<arr.size();i++)
        {
            m[arr[i]]=i;
        }
        for(int i=0;i<arr.size();i++)
        {
            if(m.find(arr[i]*2)!=m.end() && m[arr[i]*2]!=i)
            {
                return true;
            }
        }
        return false;
    }
};
