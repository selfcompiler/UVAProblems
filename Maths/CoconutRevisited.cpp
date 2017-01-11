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
typedef int64_t i64;
int main(){
    int n;
    while((scanf("%d",&n)==1)&&(n>=0)){
        printf("%d coconuts, ", n);
        int sol=0,i,j;
        int sq=(int)sqrt(n)+1;
        for(i=sq;i>=2;i--){
            int ans=n;
            for(j=1;j<=i;j++){
                if(ans%i!=1)
                    break;
                ans=ans - ans/i - 1 ;
            }
            if(j==i+1 && ans%i==0){
                sol = 1;
                printf("%d people and 1 monkey\n", i);
                break;
            }
        }
        if(!sol)
            puts("no solution");
    }
    return 0;
}
