//
// Created by RAHUL KUMAR SINGH on 17/01/17.
//

//
// Created by RAHUL KUMAR SINGH on 17/01/17.
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
int arr[]={0,1,1,1,3,8,21,43,69,102,145}; //dart board Sequence;
int getDartBoardSequence(int n){
    int ans=0;
    if(n<=10)
        return arr[n];
    if(n%2){
            ans=n*n*n-16*n+27;
    }
    else{
        ans=n*n*n-16*n+30;
    }
    return ans/6;
}
int main(){
    int n,tc=1;
    while(scanf("%d",&n)&&n>0){
        cout<<"Case #"<<tc<<": "<<getDartBoardSequence(n)<<"\n";
        tc++;
    }
    return 0;
}
