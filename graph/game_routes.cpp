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

vector<int> topoSort(vector<vector<ll>> &adj, ll n, vector<ll> &indeg) {
    vector<int> res;
    queue<ll> q;
    for(ll i = 1; i <= n; i++) {
        if(indeg[i] == 0)
            q.push(i);
    }
    while(!q.empty()) {
        auto u = q.front();
        q.pop();
        res.push_back(u);
        for(auto v : adj[u]) {
            indeg[v]--;
            if(indeg[v] == 0)
                q.push(v);
        }
    }
    return res;
}

int main() {
    // Uncomment below for file input
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout); 
    fast;
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> adj(n + 2);
    vector<ll> indeg(n + 2, 0);
    while(m--) {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        indeg[v]++;
    }
    vector<int> topoSortedNodes = topoSort(adj, n, indeg);
    if((ll) topoSortedNodes.size() != n) {
        // Graph contains a cycle
        return 0;
    }
    vector<ll> dp(n + 2, 0);
    dp[n] = 1;
    for(ll i = n - 1; i >= 0; i--) {
        for(auto v: adj[topoSortedNodes[i]]) {
            dp[topoSortedNodes[i]] += dp[v];
            dp[topoSortedNodes[i]] %= MOD;
        }
    }
    cout << dp[1] << endl;
    return 0;
}