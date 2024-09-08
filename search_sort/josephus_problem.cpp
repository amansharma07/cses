#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;
#define ll long long


#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> 

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


    // Option 1
    /*
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
    cout << endl << endl;
    */

    // Option 2
    ordered_set o_set;
    ll i = 0, c = n;
    for(int i = 1; i <= n; i++)
        o_set.insert(i);
    while(c) {
        i = (i + 1) % c;
        auto it = o_set.find_by_order(i);
        cout << *it << " ";
        o_set.erase(it);
        c--;
    }
    return 0;
}