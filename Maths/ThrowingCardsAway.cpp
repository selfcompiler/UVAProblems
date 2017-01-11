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
        queue<int> q;
        int n,t;
        while(scanf("%d",&n)&&n>0){
            t=1;
            while(n>t){
                t=t*2;
            }
            if(n==t){
                cout<<t<<"\n";
                continue;
            }
            t=t/2;
            n=n-t;
            cout<<2*n<<endl;
        }
    return 0;
}
