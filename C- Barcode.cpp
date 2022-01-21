
///Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>

#define ll long long
#define pll  pair<ll,ll>

#define ff    first
#define ss    second


#define  pb  push_back

#define cy  cout<<"YES"<<endl
#define cn   cout<<"NO"<<endl


using namespace std;

const ll inf=1e15;
const int mod=1e9+7;


const int N=500005;

int dp[1005][2],n,m,x,y;
int w[1005],b[1005];



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>n>>m>>x>>y;

    w[0]=b[0]=0;

    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            char ch;cin>>ch;
            if(ch=='#') b[j]++;
            else w[j]++;
        }
    }

    for(int j=1;j<=m;j++)
    {
         w[j]+=w[j-1];
        b[j]+=b[j-1];
    }





    int ans=


    cout<<ans<<endl;





    return 0;

}






