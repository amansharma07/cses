#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;
#define ll long long

#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

#define debug(x) cout<<#x<<" :: "<<x<<endl;
#define debug2(x,y) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<endl;
#define debug3(x,y,z) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<endl;
#define debug4(p,q,r,s) cout<<#p<<" :: "<<p<<"\t"<<#q<<" :: "<<q<<"\t"<<#r<<" :: "<<r<<"\t"<<#s<<" :: "<<s<<endl;

struct DSU
{
	int connected;
	vector<int> par, sz;

	void init(int n) 
	{
		par = sz = vector<int> (n + 1, 0);
		for(int i = 1; i <= n; i++)
			par[i] = i, sz[i] = 1;
		connected = n;
	}

	int getPar(int u)
	{
		while(u != par[u])
		{
			par[u] = par[par[u]];
			u = par[u];
		}
		return u;
	}

	int getSize(int u)
	{
		return sz[getPar(u)];
	}

	bool unite(int u, int v)
	{
		int par1 = getPar(u), par2 = getPar(v);

		if(par1 == par2)
			return 0;

		connected--;

		if(sz[par1] > sz[par2])
			swap(par1, par2);

		sz[par2] += sz[par1];
		sz[par1] = 0;
		par[par1] = par[par2];
        return 1;
	}
};


int main() {
    // Uncomment below for file input
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout); 
    fast;
    ll n, m;
    cin >> n >> m;
    vector<tuple<ll, ll, ll>> edges;
    for(ll i = 0; i < m; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w, u, v});
    }
    sort(edges.begin(), edges.end());
    ll ans = 0;
    DSU dsu;
    dsu.init(n);
    
    for(auto [w, u, v] : edges) {
        if(dsu.unite(u, v)) ans += w;
    }
    for(ll i = 1; i <= n; i++) {
        if(dsu.getSize(i) != n) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }
    cout << ans << "\n";
    return 0;
}