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

vector<bool> isReachable(ll src, vector<vector<ll>> &adj, ll n) {
    vector<bool> res(n + 2, false);
    res[src] = true;
    queue<ll> q;
    q.push(src);
    while(!q.empty()) {
        auto u = q.front();
        q.pop();
        for(auto v : adj[u]) {
            if(!res[v]) {
                res[v] = true;
                q.push(v);
            }
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
    ll edges = m;
    vector<tuple<ll, ll, ll>> adj;
    vector<vector<ll>> forwardEdges(n + 2);
    vector<vector<ll>> backWardEdges(n + 2);
    while(m--) {
        ll u, v, w;
        cin >> u >> v >> w;
        adj.push_back(make_tuple(u, v, -w));
        forwardEdges[u].push_back(v);
        backWardEdges[v].push_back(u);
    }
    // Bellman Ford begins
    // Do it n-1 times initially
    vector<ll> dis(n + 2, INF);
    dis[1] = 0;
    vector<bool> onNegPath(n + 2, false);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < edges; j++) {
            ll u, v, w;
            tie(u, v, w) = adj[j];
            if(dis[u] + w < dis[v])
                dis[v] = dis[u] + w;
        }
    }
    // Now do Bellman Ford one more time to detect cycle nodes
    for(int j = 0; j < edges; j++) {
        ll u, v, w;
        tie(u, v, w) = adj[j];
        if(dis[u] + w < dis[v]) {
            onNegPath[v] = true;
            dis[v] = dis[u] + w;
        }
    }

    vector<bool> reachStart = isReachable(1, forwardEdges, n);
    vector<bool> reachEnd = isReachable(n, backWardEdges, n);

    for(int i = 1; i <= n; i++) {
        if(onNegPath[i] && reachStart[i] && reachEnd[i]) {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << -dis[n] << endl;
    return 0;
}