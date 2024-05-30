class Solution {
public:
    int countTriplets(vector<int> & arr) {
        int ans=0;
        for(int i=0;i<arr.size()-1;i++) 
        {
            int xor_first_arr=0;
            for(int j=i+1;j<arr.size();j++) 
            {
                xor_first_arr^=arr[j-1];
                int xor_second_arr=0;
                for(int k=j;k<arr.size();k++) 
                {
                    xor_second_arr^=arr[k];
                    if(xor_first_arr==xor_second_arr) 
                    {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};
