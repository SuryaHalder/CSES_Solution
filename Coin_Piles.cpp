/*
	Author : SURYA HALDER
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long int
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
ll mod_pow(ll a,ll b){
    if(b==0) return 1;
    if(b%2){
        return a* mod_pow(a,b-1) %mod;
    }
    ll temp= mod_pow(a,b/2);
    return temp*temp %mod;
}
ll mod_mul(ll a,ll b){
    return ((a%mod) * (b%mod))%mod;
}
ll mod_add(ll a,ll b){
    return ((a%mod) + (b%mod))%mod;
}
ll mod_sub(ll a,ll b){
    return ((a%mod) - (b%mod))%mod;
}
ll mod_inv(ll a,ll b=mod-2){
    return mod_pow(a,b);
}
ll mod_div(ll a,ll b){
    int invb=mod_inv(b);
    return mod_mul(a,invb);
}
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

void solve() {
    /*Your code here */
    /* we cannot solve if max(a,b)>2*min(a,b)*/
    /*
     let chose l and r. 
     l-> 2 rem from left, 1 rem from right
	 r-> 2 rem from right 1 rem from left.
	 a=2*l+r;
	 b=2*r+l
	 a+b=3*(l+r);
	 l+r is total moves which must be integer
	 so (a+b) must be divisible by 3		
    
    */
    int a,b;
    cin>>a>>b;
    if(max(a,b)>2*min(a,b)){
    	no;
    	return;
    }
    else if((a+b)%3==0) yes;
    else no;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //==============Multi testcase==============//
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    //==============comment till here==============//
    
    //==============ATCODER ALERT..don't forget to uncomment below==============//
    
    //solve();
    return 0;
}
