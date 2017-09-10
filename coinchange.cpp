//
//  main.cpp
//  047
//
//  Created by Alessandro Solbiati on 09/09/2017.
//  Copyright © 2017 Alessandro Solbiati. All rights reserved.
//

#include <iostream>

using namespace std;

int INF = 1 << 30;
int V=10,n=2,C[] = {1,5};

int memo[11];

int rec(int d){
    if(!d) return 0;
    if(d<0) return INF;
    if(memo[d]!=-1) return memo[d];
    int m=INF;
    for(int i=0;i<n;i++) m = min(m,rec(d - C[i]));
    return memo[d] = m+1;
}

int main(int argc, const char * argv[]) {
    memset(memo, -1, sizeof memo);
    printf("%d\n",rec(V));
}
