class RideSharingSystem {
public:
    queue<int> rider;
    queue<int> driver;
    unordered_set<int> s;
    RideSharingSystem() {
        
    }
    
    void addRider(int riderId) {
        rider.push(riderId);
    }
    
    void addDriver(int driverId) {
        driver.push(driverId);
    }
    
    vector<int> matchDriverWithRider() {
        while(!rider.empty() && s.find(rider.front()) != s.end()){
            s.erase(rider.front());
            rider.pop();
        }
        if(rider.empty() || driver.empty()){
            return {-1,-1};
        }
        vector<int> match(2);
        match[0] = driver.front();
        match[1] = rider.front();
        driver.pop(); rider.pop();
        return match;
    }
    
    void cancelRider(int riderId) {
        if(!rider.empty()){
            if(rider.front() == riderId){
               rider.pop();
            }else{
               s.insert(riderId);
           }
        }    
    }
};

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem* obj = new RideSharingSystem();
 * obj->addRider(riderId);
 * obj->addDriver(driverId);
 * vector<int> param_3 = obj->matchDriverWithRider();
 * obj->cancelRider(riderId);
 */