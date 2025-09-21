#include <bits/stdc++.h>
using namespace std;

class MovieRentingSystem {
private:
    // price lookup for (shop, movie)
    unordered_map<long long, int> priceMap;
    
    // available[ movie ] = set of { price, shop }
    unordered_map<int, set<pair<int,int>>> available;
    
    // rented movies: { price, shop, movie }
    set<tuple<int,int,int>> rented;
    
    // Helper: pack (shop,movie) into one key for priceMap
    long long encodeKey(int shop, int movie) {
        return ((long long)shop << 20) | movie; 
    }

public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (auto &e : entries) {
            int shop = e[0], movie = e[1], price = e[2];
            priceMap[encodeKey(shop, movie)] = price;
            available[movie].insert({price, shop});
        }
    }
    
    // Search for cheapest shops for a given movie
    vector<int> search(int movie) {
        vector<int> res;
        if (available.count(movie)) {
            auto &s = available[movie];
            for (auto it = s.begin(); it != s.end() && (int)res.size() < 5; ++it) {
                res.push_back(it->second); // shop id
            }
        }
        return res;
    }
    
    // Rent a movie: move from available -> rented
    void rent(int shop, int movie) {
        int price = priceMap[encodeKey(shop, movie)];
        available[movie].erase({price, shop});
        rented.insert({price, shop, movie});
    }
    
    // Drop a movie: move from rented -> available
    void drop(int shop, int movie) {
        int price = priceMap[encodeKey(shop, movie)];
        rented.erase({price, shop, movie});
        available[movie].insert({price, shop});
    }
    
    // Report cheapest 5 rented movies
    vector<vector<int>> report() {
        vector<vector<int>> res;
        for (auto it = rented.begin(); it != rented.end() && (int)res.size() < 5; ++it) {
            auto [price, shop, movie] = *it;
            res.push_back({shop, movie});
        }
        return res;
    }
};

