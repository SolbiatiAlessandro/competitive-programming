//
//  main.cpp
//  024
//
//  Created by Alessandro Solbiati on 29/08/2017.
//  Copyright © 2017 Alessandro Solbiati. All rights reserved.
// UVA 10976

#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    int k;
    
    while (scanf("%d",&k)!=EOF){
        
        std::vector<std::tuple<int,int>> cc;
        
        for (int x=k+1; x<=2*k; x++) {
            if((x*k)%(x-k)==0){
                tuple<int,int> xy (x,(x*k)/(x-k));
                cc.push_back(xy);
            }
        }
        
        printf("%d\n",int(cc.size()));
        
        for(int i=0; i<int(cc.size());i++) printf("1/%.d = 1/%d + 1/%d\n", k, get<1>(cc[i]), get<0>(cc[i]));
    
    }
}
