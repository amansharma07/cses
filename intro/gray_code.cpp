#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;
#define ll long long

#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

#define debug(x) cout<<#x<<" :: "<<x<<endl;
#define debug2(x,y) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<endl;
#define debug3(x,y,z) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<endl;
#define debug4(p,q,r,s) cout<<#p<<" :: "<<p<<"\t"<<#q<<" :: "<<q<<"\t"<<#r<<" :: "<<r<<"\t"<<#s<<" :: "<<s<<endl;

void utils(bitset<32>& bits, vector<string>& result, int k, int n){
    if (k==0) {
        result.push_back(bits.to_string().substr(32-n));
    }
    else {
        utils(bits, result, k-1, n);
        bits.flip(k-1);
        utils(bits, result, k-1, n);
    }
}

vector<string> grayCode(int n) {
    bitset<32> bits;
    vector<string> result;
    utils(bits, result, n, n);
    return result;
}

int main() {
    // Uncomment below for file input
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout); 
    fast;
    ll n;
    cin >> n;
    vector<string> res = grayCode(n);
    for(auto val : res) {
        cout << val << endl;
    }
    return 0;
}