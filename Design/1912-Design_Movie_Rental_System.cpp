class MovieRentingSystem {
public:
    map<int,set<pair<int,int>>> available;
    set<tuple<int,int,int>> rented;
    map<pair<int,int>,int> priceMap;
    MovieRentingSystem(int n,vector<vector<int>> &entries)
    {
        for(auto &i:entries)
        {
            int shop=i[0],movie=i[1],price=i[2];
            available[movie].insert({price,shop});
            priceMap[{shop,movie}]=price;
        }
    }
    
    vector<int> search(int movie)
    {
        vector<int> ans;
        if(available.count(movie))
        {
            for(auto &i:available[movie])
            {
                ans.push_back(i.second);
                if(ans.size()==5)
                {
                    break;
                }
            }
        }
        return ans;
    }
    
    void rent(int shop,int movie)
    {
        int price=priceMap[{shop,movie}];
        available[movie].erase({price,shop});
        rented.insert({price,shop,movie});
    }
    
    void drop(int shop,int movie)
    {
        int price=priceMap[{shop,movie}];
        rented.erase({price,shop,movie});
        available[movie].insert({price,shop});
    }
    
    vector<vector<int>> report()
    {
        vector<vector<int>> ans;
        for(auto &i:rented)
        {
            ans.push_back({get<1>(i),get<2>(i)});
            if(ans.size()==5)
            {
                break;
            }
        }
        return ans;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */
