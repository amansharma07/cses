#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;
#define ll long long

#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

#define debug(x) cout<<#x<<" :: "<<x<<endl;
#define debug2(x,y) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<endl;
#define debug3(x,y,z) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<endl;
#define debug4(p,q,r,s) cout<<#p<<" :: "<<p<<"\t"<<#q<<" :: "<<q<<"\t"<<#r<<" :: "<<r<<"\t"<<#s<<" :: "<<s<<endl;


// Option 1
// Dynamically check safe indices
bool isSafe(ll i, ll j, vector<vector<bool>> &vis) {
    for(int x = 0; x < j; x++) {
        if(vis[i][x])
            return false;
    }
    for(int x = 0; x < i; x++) {
        if(vis[x][j])
            return false;
    }
    ll x = i, y = j;
    while(x >= 0 && y >= 0) {
        if(vis[x][y])
            return false;
        x--;
        y--;
    }
    x = i, y = j;
    while(x >= 0 && y < 8) {
        if(vis[x][y])
            return false;
        x--;
        y++;
    }
    return true;
}

void backtrack(ll &res, set<pair<ll, ll>> &reserved, ll n, vector<vector<bool>> &vis) {
    if(n == 8) {
        res++;
        return;
    }
    for(int col = 0; col < 8; col++) {
        if(reserved.find({n, col}) == reserved.end() && isSafe(n, col, vis)) {
            vis[n][col] = true;
            backtrack(res, reserved, n+1, vis);
            vis[n][col] = false;
        }
    }
}

int main() {
    // Uncomment below for file input
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout); 
    fast;
    set<pair<ll, ll>> reserved;
    for(int i = 0; i < 8; i++) {
        string str;
        getline(cin, str);
        for(int j = 0; j < 8; j++) {
            if(str[j] == '*')
                reserved.insert({i, j});
        }
    }
    ll res = 0;
    vector<vector<bool>> vis(10, vector<bool>(10, false));
    backtrack(res, reserved, 0LL, vis);
    cout << res << endl;
    return 0;
}



/*
// Option 2
// Statically store columns and diagonals and use property to check


// occupiedCol[i] = true if there is a queen somewhere in the column i.
// occupiedPrimary[i] = true if there is a queen across the primary diagonal having (row + column = i). Value of (row + column) is same for all the cells lying on the same primary diagonal.
// occupiedSecondary[i] = true if there is a queen across the secondary diagonal having (row – column + 8 = i). Value of (row – column + 8 ) is same for all the cells lying on the same secondary diagonal.

bool isSafe(ll i, ll j, vector<bool> &occupiedCol, vector<bool> &occupiedPrimary, vector<bool> &occupiedSecondary) {
    if(occupiedCol[j] || occupiedPrimary[i - j + 8] || occupiedSecondary[i + j])
        return false;
    return true;
}

void backtrack(ll &res, set<pair<ll, ll>> &reserved, ll n, vector<bool> &occupiedCol, vector<bool> &occupiedPrimary, vector<bool> &occupiedSecondary) {
    if(n == 8) {
        res++;
        return;
    }
    for(int col = 0; col < 8; col++) {
        if(reserved.find({n, col}) == reserved.end() && isSafe(n, col, occupiedCol, occupiedPrimary, occupiedSecondary)) {
            occupiedCol[col] = occupiedPrimary[n - col + 8] = occupiedSecondary[n + col] = true;
            backtrack(res, reserved, n+1, occupiedCol, occupiedPrimary, occupiedSecondary);
            occupiedCol[col] = occupiedPrimary[n - col + 8] = occupiedSecondary[n + col] = false;
        }
    }
}

int main() {
    // Uncomment below for file input
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout); 
    fast;
    set<pair<ll, ll>> reserved;
    for(int i = 0; i < 8; i++) {
        string str;
        getline(cin, str);
        for(int j = 0; j < 8; j++) {
            if(str[j] == '*')
                reserved.insert({i, j});
        }
    }
    ll res = 0;
    vector<bool> occupiedCol(10, false), occupiedPrimary(20, false), occupiedSecondary(20, false);
    backtrack(res, reserved, 0LL, occupiedCol, occupiedPrimary, occupiedSecondary);
    cout << res << endl;
    return 0;
}
*/