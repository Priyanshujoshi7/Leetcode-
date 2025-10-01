#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int totalDrank = numBottles;   // You drink all initial bottles
        int empty = numBottles;        // Now you have that many empty bottles
        
        // Keep exchanging as long as you have enough empty bottles
        while (empty >= numExchange) {
            int newBottles = empty / numExchange;   // How many new full bottles you get
            totalDrank += newBottles;              // You will drink them all
            empty = newBottles + (empty % numExchange); // New empties + leftover empties
        }
        
        return totalDrank;
    }
};

