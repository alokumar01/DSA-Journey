#include <bits/stdc++.h>
using namespace std;

class MovieRentingSystem {
    // STEP 1: Custom structure to store rented movies
    struct Entry {
        int shop, movie, price;
        // Sorting logic for rented movies
        bool operator<(const Entry &other) const {
            // Sort by price first
            if (price != other.price) return price < other.price;
            // If price same → sort by shop
            if (shop != other.shop) return shop < other.shop;
            // If shop also same → sort by movie id
            return movie < other.movie;
        }
    };

    // STEP 2: Data Structures
    // available[movie] → all available shops (price, shop)
    unordered_map<int, set<pair<int,int>>> available;

    // rented → global set of rented movies (Entry)
    set<Entry> rented;

    // priceMap[(shop,movie)] → price
    unordered_map<long long,int> priceMap;

    // STEP 3: Encode shop & movie into one unique key
    long long encode(int shop, int movie) {
        return ((long long)shop << 32) | movie;
    }

public:
    // STEP 4: Constructor → initialize the system
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (auto &e : entries) {
            int shop = e[0], movie = e[1], price = e[2];
            
            // store price for quick lookup
            priceMap[encode(shop,movie)] = price;

            // add this shop in available list of movie
            available[movie].insert({price,shop});
        }
    }
    
    // STEP 5: Search → get cheapest 5 shops for a movie
    vector<int> search(int movie) {
        vector<int> res;
        if (available.count(movie)) {
            int cnt = 0;
            for (auto &p : available[movie]) {
                if (cnt == 5) break;   // only take top 5
                res.push_back(p.second); // store shop id
                cnt++;
            }
        }
        return res;
    }
    
    // STEP 6: Rent → move movie from available → rented
    void rent(int shop, int movie) {
        int price = priceMap[encode(shop,movie)];
        // remove from available
        available[movie].erase({price,shop});
        // add to rented set
        rented.insert({shop,movie,price});
    }
    
    // STEP 7: Drop → move movie from rented → available
    void drop(int shop, int movie) {
        int price = priceMap[encode(shop,movie)];
        // remove from rented
        rented.erase({shop,movie,price});
        // add back to available
        available[movie].insert({price,shop});
    }
    
    // STEP 8: Report → get cheapest 5 rented movies globally
    vector<vector<int>> report() {
        vector<vector<int>> res;
        int cnt = 0;
        for (auto &e : rented) {
            if (cnt == 5) break;  // only take top 5
            res.push_back({e.shop,e.movie});
            cnt++;
        }
        return res;
    }
};

// 🔑 Easy Hinglish Explanation

// Data Structures banaye:

// available[movie] → stores shops jaha wo movie free hai, sorted by (price, shop).

// rented → globally rented movies, sorted by (price, shop, movie).

// priceMap → fast lookup of price from (shop, movie).

// search(movie):

// Jo shops available hai us movie ke liye → unme se cheapest 5 shops return karo.

// rent(shop, movie):

// Available se remove karo.

// Rented set me insert karo.

// drop(shop, movie):

// Rented se remove karo.

// Available me insert karo.

// report():

// Rented me jo cheapest 5 movies hai, unko return karo.

// ⚡ Sochne ka easy tareeka:

// available → per movie tracking

// rented → global tracking

// Dono set auto-sorted hote hai, toh hume manual sorting ki zaroorat nahi hai.