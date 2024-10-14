#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;
#define ll long long

#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

#define debug(x) cout<<#x<<" :: "<<x<<endl;
#define debug2(x,y) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<endl;
#define debug3(x,y,z) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<endl;
#define debug4(p,q,r,s) cout<<#p<<" :: "<<p<<"\t"<<#q<<" :: "<<q<<"\t"<<#r<<" :: "<<r<<"\t"<<#s<<" :: "<<s<<endl;

void topoSort(ll src, stack<ll> &st, vector<vector<ll>> &adj, vector<bool> &vis) {
    vis[src] = true;
    for(auto v : adj[src]) {
        if(!vis[v])
            topoSort(v, st, adj, vis);
    }
    st.push(src);
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
    stack<ll> st;
    vector<bool> vis(n + 2, false);
    for(ll i = 1; i <= n; i++) {
        if(!vis[i])
            topoSort(i, st, adj, vis);
    }
    while(!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
    return 0;
}