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

void dfs(ll u, vector<ll> &subs) {
    for(auto v: adj[u]) {
        dfs(v, subs);
        subs[u] = 1 + subs[u] + subs[v];
    }
}

int main() {
    // Uncomment below for file input
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout); 
    fast;
    ll n;
    cin >> n;
    
    vector<ll> subs(N, 0);
    for(ll i = 2; i <= n; i++) {
        ll val;
        cin >> val;
        adj[val].push_back(i);
    }
    dfs(1, subs);
    for(ll i = 1; i <= n; i++)
        cout << subs[i] << " ";
    cout << endl;
    return 0;

}