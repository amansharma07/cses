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
    ll n, m;
    cin >> n >> m;
    vector<vector<pair<ll, ll>>> adj(n + 2);
    while(m--) {
        ll u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    struct Position
    {
        ll node;
        ll cost;
        bool isCoupon;
    };
    auto comparator = [&](const Position &a, const Position &b){ return a.cost > b.cost; };
    priority_queue<Position, vector<Position>, decltype(comparator)> pq(comparator);
    pq.push({1, 0, false});
    vector<bool> vis(n + 2, false);
    vector<vector<ll>> dis(n + 2, vector<ll>(2, INF));
    // Distance vector with coupon used flag combined, no and yes
    dis[1][0] = 0;
    dis[1][1] = 0;
    while(!pq.empty()) {
        auto val = pq.top();
        pq.pop();
        if(vis[val.node])
            continue;
        vis[val.node] = true;
        if(val.node == n)
            break;
        for(auto vv : adj[val.node]) {
            auto v = vv.first;
            auto cost =  vv.second;
            if(!val.isCoupon) {
                ll newCost = val.cost + cost / 2;
                if(newCost < dis[v][1]) {
                    dis[v][1] = newCost;
                    pq.push({v, newCost, true});
                }
            }

            if(val.cost + cost < dis[v][val.isCoupon]) {
                dis[v][val.isCoupon] = val.cost + cost;
                pq.push({v, val.cost + cost, val.isCoupon});
            }
        }
    }
    cout << dis[n][1] << endl;
    return 0;
}