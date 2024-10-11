class Solution {
public:
    int smallestChair(vector<vector<int>> &times,int targetFriend) 
    {
        int n=times.size();
        vector<int> chairs(n,-1);
        int tar=times[targetFriend][0];
        sort(times.begin(),times.end());
        for(auto i:times) 
        {
            int arr=i[0],dep=i[1];
            for(int j=0;j<n;j++) 
            {
                if(arr>=chairs[j]) 
                {
                    chairs[j]=dep;
                    if(arr==tar)
                    {
                        return j;
                    }
                    break;
                }
            }
        }
        return -1;
    }
};
