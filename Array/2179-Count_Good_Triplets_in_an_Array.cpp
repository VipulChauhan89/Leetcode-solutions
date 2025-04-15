class Solution {
public:
    int binarySearchInsertPosition(vector<int> &arr,int target) 
    {
        int l=0,h=arr.size();
        while(l<h) 
        {
            int mid=(l+h)/2;
            if(arr[mid]<target) 
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
    long long goodTriplets(vector<int> &nums1,vector<int> &nums2) 
    {
        unordered_map<int,int> m;
        vector<int> sorted;
        long long total=0;
        for(int i=0;i<nums1.size();i++) 
        {
            m[nums1[i]]=i;
        }
        for(auto &i:nums2) 
        {
            long long indexInNums1=m[i],leftCount=binarySearchInsertPosition(sorted,indexInNums1),rightCount=(nums1.size()-1-indexInNums1)-(sorted.size()-leftCount);
            total+=leftCount*rightCount;
            int insertPos=binarySearchInsertPosition(sorted,indexInNums1);
            sorted.insert(sorted.begin()+insertPos,indexInNums1);
        }
        return total;
    }
};
