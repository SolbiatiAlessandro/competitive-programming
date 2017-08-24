//
//  main.cpp
//  009
//
//  Created by Alessandro Solbiati on 18/08/2017.
//  Copyright © 2017 Alessandro Solbiati. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>


int check_a(int W,int N) {
    int cap=0;
    for (int i=0,a; i<W; i++) {
        std::cin >> a;
        cap = std::max(cap,a);
    }
    return cap;
}

int main(int argc, const char * argv[]) {
    int N,B,H,W;
    while (scanf(" %d %d %d %d",&N,&B,&H,&W)==4) {
        
        std::vector<int> Pvec;
        for (int k=0; k<H; k++) {
            int p;
            scanf(" %d", &p);
            if(check_a(W,N)>=N)
                if(p*N<=B)
                    Pvec.push_back(p*N);
        }
        std::sort(Pvec.begin(), Pvec.end());
        if(!Pvec.empty()) printf("%d\n", Pvec[0]);
        else printf("stay home\n");
    }
    return 0;
}
