class UndergroundSystem {
public:
    unordered_map<int,pair<string,int>> c;
    unordered_map<string,pair<int,int>> o;
    UndergroundSystem() 
    {
        
    }
    
    void checkIn(int id,string stationName,int t) 
    {
        c[id]={stationName,t};
    }
    
    void checkOut(int id,string stationName,int t) 
    {
        pair<string,int> p=c[id];
        c.erase(id);
        string s=p.first+"-"+stationName;
        o[s].first+=t-p.second;
        o[s].second+=1;
    }
    
    double getAverageTime(string startStation,string endStation) 
    {
        string s=startStation+"-"+endStation;
        pair<int,int> p=o[s];
        return (double)p.first/p.second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
