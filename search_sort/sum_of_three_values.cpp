#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;
#define ll long long

#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

#define debug(x) cout<<#x<<" :: "<<x<<endl;
#define debug2(x,y) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<endl;
#define debug3(x,y,z) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<endl;
#define debug4(p,q,r,s) cout<<#p<<" :: "<<p<<"\t"<<#q<<" :: "<<q<<"\t"<<#r<<" :: "<<r<<"\t"<<#s<<" :: "<<s<<endl;

bool targetSum(vector<vector<ll>> &a, ll x, ll idx, ll n) {
    ll left = 0, right = n-1;
    while(left < right) {
        if(a[left][1] == idx || a[right][1] == idx) {
            right--;
            continue;
        }
        if(a[left][0] + a[right][0] == x) {
            cout << a[left][1] << " " << a[right][1] << " " << idx << endl;
            return true;
        } else if (a[left][0] + a[right][0] < x) {
            left++;
        } else {
            right--;
        }
    }
    return false;
}


int main() {
    // Uncomment below for file input
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout); 
    fast;
    ll n, x;
    cin >> n >> x;
    vector<vector<ll>> a(n, vector<ll>(2));
    for(int i = 0; i < n; i++) {
        cin >> a[i][0];
        a[i][1] = i + 1;
    }
    sort(begin(a), end(a));
    for(auto val : a) {
        ll target = x - val[0];
        ll idx = val[1];
        if(targetSum(a, target, idx, n)) {
            return 0;
        }
    }
    cout << "IMPOSSIBLE" << endl;
}