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
    ll sum = (n * (n + 1)) >> 1;
    if(sum & 1 || (n < 3)) {
        cout << "NO" << endl;
        return 0;
    }
    unordered_set<ll> st;
    unordered_set<ll> st2;
    sum /= 2;
    ll s1 = 0;
    for(int i = n; i >= 1; i--) {
        if(sum == s1)
            break;
        if(sum - s1 < i-1) {
            st.insert(sum-s1);
            break;
        }
        s1 += i;
        st.insert(i);
    }
    for(int i = n; i >= 1; i--) {
        if(st.find(i) == st.end())
            st2.insert(i);
    }
    cout << "YES" << endl;
    cout << st.size() << endl;
    for(auto val : st)
        cout << val << " ";
    cout << endl;
    cout << st2.size() << endl;
    for(auto val : st2)
        cout << val << " ";
    cout << endl;
    return 0;   
}