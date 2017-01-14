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
    int l,n;
    char str[1005];
    while(scanf("%s",str)==1){
        if(!strcmp(str,"0"))
            break;
        l=strlen(str);
        n=str[0]-48;
        if(l>1){
            if((l%2)==0){
                n=n*10+str[1]-48;
            }
        }
        l=(l-1)/2;
        cout<<(int)sqrt(n);
        while(l)
            putchar('0'),l--;
        cout<<"\n";
    }
    return 0;
}
