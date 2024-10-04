#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;
#define ll long long

#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

#define debug(x) cout<<#x<<" :: "<<x<<endl;
#define debug2(x,y) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<endl;
#define debug3(x,y,z) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<endl;
#define debug4(p,q,r,s) cout<<#p<<" :: "<<p<<"\t"<<#q<<" :: "<<q<<"\t"<<#r<<" :: "<<r<<"\t"<<#s<<" :: "<<s<<endl;

void dfs(vector<vector<ll>> &adj, ll src, vector<bool> &vis) {
    vis[src] = true;
    for(auto v : adj[src])
        if(!vis[v])
            dfs(adj, v, vis);
}

int main() {
    // Uncomment below for file input
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout); 
    fast;
    ll n, m;
    cin >> n >> m;
    if(n == 1) {
        cout << 0 << endl;
        return 0;
    }
    vector<vector<ll>> adj(n + 2, vector<ll>());
    vector<ll> res;
    vector<bool> vis(n + 2, false);
    while(m--) {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            res.push_back(i);
            dfs(adj, i, vis);
        }
    }
    ll k = (ll)res.size() - 1;
    cout << k << endl;
    if(k > 0) {
        cout << res[0] << " " << res[1] << endl;
        for(ll i = 2; i < res.size(); i++) {
            cout << res[i-1] << " " << res[i] << endl;
        }   
    }
    return 0;
}