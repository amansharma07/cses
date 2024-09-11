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
    fast;
    ll n;
    cin >> n;
    vector<vector<ll>> v(n, vector<ll>(2));
    for(int i = 0; i < n; i++)
        cin >> v[i][0] >> v[i][1];
    sort(begin(v), end(v)
    // , [](const vector<ll> &a, const vector<ll> &b) {
    //     ll diff1 = a[1]-a[0];
    //     ll diff2 = b[1]-b[0];
    //     if(diff1 != diff2)
    //         return diff1 > diff2;
    //     return a[0] < b[0];
    // }
    );

    /*
    If we perform T1 before T2, reward = (deadline(T1) – duration(T1)) + (deadline(T2) – duration(T1) – duration(T2)).
    So, reward1 = deadline(T1) + deadline(T2) – 2 * duration(T1) – duration(T2)
    If we perform T2 before T1, reward = (deadline(T2) – duration(T2)) + (deadline(T1) – duration(T2) – duration(T1)).
    So, reward2 = deadline(T1) + deadline(T2) – 2 * duration(T2) – duration(T1)

    We can see that one with lower duration will always give higher result
    */
    ll res = 0, finishing_time = 0;
    for(auto val : v) {
        // debug3(finishing_time, val[0], val[1]);
        finishing_time = finishing_time + val[0];
        res += val[1] - finishing_time;
    }
    cout << res << endl;
}