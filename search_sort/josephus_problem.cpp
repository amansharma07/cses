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
    // 2 ---> 2 1
    // 3 ---> 2 1 3
    // 4 ---> 2 4 3 1
    // 5 ---> 2 4 1 5 3
    // 6 ---> 2 4 6 3 1 5
    // 7 ---> 2 4 6 1 5 3 7
    // 8 ---> 2 4 6 8 3 7 5 1
    // 9 ---> 2 4 6 8 1 5 9 7 3
    fast;
    ll n;
    cin >> n;
    queue<ll> q;
    for (int i = 1; i <= n; i++)
        q.push(i);

    bool flag = false;

    while (!q.empty()) {
        int num = q.front();
        q.pop();
        if (flag) {
            cout << num << " ";
        } else {
            q.push(num);
        }
        flag = !flag;
    }
    return 0;
}