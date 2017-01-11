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
const double conv = 3.14159265 / 180;
int verticleComponent(int L,int v,int A,int s){
    int td=s*v;
    return int((L + v * cos(A * conv) * s) / (L * 2));
}
int horizontalComponent(int L,int v,int A,int s){
    int td=s*v;
    return int((L + v * sin(A * conv) * s) / (L * 2));
}
int main(){
    int a,b,v,A,s;
    while(scanf("%d%d%d%d%d",&a,&b,&v,&A,&s)&&(a||b||v||A||s)){
        cout<<verticleComponent(a, v, A, s)<<" "<<horizontalComponent(b, v, A, s)<<endl;
    }
    return 0;
}
