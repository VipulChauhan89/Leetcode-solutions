class Router {
public:
    typedef pair<int,pair<int,int>> Packet;
    queue<Packet> packetQueue;
    set<Packet> packetSet;
    unordered_map<int,pair<int,vector<int>>> destinationMap;
    int memoryLimit;

    Router(int limit)
    {
        memoryLimit=limit;
    }
    
    bool addPacket(int source,int destination,int timestamp)
    {
        Packet newPacket={source,{destination,timestamp}};
        if(packetSet.find(newPacket)!=packetSet.end())
        {
            return false;
        }
        else
        {
            packetQueue.push(newPacket);
            destinationMap[destination].second.push_back(timestamp);
            packetSet.insert(newPacket);
            if(packetQueue.size()>memoryLimit)
            {
                Packet oldestPacket=packetQueue.front();
                packetQueue.pop();
                destinationMap[oldestPacket.second.first].first++;
                packetSet.erase(oldestPacket);
            }
            return true;
        }
    }
    
    vector<int> forwardPacket()
    {
        vector<int> packetData;
        if(!packetQueue.empty())
        {
            Packet frontPacket=packetQueue.front();
            packetQueue.pop();
            destinationMap[frontPacket.second.first].first++;
            packetData.push_back(frontPacket.first);
            packetData.push_back(frontPacket.second.first);
            packetData.push_back(frontPacket.second.second);
            packetSet.erase(frontPacket);
        }
        return packetData;
    }
    
    int getCount(int destination,int startTime,int endTime)
    {
        int processedCount=destinationMap[destination].first;
        auto& timestamps=destinationMap[destination].second;

        return upper_bound(timestamps.begin()+processedCount,timestamps.end(),endTime)-lower_bound(timestamps.begin()+processedCount,timestamps.end(),startTime);
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */
