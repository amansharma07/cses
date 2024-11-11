#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;
#define ll long long

#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

#define debug(x) cout<<#x<<" :: "<<x<<endl;
#define debug2(x,y) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<endl;
#define debug3(x,y,z) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<endl;
#define debug4(p,q,r,s) cout<<#p<<" :: "<<p<<"\t"<<#q<<" :: "<<q<<"\t"<<#r<<" :: "<<r<<"\t"<<#s<<" :: "<<s<<endl;

const int MOD = 1e9 + 7;

int main() {
    // Uncomment below for file input
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout); 
    fast;
    ll n, m;
    cin >> n >> m;
    vector<vector<pair<ll, ll>>> adj(n + 2, vector<pair<ll, ll>>());
    while(m--) {
        ll u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    vector<ll> dis(n + 2, 1e18);
    vector<ll> route(n + 2, 0);
    vector<ll> min_flight(n + 2, 0);
    vector<ll> max_flight(n + 2, 0);
    priority_queue<pair<ll, ll>> pq;
    pq.push({0, 1});
    dis[1] = 0;
    route[1] = 1;
    while(!pq.empty()) {
        auto val = pq.top();
        pq.pop();
        auto u = val.second;
        auto d = -val.first;
        if(d > dis[u])
            continue;
        for(auto vv : adj[u]) {
            auto v = vv.first;
            auto wei = vv.second;
            if(d + wei > dis[v])
                continue;
            if(d + wei == dis[v]) {
                route[v] += route[u];
                route[v] %= MOD;
                min_flight[v] = min(min_flight[v], 1 + min_flight[u]);
                max_flight[v] = max(max_flight[v], 1 + max_flight[u]);
            }
            if(d + wei < dis[v]) {
                dis[v] = d + wei;
                route[v] = route[u];
                min_flight[v] = 1 + min_flight[u];
                max_flight[v] = 1 + max_flight[u];
                pq.push({-dis[v], v});
            }
        }
    }
    cout << dis[n] << " " << route[n] << " " << min_flight[n] << " " << max_flight[n] << endl;
    return 0;
}