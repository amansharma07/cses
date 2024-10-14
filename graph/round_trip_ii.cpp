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

bool dfs(ll src, vector<vector<ll>> &adj, vector<ll> &par, vector<char> &color) {
    color[src] = 1;
    for(auto v : adj[src]) {
        if(color[v] == 0) {
            par[v] = src;
            if(dfs(v, adj, par, color))
                return true;
        } else if(color[v] == 1) {
            // Marking the correct start and end is important
            start = v;
            endi = src;
            return true;
        }
    }
    color[src] = 2;
    return false;
}

int main() {
    // Uncomment below for file input
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout); 
    fast;
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> adj(n + 2);
    while(m--) {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    vector<char> color(n + 2, 0);
    vector<ll> par(n + 2, -1);
    start = -1;
    for(ll i = 1; i <= n; i++) {
        if(color[i] == 0 && dfs(i, adj, par, color))
            break;
    }
    if(start != -1) {
        vector<ll> res;
        res.push_back(start);
        // Always start from end to start as parent of start i.e. break point could have been different
        for(ll i = endi; i != start; i = par[i])
            res.push_back(i);
        res.push_back(start);
        reverse(begin(res), end(res));
        cout << res.size() << endl;
        for(auto val : res)
            cout << val << " ";
        cout << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}