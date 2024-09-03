#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;
#define ll long long

#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

#define debug(x) cout<<#x<<" :: "<<x<<endl;
#define debug2(x,y) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<endl;
#define debug3(x,y,z) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<endl;
#define debug4(p,q,r,s) cout<<#p<<" :: "<<p<<"\t"<<#q<<" :: "<<q<<"\t"<<#r<<" :: "<<r<<"\t"<<#s<<" :: "<<s<<endl;

int dir[5] = {-1, 0, 1, 0, -1};

bool isSafe(int x, int y, int m, int n) {
    return x >=0 && y >=0 && x < m && y < n;
}

void dfs(int x, int y, vector<vector<char>> &grid, vector<vector<bool>> &vis) {
    vis[x][y] = true;
    int m = grid.size();
    int n = grid[0].size();
    for(int i = 0; i < 4; i++) {
        int dx = x + dir[i];
        int dy = y + dir[i + 1];
        if(isSafe(dx, dy, m, n) && grid[dx][dy] == '.' && !vis[dx][dy])
            dfs(dx, dy, grid, vis);
    }
}

int main() {
    // Uncomment below for file input
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout); 
    fast;
    ll m, n;
    cin >> m >> n;
    vector<vector<char>> grid(m, vector<char>(n));
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    vector<vector<bool>> vis(m, vector<bool>(n, false));
    int c = 0;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(!vis[i][j] && grid[i][j] == '.') {
                c++;
                dfs(i, j, grid, vis);
            }
        }
    }
    cout << c << endl;
    return 0;
}