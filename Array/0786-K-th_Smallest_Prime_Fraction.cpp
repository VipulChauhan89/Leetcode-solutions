class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n=arr.size();
        double l=0,r=1,mid;
        vector<int> ans;
        while(l<=r) 
        {
            mid=l+(r-l)/2;
            int j=1,total=0,num=0,den=0;
            double maxFrac=0;
            for(int i=0;i<n;i++) 
            {
                while(j<n && arr[i]>=arr[j]*mid) 
                {
                    j++;
                }
                total+=n-j;
                if(j<n && maxFrac<arr[i]*1.0/arr[j]) 
                {
                    maxFrac=arr[i]*1.0/arr[j];
                    num=i;
                    den=j;
                }
            }
            if(total==k) 
            {
                ans={arr[num],arr[den]};
                break;
            }
            if(total>k) 
            {
                r=mid;
            } 
            else 
            {
                l=mid;
            }
        }
        return ans;
    }
};
