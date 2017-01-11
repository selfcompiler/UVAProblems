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
int divsum(int n){
    int sum=0;
    if(n==1)
        return 0;
    for(int i=1;i*i<=n;i++){
        if((n%i)==0){
            sum+=i;
            if(((i*i)!=n)&&(i>1))
              sum+=n/i;
        }
    }
    return sum;
}
int main(){
    int n,s;
    cin>>n;
    cout<<"PERFECTION OUTPUT\n";
    while(n){
        s=divsum(n);
        if(s==n){
            std::cout.width(5);
            std::cout << std::right<<n<<"  PERFECT\n";
        }
        else if(s<n){
            std::cout.width(5);
            std::cout << std::right<<n<<"  DEFICIENT\n";
        }
        else{
            std::cout.width(5);
            std::cout << std::right<<n<<"  ABUNDANT\n";
        }
        cin>>n;
    }
    cout<<"END OF OUTPUT\n";
    return 0;
}
