// Problem: Book Shop
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1158
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


/*
	Author : SURYA HALDER
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
//#define int long long int
#define ff first
#define ss second
#define inf INT_MAX
#define sz size()
#define rtn return
#define rnt return
#define vi vector<int>
#define vvi vector<vector<int>>
#define vll vector<long long>
#define vvll vector<vector<long long>>
#define pb push_back
#define endl '\n'
#define maxheap priority_queue<int> //max heap
#define minheap priority_queue <int, vector<int>, greater<int>> //min heap
#define loop(i,a,b) for(int i=a;i<b;i++)     //for loop from a(included)->b(excluded)
#define roop(i,b,a) for(int i=b;i>=a;i--)    //rev. for loop from b(included)->a(inluded)
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

int dr[]={-1,0,1,0}; //up,left,down,right
int dc[]={0,-1,0,1};
bool in(int i,int j,int n,int m){
    rtn (i>=0 && i<n && j>=0 && j<m);
}
// int f(int ind,int x,vector<vector<int>>&dp){
	// if(ind==0){
		// if(x>=h[ind]) return s[ind];
		// else return 0;
	// }
	// if(dp[ind][x]!=-1) return dp[ind][x];
	// int op1=-1;
	// if(x>=h[ind]) op1=s[ind]+f(ind-1,x-h[ind],dp);
	// int op2=f(ind-1,x,dp);
	// return dp[ind][x]=max(op1,op2);
// }
int h[1001];
int s[1001];
int dp[1001][100001];
void solve() {
    /*Your code here */
    int n,x;
    cin>>n>>x;
    for(int i=0;i<n;i++) cin>>h[i];
    loop(i,0,n) cin>>s[i];
    // vector<vector<int>> dp(n,vector<int>(x+1,0));
    //cout<<f(n-1,x,dp)<<endl;
    for(int i=0;i<=x;i++){
    	if(i>=h[0]) dp[0][i]=s[0];
    }
    for(int i=1;i<n;i++){
    	for(int j=1;j<=x;j++){
    		int op1=-1;
    		if(j>=h[i]) op1=s[i]+dp[i-1][j-h[i]];
    		int op2=dp[i-1][j];
    		dp[i][j]=max(op1,op2);
    	}
    }
    cout<<dp[n-1][x]<<endl;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //==============Multi testcase==============//
    int t=1;
    //cin >> t;
    while (t--) {
        solve();
    }
    //==============comment till here==============//
    
    //==============ATCODER ALERT..don't forget to uncomment below==============//
    
    //solve();
    return 0;
}
