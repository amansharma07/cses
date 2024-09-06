#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;
#define ll long long

#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

#define debug(x) cout<<#x<<" :: "<<x<<endl;
#define debug2(x,y) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<endl;
#define debug3(x,y,z) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<endl;
#define debug4(p,q,r,s) cout<<#p<<" :: "<<p<<"\t"<<#q<<" :: "<<q<<"\t"<<#r<<" :: "<<r<<"\t"<<#s<<" :: "<<s<<endl;

map<char, pair<int, int>> mp = {
    {'D', {1, 0}},
    {'U', {-1, 0}},
    {'L', {0, -1}},
    {'R', {0, 1}}
};

int dir[5] = {-1, 0, 1, 0, -1};

bool isSafe(int x, int y) {
    return x >= 0 && y >= 0 && x < 7 && y < 7;
}

// https://usaco.guide/problems/cses-1625-grid-paths/solution --- IMP

// What are these below ??

//  if( !isVisited(x+1,y) and !isVisited(x-1,y) and isVisited(x,y+1) and isVisited(x,y-1) ) { visited[x][y] = false;return;}
//  if( isVisited(x+1,y) and isVisited(x-1,y) and !isVisited(x,y+1) and !isVisited(x,y-1) ) { visited[x][y] = false;return;}

#define up 0
#define right 1
#define down 2
#define left 3

void recur(int x, int y, string &str, vector<vector<bool>> &vis, ll &res, int idx) {
    if(x == 6 && y == 0 && idx == (int)str.size()) {
    // && idx == (int)str.size()) {
        res++;
        return;
    }
    if(idx == (int)str.size())
        return;
    if((x == 6 && y == 0) || vis[x][y]) {
        return;
    }

    // Array to keep track of the visited status of the
    // neighboring cells
    vector<bool> visited(4, -1);
    for (int k = 0; k < 4; k++)
        if (isSafe(x + dir[k], y + dir[k + 1]))
            visited[k] = vis[x + dir[k]][y + dir[k + 1]];

    // If we are at a position such that the up and down
    // squares are unvisited and the left and right squares
    // are visited return
    if (!visited[down] && !visited[up] && visited[right]
        && visited[left])
        return;

    // If we are at a position such that the left and right
    // squares are unvisited and the up and down squares are
    // visited return
    if (!visited[right] && !visited[left] && visited[down]
        && visited[up])
        return;

    // If we are at a position such that the upper-right
    // diagonal square is visited and the up and right
    // squares are unvisited return
    if (isSafe(x - 1, y + 1)
        && vis[x - 1][y + 1] == 1)
        if (!visited[right] && !visited[up])
            return;

    // If we are at a position such that the lower-right
    // diagonal square is visited and the down and right
    // squares are unvisited return
    if (isSafe(x + 1, y + 1)
        && vis[x + 1][y + 1] == 1)
        if (!visited[right] && !visited[down])
            return;

    // If we are at a position such that the upper-left
    // diagonal square is visited and the up and left
    // squares are unvisited return
    if (isSafe(x - 1, y - 1)
        && vis[x - 1][y - 1] == 1)
        if (!visited[left] && !visited[up])
            return;

    // If we are at a position such that the lower-left diagonal
    // square is visited and the down and right squares are
    // unvisited return
    if (isSafe(x + 1, y - 1)
        && vis[x + 1][y - 1] == 1)
        if (!visited[left] && !visited[down])
            return;

    

    char ch = str[idx];
    vis[x][y] = true;
    int dx, dy;
    // debug4(x, y, idx, res);
    if(ch == '?') {
        for(int j = 0; j < 4; j++) {
            dx = x + dir[j];
            dy = y + dir[j + 1];
            if(isSafe(dx, dy)) {
                recur(dx, dy, str, vis, res, idx + 1);
            }
        }
    } else {
        dx = x + mp[ch].first;
        dy = y + mp[ch].second;
        if(isSafe(dx, dy)) {
            recur(dx, dy, str, vis, res, idx + 1);
        }
    }
    vis[x][y] = false;
}

int main() {
    // Uncomment below for file input
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout); 
    fast;
    string str;
    getline(cin, str);
    ll res = 0;
    vector<vector<bool>> vis(8, vector<bool>(8, false));
    auto start = chrono::high_resolution_clock::now();
    recur(0, 0, str, vis, res, 0);
    cout << res << endl;
    auto end = chrono::high_resolution_clock::now();
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
 
    time_taken *= 1e-9;
 
    // cout << "Time taken by program is : " << fixed 
        //  << time_taken << setprecision(9);
    // cout << " sec" << endl;
    return 0;
}