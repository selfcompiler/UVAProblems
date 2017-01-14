//
// Created by RAHUL KUMAR SINGH on 14/01/17.
//
// ans=n-n/k+n/k*k-n/k*k*k+....
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
int main(){
    LL a,n,k,tc;
    bool flag=true;
    cin>>tc;
    while(tc--){
        cin>>n>>k;
        a=0;
        flag=true;
        while(n>0){
            if(flag)
            { a+=n;flag= false;}
            else
            {a-=n;flag=true;}
            n=n/k;
        }
        cout<<a<<endl;
    }
    return 0;
}
