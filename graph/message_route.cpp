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
    vector<vector<ll>> adj(n + 2, vector<ll>());
    while(m--) {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    queue<pair<ll, ll>> q;
    vector<bool> vis(n + 2, false);
    unordered_map<ll, ll> par;
    q.push({n, 0});
    vis[n] = true;
    par[n] = -1;
    while(!q.empty()) {
        auto s = q.size();
        while(s--) {
            auto val = q.front();
            q.pop();
            auto u = val.first;
            auto dis = val.second;
            for(auto v : adj[u]) {
                if(!vis[v]) {
                    q.push({v, 1 + dis});
                    vis[v] = true;
                    par[v] = u;
                }
            }
        }
    }
    if(vis[1]) {
        vector<ll> res;
        ll u = 1;
        while(par[u] != -1) {
            res.push_back(u);
            u = par[u];
        }
        res.push_back(n);
        cout << res.size() << endl;
        for(auto val : res)
            cout << val << " ";
    } else {
        cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}