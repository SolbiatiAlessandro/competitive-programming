//
//  main.cpp
//  UVa 441
//
//  Created by Alessandro Solbiati on 22/08/2017.
//  Copyright © 2017 Alessandro Solbiati. All rights reserved.
//

#include <iostream>

void rec(int k, int N,  int* in, int* out){
    for (int i =k; i<N; i++) {
        *(out+k) = *(in+i);
        if(k == N-1){
            int increasing=1;
            for (int i=0; i<5; i++) if(!(*(out+i)<*(out+i+1))) increasing=0;
            if (increasing){
                for (int i=0; i<6; i++) printf("%d ",*(out+i));
                printf("\n");
            }
        }
        else rec(k+1,N,in,out);
    }
}


int main() {
    for (;;) {
        int N,in[13],out[6];
        
        std::cin >> N;
        if(!N) break;
 
        for (int i=0; i<N; i++) {
            int t; std::cin >> t;
            *(in+i) = t;
            if(i<6) *(out+i) = t;
        
        }

        rec(0,N,in,out);
        printf("\n");
    }
}

