#include<bits/stdc++.h>
using namespace std;

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
  
// #define ordered_set tree<pi, null_type,less<pi>, rb_tree_tag,tree_order_statistics_node_update> 

#define ll long long
#define ull unsigned ll
#define pi pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vll vector<ll>
#define vb vector<bool>
#define vd vector<double>
#define vs vector<string>
#define vvi vector<vi>
#define vvll vector<vll>
#define ff first
#define ss second
#define pb push_back
#define vpi vector<pi>
#define vpll vector<pll>
#define umap unordered_map
#define uset unordered_set
#define all(x) x.begin(),x.end()
#define fr(i,j,n) for(int i=j;i<n;++i)
#define rfr(i,j,n) for(int i=j; i>=n;--i)
#define MOD 1000000007
#define INF INT_MAX
#define LINF LONG_LONG_MAX  
#define mp make_pair
#define endl "\n"
#define sz  size()
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

vb segmentedSieve(ll L, ll R){
    ll lim = sqrt(R);
    vll prime;
    vb isprime(R+1,true);

    for(ll i=2;i<lim+1;i++){
        if(isprime[i]){
            prime.pb(i);
            for(ll j = i*i;j<=lim;j+=i){
                isprime[j] = false;
            }
        }
    }
    vb Prime(R-L+1,true);
    for(auto p : prime){
        for(ll j = max(p*p, (L+p-1)/p*p);j<=R; j+= p){
            Prime[j-L] = false;
        }
    }
    if(L == 1){
        Prime[0] = false;
    }
    return Prime;
}


void solve(){
    int l,r;
    cin>>l>>r;
    vb res = segmentedSieve((ll)l,(ll)r);
    for(int i = 0;i<res.sz;i++){
        if(res[i]){
            cout<<l+i<<endl;
        }
    }
}

void pre() {
    int t = 1;
    // cin>>t;
    fr(i,0,t){
        // cout<<"Case #"<<i+1<<": ";
        solve();
        // cout<<solve()<<endl;
    }
}

int main() {
	fastIO; 

	auto start = clock();

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	pre();

	double used= (double) (clock()-start);
    used=(used*1000)/CLOCKS_PER_SEC;
    cerr<<fixed<<setprecision(2)<<used<<" ms"<<endl;

	return 0; 
	
}
