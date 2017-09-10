//
//  main.cpp
//  044
//
//  Created by Alessandro Solbiati on 08/09/2017.
//  Copyright © 2017 Alessandro Solbiati. All rights reserved.
//

#include <iostream>

using namespace std;

int M,n,P[101],F[101];

int rec(int i,int m){
    if(i==n) return 0;
    if(m==0) return 0;
    if(P[i]>m) return rec(i+1,m);
    return max(rec(i+1,m), rec(i+1,m-P[i])+F[i]);
}

int main(int argc, const char * argv[]) {
    while (scanf("%d",&M)!=EOF) {
        scanf("%d",&n);
        for(int i=0;i<n;i++) scanf("%d %d",&P[i],&F[i]);

        printf("%d\n",rec());
    }
}
