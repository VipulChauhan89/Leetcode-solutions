class Solution {
public:
    int minStoneSum(vector<int>& piles,int k){
        priority_queue<pair<int,int>> pq;
        int updated_val,updated_index,sum=0;
        for(int i=0;i<piles.size();i++)
        {
            pq.push(make_pair(piles[i],i));
        }
        while(k--) 
        {
            int index=pq.top().second;
            piles[index]-=floor(piles[index]/2);
            pq.pop();
            pq.push(make_pair(piles[index],index));
        }
        for(int i=0;i<piles.size();i++) 
        {
            sum += piles[i];
        }
        return sum;
    }
};
