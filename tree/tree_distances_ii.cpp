#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;
#define ll long long

#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

#define debug(x) cout<<#x<<" :: "<<x<<endl;
#define debug2(x,y) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<endl;
#define debug3(x,y,z) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<endl;
#define debug4(p,q,r,s) cout<<#p<<" :: "<<p<<"\t"<<#q<<" :: "<<q<<"\t"<<#r<<" :: "<<r<<"\t"<<#s<<" :: "<<s<<endl;

/*
Rerooting Tree DP
*/

const int MAXN = (2 * 1e5) + 5;
vector<ll> sz, dp, res;
vector<vector<ll>> adj;

void dfs0(int u, int par) {
    dp[u] = 0;
    sz[u] = 1;
    for(auto v : adj[u]) {
        if(v != par) {
            dfs0(v, u);
            sz[u] += sz[v];
            dp[u] += dp[v] + sz[v];
        }
    }
}

void reroot(int from, int to) {
    dp[from] -= sz[to] + dp[to];
    sz[from] -= sz[to];

    sz[to] += sz[from];
    dp[to] += sz[from] + dp[from];
}

void dfs1(int u, int par) {
    res[u] = dp[u];
    for(auto v : adj[u]) {
        if(v != par) {
            reroot(u, v);
            dfs1(v, u);
            reroot(v, u);
        }
    }
}

int main() {
    // Uncomment below for file input
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout); 
    fast;
    ll n;
    cin >> n;
    adj.resize(n + 1);
    sz.resize(n + 1);
    dp.resize(n + 1);
    res.resize(n + 1);
    
    for(int i = 0; i < n-1; i++) {
        ll u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs0(0, -1);
    dfs1(0, -1);

    for(int i = 0; i < n; i++)
        cout << res[i] << " ";
    cout << endl;
    return 0;
}