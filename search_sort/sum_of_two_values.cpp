#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;
#define ll long long

#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

#define debug(x) cout<<#x<<" :: "<<x<<endl;
#define debug2(x,y) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<endl;
#define debug3(x,y,z) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<endl;
#define debug4(p,q,r,s) cout<<#p<<" :: "<<p<<"\t"<<#q<<" :: "<<q<<"\t"<<#r<<" :: "<<r<<"\t"<<#s<<" :: "<<s<<endl;

/*
int main() {
    // Uncomment below for file input
    // freopen("test_input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout); 
    fast;
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n);
    unordered_map<ll, ll> mp;
    ll c = 0;
    for(int i = 0; i < n && x > 1; i++) {
        cin >> a[i];
        if(a[i] >= x)
            continue;
        mp[a[i]]++;
        if(a[i] < x)
            c++;
    }
    for(int i = 0; i < n && c >= 2; i++) {
        if(a[i] >= x)
            continue;
        mp[a[i]]--;
        if(mp[x-a[i]] > 0) {
            int j;
            for(j = 0; j < n; j++) {
                if(j == i)
                    continue;
                if(a[j] == (x-a[i]))
                    break;
            }
            cout << i + 1 << " " << j + 1 << endl;
            return 0;
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}
*/

// Option 2 by sorting

int main() {
    // Uncomment below for file input
    // freopen("test_input.txt", "r", stdin); 
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
    ll left = 0, right = n - 1;
    while(left < right) {
        if(a[left][0] + a[right][0] == x) {
            cout << a[left][1] << " " << a[right][1] << endl;
            return 0;
        } else if (a[left][0] + a[right][0] < x) {
            left++;
        } else {
            right--;
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}