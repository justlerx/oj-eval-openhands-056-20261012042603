#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

struct Interval {
    int l, r;
    bool operator<(const Interval& other) const {
        if (l != other.l) return l < other.l;
        return r < other.r;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    set<Interval> activities;
    
    for (int i = 0; i < n; i++) {
        char op;
        cin >> op;
        
        if (op == 'A') {
            int l, r;
            cin >> l >> r;
            
            vector<Interval> to_remove;
            
            // Check all intervals for overlap
            // Two intervals [a,b] and [c,d] overlap if: a <= d && c <= b
            for (auto it = activities.begin(); it != activities.end(); ++it) {
                if (it->l <= r && l <= it->r) {
                    to_remove.push_back(*it);
                }
            }
            
            // Remove all conflicting intervals
            for (const auto& interval : to_remove) {
                activities.erase(interval);
            }
            
            // Add the new interval
            activities.insert({l, r});
            
            cout << to_remove.size() << '\n';
        } else if (op == 'B') {
            cout << activities.size() << '\n';
        }
    }
    
    return 0;
}