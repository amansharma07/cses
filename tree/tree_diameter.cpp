#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;
#define ll long long

#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

#define debug(x) cout<<#x<<" :: "<<x<<endl;
#define debug2(x,y) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<endl;
#define debug3(x,y,z) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<endl;
#define debug4(p,q,r,s) cout<<#p<<" :: "<<p<<"\t"<<#q<<" :: "<<q<<"\t"<<#r<<" :: "<<r<<"\t"<<#s<<" :: "<<s<<endl;

const int N = 2 * 1e5 + 5;
vector<ll> adj[N];
ll maxi = INT_MIN, farthest = 0;
vector<bool> vis(N, false);

void findFarthest(ll src, ll dis) {
    vis[src] = true;
    for(auto v : adj[src]) {
        if(!vis[v]) {
            if(dis >= maxi) {
                maxi = dis;
                farthest = v;
            }
            findFarthest(v, dis + 1);
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
    for(ll i = 0; i < n-1; i++) {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    maxi = 0;
    for (int i = 1; i <= n; ++i)
        vis[i] = false;
    findFarthest(1, 1);
    maxi = 0;
    for (int i = 1; i <= n; ++i)
        vis[i] = false;
    findFarthest(farthest, 1);
    cout << maxi << endl;
    return 0;
}