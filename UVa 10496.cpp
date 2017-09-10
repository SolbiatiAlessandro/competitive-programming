//
//  main.cpp
//  041
//
//  Created by Alessandro Solbiati on 06/09/2017.
//  Copyright © 2017 Alessandro Solbiati. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int dist[100][100],n;

int memo[101][1 << 11];


int tsp(int pos, int mask){
    if(mask==((1 << (n+1)) - 1)) return memo[pos][mask] = dist[pos][0];
    if(memo[pos][mask]!=-1) return memo[pos][mask];
    
    
    else{
        int m=10000000;
        for(int i=0;i<=n;i++)
            if (i!=pos && 0==(mask&(1<<i)))
                m = min(m,dist[pos][i] + tsp(i,mask | (1<<i)));
            
            
        return memo[pos][mask] = m;
    }
    
}

int main(int argc, const char * argv[]) {
    tuple<int,int> e;
    vector<tuple<int,int>> coo;
    
    int TC;
    cin >> TC;
    while(TC--){
    
        coo.clear();
        
        cin >> get<0>(e) >> get<1>(e);
        cin >> get<0>(e) >> get<1>(e);
        coo.push_back(e);
        
        cin >> n;
        
        for(int i=1;i<=n;i++){
            cin >> get<0>(e) >> get<1>(e);
            coo.push_back(e);
        }
    
        for(int i=0;i<=n;i++)
            for(int j=0;j<=n;j++)
                dist[i][j] = abs(get<0>(coo[i])-get<0>(coo[j]))+abs(get<1>(coo[i])-get<1>(coo[j]));
        
        memset(memo, -1, sizeof memo);
        printf("The shortest path has length %d\n",tsp(0,1));
    }
}



