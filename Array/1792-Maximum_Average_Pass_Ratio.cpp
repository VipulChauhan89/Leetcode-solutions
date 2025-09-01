class Solution {
public:
    double gain(double p,double t)
    {
        return (p+1)/(t+1)-p/t;
    }
    double maxAverageRatio(vector<vector<int>> &classes,int extraStudents)
    {
        priority_queue<tuple<double,int,int>> pq;
        for(auto &i:classes)
        {
            pq.push({gain(i[0],i[1]),i[0],i[1]});
        }
        while(extraStudents--)
        {
            auto [g,p,t]=pq.top();
            pq.pop();
            p++;
            t++;
            pq.push({gain(p,t),p,t});
        }
        double total=0;
        while(!pq.empty())
        {
            auto [g,p,t]=pq.top();
            pq.pop();
            total+=(double)p/t;
        }
        return total/classes.size();
    }
};
