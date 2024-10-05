#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;
#define ll long long

#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

#define debug(x) cout<<#x<<" :: "<<x<<endl;
#define debug2(x,y) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<endl;
#define debug3(x,y,z) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<endl;
#define debug4(p,q,r,s) cout<<#p<<" :: "<<p<<"\t"<<#q<<" :: "<<q<<"\t"<<#r<<" :: "<<r<<"\t"<<#s<<" :: "<<s<<endl;

bool isSafe(int x, int y, int m, int n, vector<vector<char>> &grid) {
    return x >= 0 && x < m && y >= 0 && y < n && grid[x][y] != '#';
}

bool isBoundary(int x, int y, int m, int n) {
    return (x == 0) || x == (m - 1) || (y == 0) || y == (n - 1);
}

map<int, char> directionMap = {
    {2, 'L'},
    {3, 'U'},
    {0, 'R'},
    {1, 'D'}
};

map<pair<int, int>, int> directionInt = {
    {{0, 1}, 0},
    {{1, 0}, 1},
    {{0, -1}, 2},
    {{-1, 0}, 3}
};

map<int, pair<int, int>> revDirectionInt = {
    {0, {0, 1}},
    {1, {1, 0}},
    {2, {0, -1}},
    {3, {-1, 0}}
};

int dir[5] = {-1, 0, 1, 0, -1};

int main() {
    // Uncomment below for file input
    // freopen("test_input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout); 
    fast;

    ll n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    int par[n][m];
    pair<int, int> src;
    pair<int, int> des;
    
    vector<pair<ll, ll>> points;
    cin.ignore();
    for(int i = 0; i < n; i++) {
        string s;
        getline(cin, s);
        int j = 0;
        for(auto ch : s) {
            if(ch == 'A') {
                src.first = i;
                src.second = j;
            }
            if(ch == 'M') {
                points.push_back({i, j});
            }
            grid[i][j++] = ch;
            
        }
    }
    par[src.first][src.second] = -1;
    queue<tuple<ll, ll, ll>> q;
    for(auto val : points) {
        grid[val.first][val.second] = '#';
        q.push({val.first, val.second, 0});
    }
    q.push({src.first, src.second, 1});
    grid[src.first][src.second] = '#';
    bool flg = false;
    while (!q.empty()) {
        auto val = q.front();
        q.pop();
        auto x = get<0>(val);
        auto y = get<1>(val);
        auto hero = get<2>(val);
        
        if(hero && isBoundary(x, y, n, m)) {
            des = {x, y};
            flg = true;
            break;
        }
        for(int i = 0; i < 4; i++) {
            int dx = x + dir[i];
            int dy = y + dir[i+1];
            if(isSafe(dx, dy, n, m, grid)) {
                grid[dx][dy] = '#';
                pair<int, int> diff;
                diff.first = dx - x;
                diff.second = dy - y;
                par[dx][dy] = directionInt[diff];
                q.push({dx, dy, hero});
            }
        }
    }
    if(flg) {
        cout << "YES" << endl;
        string res = "";
        auto u = des;
        while(par[u.first][u.second] != -1) {
            auto parent = par[u.first][u.second];
            auto tem = revDirectionInt[parent];
            pair<int, int> diff;
            diff.first = u.first - tem.first;
            diff.second = u.second - tem.second;
            res += directionMap[parent];
            u = diff;
        }
        cout << res.size() << endl;
        reverse(begin(res), end(res));
        cout << res << endl;
    } else {
        cout << "NO" << endl;
    }
}