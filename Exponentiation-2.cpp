/*
	Author : SURYA HALDER
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long int
#define ff first
#define ss second
#define inf INT_MAX
#define vi vector<int>
#define vvi vector<vector<int>>
#define vll vector<long long>
#define vvll vector<vector<long long>>
#define pb push_back
#define endl '\n'
#define maxheap priority_queue<int> //max heap
#define minheap priority_queue <int, vector<int>, greater<int>> //min heap
#define rep(i,a,b) for(int i = a; i <= b; i++)
#define reprev(i,a,b) for(int i=a;i>=b;i--)
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

//==============Modular arithematic==============//

const int mod=1000000000+7; 
ll mod_mul(ll a,ll b){
    return ((a%mod) * (b%mod))%mod;
}
ll mod_add(ll a,ll b){
    return ((a%mod) + (b%mod))%mod;
}
ll mod_sub(ll a,ll b){
    return ((a%mod) - (b%mod))%mod;
}
// ll mod_inv(ll a,ll b=mod-2){
    // return mod_pow(a,b);
// }
// ll mod_div(ll a,ll b){
    // int invb=mod_inv(b);
    // return mod_mul(a,invb);
// }
//==============End of Modular Arithematic==============//

//==============i/p and o/p==============//
template<typename T>
void input(vector<T>& v) {
    for (auto& x : v) {
        cin >> x;
    }
}
template<typename T>
void output(const vector<T>& v) {
    for (const auto& x : v) {
        cout << x << " ";
    }
    cout << '\n';
}
//==============end of i/p and o/p==============//

//==============sorting==============//
template<typename T>
void sortA(vector<T>& v) {
    sort(v.begin(), v.end());
}

template<typename T>
void sortD(vector<T>& v) {
    sort(v.begin(), v.end(), greater<T>());
}
//==============End of sorting==============//
ll mod_pow(ll a,ll b,ll mod){
    if(b==0) return 1;
    if(b%2){
        return a* mod_pow(a,b-1,mod) %mod;
    }
    ll temp= mod_pow(a,b/2,mod);
    return temp*temp %mod;
}
void solve() {
    /*Your code here */
    int a,b,c;
    cin>>a>>b>>c;
    
    int val=mod_pow(b,c,mod-1);
    cout<<mod_pow(a,val,mod)<<endl;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //==============Multi testcase==============//
    int t=1;
    cin >> t;
    while (t--) {
        solve();
    }
    //==============comment till here==============//
    
    //==============ATCODER ALERT..don't forget to uncomment below==============//
    
    //solve();
    return 0;
}
