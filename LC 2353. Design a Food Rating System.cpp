class FoodRatings {
    unordered_map<string, map<int, map<string, int>>> m;
    unordered_map<string, int> rat;
    unordered_map<string, string> cui;
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i=0; i<foods.size(); i++){
            m[cuisines[i]][ratings[i]][foods[i]] = 1;
            rat[foods[i]] = ratings[i];
            cui[foods[i]] = cuisines[i];
        }
    }
    
    void changeRating(string food, int newRating) {
        string c = cui[food];
        int r = rat[food];
        m[c][r].erase(food);
        if(m[c][r].size() == 0){
            m[c].erase(r);
        }
        m[c][newRating][food] = 1;
        rat[food] = newRating;
    }
    
    string highestRated(string cuisine) {
        string ret;
        int min_rat = m[cuisine].rbegin()->first;
        ret = m[cuisine][min_rat].begin()->first;
        return ret;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
