//
// Created by RAHUL KUMAR SINGH on 14/01/17.
//

#include <cstdio>
#include <cmath>
#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <map>
#include <cassert>
#include <string>
#include <cstring>
#include <math.h>
#include <queue>
using  namespace std;

#define FOR(a,b) for(int i=a;i<=b;i++)
#define S(x) scanf("%d",&x)
#define S2(x,y) scanf("%d%d",&x,&y)
#define P(x) printf("%d\n",x)
#define all(v) v.begin(),v.end()
#define mp make_pair
#define pb push_back
#define FF first
#define SS second
#define PI 3.14159265
typedef long long int LL;
typedef int64_t i64;
#define INF 3999933999999
vector<LL> discount[305];
LL solve(int n,int m){
    LL dp[305][305];
    for(int i=0;i<=304;i++)
        for(int j=0;j<=304;j++)
            dp[i][j]=INF;
    for(int i=1;i<=m;i++){
        dp[1][i]=discount[1][i]+i*i;
    }
    for(int day=2;day<=n;day++){
        for(int cookie=day;cookie<=n;cookie++){
            for(int boughtCookie=0;boughtCookie<=m;boughtCookie++){
                if((cookie-boughtCookie)>0)
                    dp[day][cookie]=min(dp[day-1][cookie-boughtCookie]+boughtCookie*boughtCookie+discount[day][boughtCookie],dp[day][cookie]);
            }
        }
    }
    return dp[n][n];
}
int main(){
    int tc,n,m,cost;
    cin>>tc;
    for(int t=1;t<=tc;t++){
        cin>>n>>m;
        for(int i=1;i<=n;i++)
            discount[i].clear();

        for(int i=1;i<=n;i++){
            discount[i].push_back(0);
            for(int j=1;j<=m;j++){
                cin>>cost;
                discount[i].push_back(cost);
            }
            sort(discount[i].begin(),discount[i].end());
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++){
                discount[i][j]=discount[i][j-1]+discount[i][j];
            }
        }
        cout<<"Case #"<<t<<": "<<solve(n,m)<<endl;
    }
    return 0;
}
