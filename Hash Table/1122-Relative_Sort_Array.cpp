class Solution {
public:
    vector<int> relativeSortArray(vector<int> &arr1,vector<int> &arr2) 
    {
        unordered_map<int,int> m;
        for(int i=0;i<arr2.size();i++)
        {
            m[arr2[i]]=i;
        }
        sort(arr1.begin(),arr1.end(),[&m](int a,int b){
            return (m.count(a)?m[a]:1001+a)<(m.count(b)?m[b]:1001+b);
        });
        return arr1;
    }
};
