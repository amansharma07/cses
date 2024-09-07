#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;
#define ll long long

#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

#define debug(x) cout<<#x<<" :: "<<x<<endl;
#define debug2(x,y) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<endl;
#define debug3(x,y,z) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<endl;
#define debug4(p,q,r,s) cout<<#p<<" :: "<<p<<"\t"<<#q<<" :: "<<q<<"\t"<<#r<<" :: "<<r<<"\t"<<#s<<" :: "<<s<<endl;

int main() {
    // Uncomment below for file input
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout); 
    // 1 3 5 4 2    ---> 12, 34, 5                 
    // 3 2 1        ---> 1, 2, 3                        
    // 6 4 3 1 2 5  ---> 12, 3, 45, 6
    // 6 3 1 2 5 4  ---> 12, 34, 5, 6
    // 1 2 3        ---> 123
    // 1 2 3 5 4    ---> 1234, 5
    // N and n+1 can be in same group only if N is before N+1
    fast;
    ll n;
    cin >> n;
    vector<vector<ll>> a(n, vector<ll>(2));
    for(int i = 0; i < n; i++) {
        cin >> a[i][0];
        a[i][1] = i;
    }
    sort(begin(a), end(a));
    ll res = 1;
    for(ll i = 1; i < n; i++) {
        if(a[i][1] < a[i-1][1])
            res++;
    }
    cout << res << endl;
    return 0;
}