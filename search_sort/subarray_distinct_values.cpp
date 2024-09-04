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
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    ll res = 0, dis_count = 0, left = 0, right = 0;
    unordered_map<ll, ll> mp;
    while(right < n) {
        if(!mp.count(a[right]) || mp[a[right]] == 0) {
            dis_count++;
        }
        mp[a[right]]++;
        while (dis_count > k)
        {
            mp[a[left]]--;
            if(mp[a[left]] == 0)
                dis_count--;
            left++;
        }
        res += (right - left + 1);
        right++;
    }
    cout << res << endl;
    return 0;
}