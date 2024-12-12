class Solution {
public:
    long long pickGifts(vector<int> &gifts,int k) 
    {
        long long sum=accumulate(gifts.begin(),gifts.end(),0LL);
        priority_queue<int> pq(gifts.begin(),gifts.end());
        for(int i=0,x=INT_MAX,y;i<k && x>1;i++)
        {
            x=pq.top(),y=sqrt(x);
            pq.pop();
            sum-=(x-y);
            pq.push(y);
        }
        return sum;
    }
};
