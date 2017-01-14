//
// Created by RAHUL KUMAR SINGH on 11/01/17.
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
    int n,m,t,a;
    int tc;
    cin>>tc;
    while(tc--){
        cin>>n>>m;
        if(n!=m){
            if(n%2)
                n++;
            if(m%2)
                m++;
            cout<<(n/2)*(m/2)<<"\n";
            continue;
        }
        if(n%2){
            t=(n/2)+1;
            a=(t*(t+1))/2;
            cout<<a<<"\n";
        }
        else{
            t=n/2;
            a=((t+1)*t)/2;
            cout<<a<<"\n";
        }
    }
    return 0;
}
