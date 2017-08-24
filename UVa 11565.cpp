//
//  main.cpp
//  016
//
//  Created by Alessandro Solbiati on 22/08/2017.
//  Copyright © 2017 Alessandro Solbiati. All rights reserved.
//

#include <iostream>
#include <vector>
#define MAX 300

bool xsort(std::pair<int, int> p1, std::pair<int, int> p2){
    int x1=p1.first;
    int x2=p2.first;
    int y1=p1.second;
    int y2=p2.second;
    
    if(x1>0 && x2>0 && y1>0 && y2>0){
        if(x1<x2) return 1;
        else if(x1==x2 && y1<y2) return 1;
        else return 0;
    }
    else return 0;
}

int main(int argc, const char * argv[]) {
    int N;
    std::cin >> N;
    
    while(N--){
        int A,B,C;
        scanf(" %d %d %d",&A,&B,&C);
        
        std::vector<std::pair<int, int>> vpp;
        
        int x,z;
        int flag=0;
        for(x=-MAX;x<MAX;x++){
            for(z=-MAX;z<MAX;z++){
                int expression = x*x*z*z*(x*x+z*z-C)+B*B;
                if(expression==0){
                    std::pair<int,int> pp = std::make_pair(x, B/(x*z));
                    vpp.push_back(pp);
                    flag=1;
                }
            }
            
        }
        if (flag==0) printf("No solutions.\n");
        else{
            std::sort(vpp.begin(), vpp.end(), xsort);
            printf("%d %d %d\n", vpp[0].first, vpp[0].second, B/(vpp[0].first*vpp[0].second));
        }
    }
}
