//
// Created by RAHUL KUMAR SINGH on 15/12/16.
//

#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <map>
#include <utility>
#include <set>
using  namespace std;
typedef long long int  LL;
LL getsum(LL n){
    return (n*(n+1))/2;
}
int main(){
    long long int n;
    long long int high;
    long long int low=0;
    long long int middle;
    long long int sum,ans=0;
    int tc;
    cin>>tc;
    while(tc--) {
         high=10000000000;
         low=0;
         ans=0;
        cin >> n;
        while (low <= high) {
            middle = (low + high) / 2;
            sum=getsum(middle);
            if (sum<=n) {
                ans = middle;
                low = middle + 1;
            } else {
                high = middle - 1;
            }

        }
        cout << ans << endl;
    }
    return 0;
}
