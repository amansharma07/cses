#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;
#define ll long long

#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

#define debug(x) cout<<#x<<" :: "<<x<<endl;
#define debug2(x,y) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<endl;
#define debug3(x,y,z) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<endl;
#define debug4(p,q,r,s) cout<<#p<<" :: "<<p<<"\t"<<#q<<" :: "<<q<<"\t"<<#r<<" :: "<<r<<"\t"<<#s<<" :: "<<s<<endl;

void recur(ll n, ll from, ll aux, ll to) {
    if(n == 1) {
        cout << from << " " << to << endl;
        return;
    }
    // Moving : FROM TO AUX, aux changes to remaining one
    recur(n-1, from, to, aux);
    cout << from << " " << to << endl;
    // Moving : AUX TO TO, aux changes to remaining one
    recur(n-1, aux, from, to);
}

int main() {
    // Uncomment below for file input
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout); 
    fast;
    int n;
    cin >> n;
    ll mini = pow(2, n) - 1;
    cout << mini << endl;
    recur(n, 1LL, 2LL, 3LL);
}