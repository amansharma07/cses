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
    vector<ll> a(n);
    vector<ll> res(n, 0);
    stack<ll> st;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = n-1; i >= 0; i--) {
        while(!st.empty() && a[st.top() - 1] > a[i]) {
            res[st.top() - 1] = i + 1;
            st.pop();
        }
        st.push(i + 1);
    }
    for(auto val : res)
        cout << val << " ";
    cout << endl;
    return 0;
}