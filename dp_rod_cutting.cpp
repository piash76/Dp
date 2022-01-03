///https://www.techiedelight.com/rod-cutting/


///Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>

using namespace std;


const int N=500005;
int len[N],pt[N],dp[N];
int n,rod_len;

int solve(int len)
{
    if(len==0) return 0;
    if(dp[len]!=-1) return dp[len];

    int mx=-1;

    for(int i=1;i<=rod_len;i++)
    {
        if(len-i>=0)
        {
            int s=pt[i]+solve(len-i);

            mx=max(s,mx);
        }
    }

    return dp[len]=mx;
}

int main()
{

    cin>>rod_len;

    for(int i=1;i<=rod_len;i++)
    {
        cin>>pt[i];
    }

    memset(dp,-1,sizeof(dp));


    int ans=solve(rod_len);
    cout<<ans<<endl;

    return 0;

}





