#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(v) v.begin(), v.end()
#define pb push_back
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

const int minf = -1e18;

vector<int> dist;
vector<vector<int>> g;
vector<int> par;
vector<int> indeg; // stores indegrees of the nodes
void solve()
{
    int n, m;
    cin >> n >> m;
    g.resize(n + 1);
    dist.assign(n + 1, minf); // set all distances to minus infinity
    par.assign(n + 1, 0);
    indeg.assign(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].pb(b);
        indeg[b]++;
    }
    dist[1] = 0;
    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (indeg[i] == 0)
            q.push(i);
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        for (auto child : g[curr])
        {
            indeg[child]--;
            if (dist[child] < dist[curr] + 1)
            {
                dist[child] = dist[curr] + 1;
                par[child] = curr;
            }
            if (indeg[child] == 0)
                q.push(child);
        }
    }
    if (dist[n] < 0)
        cout << "IMPOSSIBLE"; // since number of nodes <=1e5 thus minf + anything will never give a positive distance
    else
    {
        vector<int> ans;
        int x = n;
        while (x != 0)
        {
            ans.pb(x);
            x = par[x];
        }
        reverse(all(ans));
        cout << ans.size() << "\n";
        for (auto &el : ans)
            cout << el << " ";
    }
}

int32_t main()
{
    FIO;
    clock_t tStart = clock();
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++)
    {
        // cout<<"Case #"<<i<<": ";
        solve();
    }
    // cerr<<fixed<<setprecision(6)<<"\nTime Taken: "<<(double)(clock()- tStart)/CLOCKS_PER_SEC<<endl;
}