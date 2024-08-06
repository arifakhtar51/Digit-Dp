#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define cl cout<<endl;
#define cy cout<<"YES"<<endl;
#define cn cout<<"NO"<<endl;
#define cyr cout<<"YES"<<endl; return ;
#define cnr cout<<"NO"<<endl; return ;
#define vll vector<ll>
#define srt(x) sort(begin(x),end(x))
#define vi vector<int>
#define rev(x) reverse(begin(x),end(x))
#define printarr(arr) for(int i=0;i<arr.size();i++)cout<<arr[i]<<" ";
#define sortr(x) sort(rbegin(x),rend(x))
#define vpll vector<pair<ll,ll>>
#define um unordered_map<ll,ll>
#define IOS                \
ios::sync_with_stdio(0); \
cin.tie(0);              \
cout.tie(0);
const ll MOD = 1e9 + 7;
int dp[20][2][20] ;    //index , tight=0 or 1 , cnt=ans can upto(20 digit count ex: 3 3 3 3 3 3 3.. 3)
ll f(ll i,ll tight,ll cnt,string &s){
    if(i>=s.size()){
        return cnt;
    }
    if(dp[i][tight][cnt]!=-1){
        return dp[i][tight][cnt];
    }
    ll limit=(tight==1)?s[i]-'0':9;
    ll ans=0;

    for(int j=0;j<=limit;j++){
        // ll updateCnt=cnt+(j==3?1:0); isme n-33 hai to ans =2 (each digit 3 count krega)
        ll updateCnt=cnt+(j==3)?1:0;//agar 3 hai digit me then increm your ans
        ans+=f(i+1, tight & (j==s[i]-'0'), updateCnt,s);
    }

    return dp[i][tight][cnt]=ans;


}


void solve(){
    
    ll l ,r;
    cin>>l>>r;

    // 0----L----------R
    // R-L= f(R)-f(L-1);

    memset(dp,-1,sizeof(dp));
    string s=to_string(r);
    ll temp=f(0,1,0,s);
    memset(dp,-1,sizeof(dp));
    s=to_string(l);
    ll temp2=f(0,1,0,s);


    ll ans=temp-temp2;
    cout<<ans;cl;





}
int main(){
    IOS
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int t=1;
    // cout<<string(3,'1');
    cin>>t;
    while(t--){

        solve();

    }

}