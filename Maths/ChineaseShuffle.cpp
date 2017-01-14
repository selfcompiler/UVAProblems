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
typedef long long int LL;
LL powmod(LL a,LL n,LL mod){
    LL ans=1;
    while(n){
        if(n&1){
            ans=(ans*a)%mod;
        }
        a=(a*a)%mod;
        n=n/2;
    }
    return ans;
}
int main(){
LL n;
    while(scanf("%lld",&n)&&(n!=-1)){
        if (powmod(2, n-1, n) == 1)
            printf("%lld is a Jimmy-number\n", n);
        else
            printf("%lld is not a Jimmy-number\n", n);
    }
}
