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
int main(){
    int a,m,n;
    while(scanf("%d%d",&m,&n)==2){
        a=(n-1)+n*(m-1);
        cout<<a<<endl;
    }
    return 0;
}
