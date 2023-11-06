class SeatManager {
public:
    priority_queue<int,vector<int>,greater<int>> availableSeats;
    SeatManager(int n) 
    {
        for(int i=1;i<=n;i++) 
        {
            availableSeats.push(i);
        }
    }
    int reserve() 
    {
        if(!availableSeats.empty()) 
        {
            int seat=availableSeats.top();
            availableSeats.pop();
            return seat;
        }
        return -1;
    }
    void unreserve(int seatNumber) 
    {
        availableSeats.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */
