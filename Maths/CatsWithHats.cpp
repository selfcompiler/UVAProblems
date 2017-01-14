//
// Created by RAHUL KUMAR SINGH on 13/01/17.
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
LL dfs(int n,int m,LL sum){
    if(m<n){
        return -1;
    }
    if(m==n){
        return sum+n+1;
    }
    return  dfs(n,(m/n)+m%n,sum+n*(LL)floor(m*1.0/n));
}
int main(){
    int n,m;
    LL a;
    while(scanf("%d%d",&n,&m)&&(n||m)){
        cout<<n<<" "<<m<<" ";
    if(n==1 && m==1){
        cout<<"Multiple\n";
        continue;
    }
    if(n==1 && m>=2){
        cout<<"Impossible\n";
        continue;
    }
     if(m==1)
         a=1;
     else
        a=dfs(n,m,0);
     if(a==-1){
         cout<<"Impossible\n";
     }  else
        cout<<a<<"\n";
    }
    return 0;
}
