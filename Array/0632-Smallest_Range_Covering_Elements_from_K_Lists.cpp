class Tracker {
public:
    int val,index,column;
    Tracker(int v,int i,int c)
    {
        val=v;
        index=i;
        column=c;
    }
};

struct Compare {
    bool operator()(const Tracker &a,const Tracker &b) 
    {
        return a.val>b.val;
    }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<Tracker,vector<Tracker>,Compare> track;
        int maxVal=INT_MIN,n=nums.size(),startRange=0,endRange=INT_MAX;
        for(int i=0;i<n;i++) 
        {
            int val=nums[i][0];
            track.push(Tracker(val,i,0));
            maxVal=max(maxVal,val);
        }
        while(track.size()==n) 
        {
            Tracker temp=track.top();
            track.pop();
            if(maxVal-temp.val<endRange-startRange) 
            {
                startRange=temp.val;
                endRange=maxVal;
            }
            if(temp.column+1<nums[temp.index].size()) 
            {
                int nextVal=nums[temp.index][temp.column+1];
                track.push(Tracker(nextVal,temp.index,temp.column+1));
                maxVal=max(maxVal,nextVal);
            }
        }
        return {startRange,endRange};
    }
};
