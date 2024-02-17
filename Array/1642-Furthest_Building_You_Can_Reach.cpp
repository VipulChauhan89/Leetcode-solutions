class Solution {
public:
    int furthestBuilding(vector<int> &heights,int bricks,int ladders) 
    {
        int ans=0,dif=0;
        priority_queue<int> p;
        for(;ans<heights.size()-1;ans++)
        {
            dif=heights[ans+1]-heights[ans];
            if(dif>0)
            {
                bricks-=dif;
                p.push(dif);
                if(bricks<0)
                {
                    bricks+=p.top();
                    p.pop();
                    ladders--;
                }
                if(ladders<0)
                {
                    break;
                }
            }
        }
        return ans;
    }
};
