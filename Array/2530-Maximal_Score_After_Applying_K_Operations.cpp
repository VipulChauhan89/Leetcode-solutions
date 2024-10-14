class Solution {
public:
    long long maxKelements(vector<int> &nums,int k) 
    {
        priority_queue<int> pq(nums.begin(),nums.end());
        long long score=0;
        for(int i=0;i<k;i++)
        {
            int x=pq.top();
            score+=x;
            if(x==1)
            {
                score+=(k-1-i);
                break;
            }
            pq.pop();
            pq.push((x+2)/3);
        }
        return score;
    }
};
