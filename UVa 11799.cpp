//
//  main.cpp
//  010
//
//  Created by Alessandro Solbiati on 19/08/2017.
//  Copyright © 2017 Alessandro Solbiati. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <string>

int main(int argc, const char * argv[]) {
    int TC, count=1;
    std::cin >> TC;
    while(TC--){
        int N,c, m=0;
        std::cin >> N;
        while (N--) {
            std::cin >> c;
            m = std::max(m, c);
        }
        printf("Case %d: %d\n", count++, m);
    }
}

