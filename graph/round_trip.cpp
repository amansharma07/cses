#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;
#define ll long long

#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

#define debug(x) cout<<#x<<" :: "<<x<<endl;
#define debug2(x,y) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<endl;
#define debug3(x,y,z) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<endl;
#define debug4(p,q,r,s) cout<<#p<<" :: "<<p<<"\t"<<#q<<" :: "<<q<<"\t"<<#r<<" :: "<<r<<"\t"<<#s<<" :: "<<s<<endl;

ll start, endi;

bool dfs(vector<vector<ll>> &adj, ll src, vector<bool> &vis, unordered_map<ll, ll> &par, ll parent) {
    auto u = src;
    vis[u] = true;
    for(auto v : adj[u]) {
        if(v == parent)
            continue;
        if(!vis[v]) {
            par[v] = u;
            if(dfs(adj, v, vis, par, par[v]))
                return true;
        } else {
            // Marking the correct start and end is important
            start = v;
            endi = u;
            return true;
        }
    }
    return false;
}

int main() {
    // Uncomment below for file input
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout); 
    fast;
    start = endi = -1;
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> adj(n + 2, vector<ll>());
    while(m--) {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool> vis(n + 2, false);
    unordered_map<ll, ll> par;
    ll flg = -1;
    for(int i = 0; i < n && flg; i++) {
        if(!vis[i] && dfs(adj, i, vis, par, par[i])) {
            break;
        }
    }
    if(start != -1) {
        vector<ll> res;
        res.push_back(start);
        // Always start from end to start as parent of start i.e. break point could have been different
        for(ll i = endi; i != start; i = par[i])
            res.push_back(i);
        res.push_back(start);
        cout << res.size() << endl;
        for(auto val : res)
            cout << val << " ";
        cout << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}