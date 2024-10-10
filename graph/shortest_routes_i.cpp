#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;
#define ll long long

#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

#define debug(x) cout<<#x<<" :: "<<x<<endl;
#define debug2(x,y) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<endl;
#define debug3(x,y,z) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<endl;
#define debug4(p,q,r,s) cout<<#p<<" :: "<<p<<"\t"<<#q<<" :: "<<q<<"\t"<<#r<<" :: "<<r<<"\t"<<#s<<" :: "<<s<<endl;

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
    priority_queue<pair<ll, ll>> pq;
    pq.push({0, 1});
    vector<ll> dis(n + 2, 1e18);
    dis[1] = 0;
    vector<bool> vis(n + 2, false);
    while(!pq.empty()) {
        auto val = pq.top();
        pq.pop();
        auto u = val.second;
        if(vis[u])
            continue;
        vis[u] = true;
        for(auto vv : adj[u]) {
            auto v = vv.first;
            auto wei = vv.second;
            if(dis[u] + wei < dis[v]) {
                dis[v] = dis[u] + wei;
                pq.push({-dis[v], v});
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        cout << dis[i] << " ";
    }
    cout << endl;
    return 0;
}