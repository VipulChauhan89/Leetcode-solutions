class Solution {
public:
    int peakIndexInMountainArray(vector<int> &arr) 
    {
        int l=0,h=arr.size()-1;
        while(l<h)
        {
            int mid=(l+h)/2;
            if(arr[mid]<arr[mid+1])
            {
                l=mid+1;
            }
            else
            {
                h=mid;
            }
        }
        return l;
    }
};
