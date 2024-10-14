#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;
#define ll long long

#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

#define debug(x) cout<<#x<<" :: "<<x<<endl;
#define debug2(x,y) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<endl;
#define debug3(x,y,z) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<endl;
#define debug4(p,q,r,s) cout<<#p<<" :: "<<p<<"\t"<<#q<<" :: "<<q<<"\t"<<#r<<" :: "<<r<<"\t"<<#s<<" :: "<<s<<endl;

const ll INF = 1e18;

int main() {
    // Uncomment below for file input
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout); 
    fast;
    ll n, m, k;
    cin >> n >> m >> k;
    vector<vector<pair<ll, ll>>> adj(n + 2, vector<pair<ll, ll>>());
    while(m--) {
        ll u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    vector<vector<ll>> dis(n + 2, vector<ll>(k, INF));
    priority_queue<pair<ll, ll>> pq;
    pq.push({0, 1});
    while(!pq.empty()) {
        auto val = pq.top();
        pq.pop();
        auto u = val.second;
        auto dist = val.first;
        dist *= -1;
        if(dis[u][k-1] < dist)
            continue;
        for(auto vv : adj[u]) {
            auto v = vv.first;
            auto wei = vv.second;
            if(dist + wei < dis[v][k-1]) {
                dis[v][k-1] = dist + wei;
                pq.push({-dis[v][k-1], v});
                sort(dis[v].begin(), dis[v].end());
            }
        }
    }
    for(int i = 0; i < k; i++)
        cout << dis[n][i] << " ";
    cout << endl;
    return 0;
}