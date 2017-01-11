//
// Created by RAHUL KUMAR SINGH on 09/01/17.
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
int main(){
    int n,tc;
    cin>>tc;
    for(int k=0;k<tc;k++){
    double a0,an,ans,csum=0.0,c;
    cin>>n;
    cin>>a0;
    cin>>an;
    for(int i=0;i<n;i++){
        cin>>c;
        csum+=c*2*(n-i);
    }
    ans=n*a0+an-csum;
    ans=ans/(n+1);
    printf("%.2lf\n",ans);
        if(k!=(tc-1))
            cout<<"\n";
    }
    return 0;
}
