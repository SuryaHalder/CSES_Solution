
/*
	Author : SURYA HALDER

    
    "I'm so lost in this problem, I might need a GPS to find my way out."
	"My love I know you are reading my code to get a path out of your errors, just like your presence in my life is a path out my errors,
	so please talk instead of ignoring me"
	"I may die today but for sure will be reborn tommorow like the phoenix"...
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
void inp(vector<T>& v) {
    for (auto& x : v) {
        cin >> x;
    }
}
template<typename T>
void out(const vector<T>& v) {
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

string dir="ULDR";
int dr[]={-1,0,1,0}; //up,left,down,right
int dc[]={0,-1,0,1};
bool in(int i,int j,int n,int m){
    rtn (i>=0 && i<n && j>=0 && j<m);
}

void solve() {
    /*Your code here */
    int n,m;
    cin>>n>>m;
    vector<vector<char>> a(n,vector<char>(m));
    vector<pair<int,int>> mons;
    pair<int,int> start;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
            if(a[i][j]=='M'){
                mons.pb({i,j});
            }
            if(a[i][j]=='A'){
                start={i,j};
            }
        }
    }
    vector<vector<int>> dism(n,vector<int>(m,inf));
    vector<vector<int>> dis(n,vector<int>(m,inf));
    queue<pair<int,int>> q;
    for(auto x:mons){
        q.push(x);
        dism[x.ff][x.ss]=0;
    }
    while(!q.empty()){
        auto x=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int r=x.ff+dr[i];
            int c=x.ss+dc[i];
            if(in(r,c,n,m) && dism[r][c]>(dism[x.ff][x.ss]+1) && a[r][c]!='#'){
                dism[r][c]=dism[x.ff][x.ss]+1;
                q.push({r,c});
            }
        }
    }
    //queue<pair<int,int>> q1;
    q.push(start);
    dis[start.ff][start.ss]=0;
    vector<vector<char>> mov(n,vector<char>(m,0));
    vector<vector<pair<int,int>>>parent(n,vector<pair<int,int>>(m,{-1,-1}));
    int endx=-1,endy=-1;
    while(!q.empty()){
        auto x=q.front();
        if(x.ff==0 || x.ff==n-1|| x.ss==0 ||x.ss==m-1){
            endx=x.ff;
            endy=x.ss;
            break;
        }
        q.pop();
        for(int i=0;i<4;i++){
            int r=x.ff+dr[i];
            int c=x.ss+dc[i];
            if(in(r,c,n,m) && dis[r][c]>(dis[x.ff][x.ss]+1) && a[r][c]!='#'){
                if(dism[r][c]>dis[x.ff][x.ss]+1){
                    dis[r][c]=dis[x.ff][x.ss]+1;
                    parent[r][c]={x.ff,x.ss};
                    mov[r][c]=dir[i];
                    q.push({r,c});
                }
            }
        }
    }
    if(endx==-1){
        no;
        rtn;
    }
    string ans;
    int x=endx,y=endy;
    while(x!=start.ff || y!=start.ss){
        ans.pb(mov[x][y]);
        int nx=parent[x][y].ff;
        int ny=parent[x][y].ss;
        x=nx;
        y=ny;
    }
    reverse(ans.begin(),ans.end());
    yes;
    cout<<ans.sz<<endl;
    cout<<ans<<endl;
    
    
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //==============Multi testcase==============//
    int t=1;
    //cin >> t;
    while (t--){
        solve();
    }
    //==============comment till here==============//
    
    //==============ATCODER ALERT..don't forget to uncomment below==============//
    
    //solve();
    return 0;
}
