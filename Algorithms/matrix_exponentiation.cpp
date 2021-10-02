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

struct Matrix{

    // defining a new matrix
    vector<vector<int>> mat;
    int n_row,n_col;
    
    // initialing matrix with 2D vector
    Matrix(vector<vector<int>>& val):mat(val),n_row(val.size()),n_col(val[0].size()){}

    // function to create an identity matrix of size n;
    static Matrix identity_matrix(int n){
        vector<vector<int>> iden(n,vector<int>(n,0));
        for(int i = 0; i < n; i++){
            iden[i][i] = 1;
        }

        return iden;
    }

    // function to multiply two different matrix
    Matrix operator*(const Matrix& other) const{
        assert(this->n_col == other.n_row);
        int n = n_row, m = other.n_col;
        vector<vector<int>> result(n,vector<int>(m,0));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                for(int k = 0; k < this->n_col; k++){
                    result[i][j] = ((ll)result[i][j] + 1LL * this->mat[i][k] * other.mat[k][j]) % MOD;
                }
            }
        }
        return Matrix(result);
    }

    // function to check if matrix is square
    inline bool is_square() const{
        return this->n_row == this->n_col;
    }


};

// function to raise matrix to a power
Matrix fast_exponentiation(Matrix m, ll power){
    assert(m.is_square());
    Matrix result = Matrix::identity_matrix(m.n_row);

    while(power){
        if(power&1){
            result = result*m;
        }
        m = m*m;
        power>>=1;
    }

    return result;
}


void solve(){
    vvi arr = {
        {1,1},
        {1,0}
    };
    Matrix mat(arr);
    Matrix res = fast_exponentiation(mat,3);
    vvi init = {
        {1},
        {0}
    };
    Matrix init_m = Matrix(init);
    Matrix final_res = res * init_m;
    cout<<final_res.mat[0][0];
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
