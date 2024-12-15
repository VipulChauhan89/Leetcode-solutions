class Solution {
public:
    double maxAverageRatio(vector<vector<int>> &classes,int extraStudents) 
    {
        priority_queue<tuple<double,int,int>> heap;
        double sum=0.0;
        for(auto &c:classes) 
        {
            int p=c[0],q=c[1];
            sum+=(double)p/q;
            double improvement=(double)(q-p)/(q*(q+1.0));
            heap.emplace(improvement,p,q);
        }
        for(int i=0;i<extraStudents;i++) 
        {
            auto [r,p,q]=heap.top();
            heap.pop();
            if(r==0)
            {
                break;
            } 
            sum+=r;
            double newImprovement=(double)(q-p)/((q+1.0)*(q+2.0));
            heap.emplace(newImprovement,p+1,q+1);
        }
        return sum/classes.size();
    }
};
