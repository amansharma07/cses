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
    int n, m;
    cin >> n >> m;
    DSU dsu;
    dsu.init(n);
    int res = n, sz = 1;
    while(m--) {
        int x, y;
        cin >> x >> y;
        if(dsu.unite(x, y)) {
            sz = max(sz, dsu.getSize(x));
            res--;
        }
        cout << res << " " << sz << endl;
    }
    return 0;
}