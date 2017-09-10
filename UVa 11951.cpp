//
//  main.cpp
//  038
//  UVa 11951
//  Created by Alessandro Solbiati on 04/09/2017.
//  Copyright © 2017 Alessandro Solbiati. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    int TC,N,M,K,count=0;
    int a[100][100];
    cin >> TC;
    while(TC--){
        cin >> N >> M >> K;
        for(int i=0;i<N;i++)
            for(int j=0;j<M;j++){
                cin >> a[i][j];
                if(i>0) a[i][j] += a[i-1][j];
                if(j>0) a[i][j] += a[i][j-1];
                if(i>0&&j>0) a[i][j] -= a[i-1][j-1];
            }
        
        int ans=0,sum=0,w=0,h=0;
        
        for(int i=0;i<N;i++) for(int j=0;j<M;j++){
            for(int k=0;k<i;k++) for(int l=0;l<j;l++){
                sum = a[i][j];
                if(k>0) sum -= a[k-1][j];
                if(l>0) sum -= a[i][l-1];
                if(k>0&&l>0) sum += a[k-1][l-1];
        
                
                if(i-k>=w && j-l>=h && sum<K){
                    ans = sum;
                    w=i-k;
                    h=j-l;
                }
         
                
            }
        }
        count++;
        printf("Case #%d: %d %d\n", count,w*h,ans);
    }
    
}


