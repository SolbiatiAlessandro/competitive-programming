//
//  main.cpp
//  040
//TSP
//  Created by Alessandro Solbiati on 06/09/2017.
//  Copyright © 2017 Alessandro Solbiati. All rights reserved.
//

#include <iostream>

using namespace std;

int n,dist[100][100];

int tsp(int pos, int mask){
    
    if(mask==((1<<n)-1)) return dist[pos][0];
    else{
        int m = 100000;
        for(int i=0;i<n && i!=pos &&( (mask & (1<<i))==0);i++)
            m=min(m,dist[pos][i]+tsp(i,mask |= (1<<i)));
        return m;
        
    }
}

int main(int argc, const char * argv[]) {
    
    cin >> n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin >> dist[i][j];
    
    cout << tsp(0,1);
    
}
