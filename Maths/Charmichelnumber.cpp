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
int num[]={561, 1105, 1729, 2465, 2821, 6601, 8911, 10585, 15841, 29341, 41041, 46657, 52633, 62745, 63973, 75361, 101101};
bool isCarmichael(int n){
    for(int i=0;i<17;i++)
        if(num[i]==n)
            return true;
    return false;
}
int main(){
    int n;
    while (scanf("%d",&n)&&n>0){
        if(isCarmichael(n)){
            cout<<"The number "<<n<<" is a Carmichael number.\n";
        }
        else{
            cout<<n<<" is normal.\n";
        }
    }
    return 0;
}
