#include<bits/stdc++.h>
using namespace std;

class FoodRatings {
    unordered_map<string, pair<string, int>> foodToCuisineAndRating;
    unordered_map<string, set<pair<int, string>>> cuisineToFoods;

public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i < foods.size(); i++) {
            string foodName = foods[i];
            string cuisine = cuisines[i];
            int rating = ratings[i];

            foodToCuisineAndRating[foodName] = {cuisine, rating};
            cuisineToFoods[cuisine].insert({-rating, foodName});
        }
    }
    
    void changeRating(string foodName, int newRating) {
        auto [cuisine, oldRating] = foodToCuisineAndRating[foodName];
        cuisineToFoods[cuisine].erase({-oldRating, foodName});
        foodToCuisineAndRating[foodName] = {cuisine, newRating};
        cuisineToFoods[cuisine].insert({-newRating, foodName});
    }

    string highestRated(string cuisine) {
        return cuisineToFoods[cuisine].begin()->second;
    }
};

// steps

// 1. Initialization (constructor)

// For every food, store its {cuisine, rating} in foodToCuisineAndRating.

// Insert into cuisineToFoods[cuisine] with { -rating, foodName }.

// 2. Change Rating

// Lookup the food’s old info from foodToCuisineAndRating.

// Remove the old pair { -oldRating, foodName } from that cuisine’s set.

// Update the new rating in foodToCuisineAndRating.

// Insert { -newRating, foodName } back into the set.

// 3. Highest Rated

// The highest rated food is always the first element of the set (begin()).

// Return begin()->second (the food name).


/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */