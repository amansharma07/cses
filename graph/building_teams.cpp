#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;
#define ll long long

#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

#define debug(x) cout<<#x<<" :: "<<x<<endl;
#define debug2(x,y) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<endl;
#define debug3(x,y,z) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<endl;
#define debug4(p,q,r,s) cout<<#p<<" :: "<<p<<"\t"<<#q<<" :: "<<q<<"\t"<<#r<<" :: "<<r<<"\t"<<#s<<" :: "<<s<<endl;

bool bfs(vector<vector<ll>> &adj, ll src, vector<ll> &res) {
    queue<pair<ll, ll>> q;
    q.push({src, 1});
    while(!q.empty()) {
        auto s = q.size();
        while(s--) {
            auto val = q.front();
            q.pop();
            auto u = val.first;
            auto team = val.second;
            res[u] = team;
            for(auto v : adj[u]) {
                if(res[v] == -1) {
                    q.push({v, 3 - team});
                } else if(res[v] == team) {
                    return false;
                }
            }
        }
    }
    return true;
}

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
    vector<ll> res(n + 2, -1);
    bool flg = true;
    for(int i = 0; i < n && flg; i++) {
        if(res[i] == -1) {
            flg &= bfs(adj, i, res);
        }
    }
    if(flg) {
        for(int i = 1; i <= n; i++)
            cout << res[i] << " ";
        cout << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}