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
    ll n, m, q;
    cin >> n >> m >> q;
    vector<vector<ll>> dis(n + 2, vector<ll>(n + 2, INF));
    vector<vector<ll>> adj(n + 2, vector<ll>(n + 2, INF));
    while(m--) {
        ll u, v, w;
        cin >> u >> v >> w;
        if(w < dis[u][v]) {
            adj[u][v] = w;
            adj[v][u] = w;
            dis[u][v] = w;
            dis[v][u] = w;
        }
    }
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(i == j)
                    dis[i][j] = 0;
                else if(dis[i][k] < INF && dis[k][j] < INF)
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    while(q--) {
        ll a, b;
        cin >> a >> b;
        cout << (dis[a][b] < INF ? dis[a][b] : -1) << endl;
    }
    return 0;
}