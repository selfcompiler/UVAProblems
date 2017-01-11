//
// Created by RAHUL KUMAR SINGH on 26/12/16.
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
int main(){
    int n,k,s,l,tn;
    while(scanf("%d %d",&n,&k)==2){
        l=0;
        s=n;
        l=n%k;
        n=n/k;
        while(n){
            s+=n;
            tn=n;
            n=(tn+l)/k;
            l=(tn+l)%k;
        }
        cout<<s<<endl;
    }
    return 0;
}
