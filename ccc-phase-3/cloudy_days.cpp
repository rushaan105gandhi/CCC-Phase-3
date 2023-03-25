#include <iostream>
#include <vector>
#include <utility>
#include <unordered_set>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 2e5;
const int MAXM = 1e5;
const int MAXP = 1e9;

vector<pair<int,int>> cities;
int y[MAXM];
int r[MAXM];

vector< pair<int,pair<int,int>> > endpoints;
ll prefsum[MAXN+1];
ll cover[MAXM];

ll people(int x1, int x2) {
    auto it1 = upper_bound(cities.begin(), cities.end(), make_pair(x1,0));
    auto it2 = upper_bound(cities.begin(), cities.end(), make_pair(x2,MAXP));
    if (it2 == cities.begin()) {
        return 0;
    }
    it2--;
    int i1 = it1-cities.begin();
    int i2 = it2-cities.begin();
    return max(0LL, prefsum[i2+1]-prefsum[i1]);
}

int main() {
    int n;
    cin >> n;
    cities.resize(n);

    ll sunny = 0;

    for (int i = 0; i < n; i++) {
        cin >> cities[i].second;
        sunny += cities[i].second;
    }
    for (int i = 0; i < n; i++) {
        cin >> cities[i].first;
    }

    sort(cities.begin(), cities.end());

    prefsum[0] = 0;
    for (int i = 0; i < cities.size(); i++) {
        prefsum[i+1] = prefsum[i]+cities[i].second;
    }

    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        cin >> y[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> r[i];
        endpoints.push_back({y[i]-r[i], {0,i}});
        endpoints.push_back({y[i]+r[i], {1,i}});
    }

    sort(endpoints.begin(), endpoints.end());

    unordered_set<int> intervals;
    
    for (int i = 0; i < endpoints.size(); i++) {
        int toflag = endpoints[i].second.first; 
        int toind = endpoints[i].second.second;  
        if (i > 0) {
            int from = endpoints[i-1].first;
            int to = endpoints[i].first;
            int fromflag = endpoints[i-1].second.first; 

            if (fromflag == 1) {
                from++;
            }
            if (toflag == 0) {
                to--;
            } 
            if (intervals.size() == 1 && !(from == to && fromflag == 0 && toflag == 1)) {
                cover[*intervals.begin()] += people(from,to);
            }
            if (intervals.size() > 0) {
                sunny -= people(from,to);
            }
        }
        if (toflag == 0) {
            intervals.insert(toind);
        } else {
            intervals.erase(toind);
        }
    }

    ll ans = 0;

    for (int i = 0; i < m; i++) {
        ans = max(ans, cover[i]);
    }

    cout << sunny+ans << '\n';
}