class FoodRatings {
public:
    unordered_map<string,set<pair<int,string>>> cuisRating;
    unordered_map<string,int> foodRating;
    unordered_map<string,string> foodCuis;
    FoodRatings(vector<string> &foods,vector<string> &cuisines,vector<int> &ratings)
    {
        for(int i=0;i<foods.size();i++)
        {
            foodRating.insert({foods[i],ratings[i]});
            foodCuis.insert({foods[i],cuisines[i]});
            cuisRating[cuisines[i]].insert({-ratings[i],foods[i]});
        }
    }
    
    void changeRating(string food,int newRating)
    {
        string cus=foodCuis[food];
        int oldRating=foodRating[food];
        cuisRating[cus].erase({-oldRating,food});
        cuisRating[cus].insert({-newRating,food});
        foodRating[food]=newRating;
    }
    
    string highestRated(string cuisine)
    {
        return cuisRating[cuisine].begin()->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
