class Solution {
public:
    bool canWe(vector<int> &position,int mid,int m)
    {
        int count=1,last=position[0];
        for(int i=0;i<position.size();i++)
        {
            if(position[i]-last>=mid)
            {
                count++;
                last=position[i];
            }
            if(count>=m)
            {
                return true;
            }
        }
        return false;
    }
    int maxDistance(vector<int> &position,int m) 
    {
        sort(position.begin(),position.end());
        int l=1,h=(position.back()-position[0])/(m-1),ans=1;
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            if(canWe(position,mid,m))
            {
                ans=mid;
                l=mid+1;
            }
            else
            {
                h=mid-1;
            }
        }
        return ans;
    }
};
