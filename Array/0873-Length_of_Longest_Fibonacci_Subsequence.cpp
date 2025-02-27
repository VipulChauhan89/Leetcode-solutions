class Solution {
public:
    int lenLongestFibSubseq(vector<int> &arr) 
    {
        unordered_set<int> s(arr.begin(),arr.end());
        int n=arr.size(),mx=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int previous=arr[j],current=arr[i]+arr[j],length=2;
                while(s.find(current)!=s.end())
                {
                    int temp=current;
                    current+=previous;
                    previous=temp;
                    mx=max(mx,++length);
                }
            }
        }
        return mx;
    }
};
