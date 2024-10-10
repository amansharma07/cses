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
    ll edges = m;
    vector<tuple<ll, ll, ll>> adj;
    vector<vector<ll>> forwardEdges(n + 2);
    vector<vector<ll>> backWardEdges(n + 2);
    while(m--) {
        ll u, v, w;
        cin >> u >> v >> w;
        adj.push_back(make_tuple(u, v, w));
        forwardEdges[u].push_back(v);
        backWardEdges[v].push_back(u);
    }
    // Bellman Ford begins
    // Do it n-1 times 

    /**
     * @brief 
     * Note that distance is taken as 0 and not infinity because
     * For this we need to put all the distance d[i] to zero and not infinity — as if we are looking for the shortest path 
     * from all vertices simultaneously; 
     * the validity of the detection of a negative cycle is not affected.
     * Do N iterations of Bellman-Ford algorithm. 
     * If there were no changes on the last iteration, there is no cycle of negative weight in the graph. 
     * Otherwise take a vertex the distance to which has changed, 
     * and go from it via its ancestors until a cycle is found. 
     * This cycle will be the desired cycle of negative weight.
     * 
     */
    vector<ll> dis(n + 2);
    vector<ll> par(n + 2, -1);
    ll x = -1;
    for(int i = 0; i < n; i++) {
        x = -1;
        for(int j = 0; j < edges; j++) {
            ll u, v, w;
            tie(u, v, w) = adj[j];
            if(dis[u] + w < dis[v]) {
                dis[v] = max(-INF, dis[u] + w);
                par[v] = u;
                x = v;
            }
        }
    }
    if(x == -1)
        cout << "NO" << endl;
    else {
        cout << "YES" << endl;
        for(int i = 1; i <= n; i++)
            x = par[x];
        vector<int> cycle;
        for (int v = x;; v = par[v]) {
            cycle.push_back(v);
            if (v == x && cycle.size() > 1)
                break;
        }
        reverse(cycle.begin(), cycle.end());
        
        for(auto val : cycle)
            cout << val << " ";
        cout << endl;
    }
    return 0;
}