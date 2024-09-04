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
    string s;
    cin >> s;
    int n = (int)s.size();
    unordered_map<char, ll> has;
    string res = s;
    for(auto ch : s)
        has[ch]++;
    int beg = 0, end = n-1;
    string rep_chr = "";
    ll rep_chr_freq = 0;
    for(auto val : has) {
        char ch = val.first;
        ll freq = val.second;
        if((freq & 1) && rep_chr.length()) {
            cout << "NO SOLUTION" << endl;
            return 0;
        }
        if(freq & 1) {
            rep_chr += ch;
            rep_chr_freq = freq;
        }
        while(freq > 0 && (freq&1) == 0) {
            res[beg++] = ch;
            res[end--] = ch;
            freq -= 2;
        }
    }
    while (rep_chr_freq) {
        res[beg++] = rep_chr[0];
        rep_chr_freq--;
    }
    cout << res << endl;
    return 0;
}