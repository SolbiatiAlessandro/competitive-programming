//
//  main.cpp
//  001
//
//  Created by Alessandro Solbiati on 14/08/2017.
//  Copyright © 2017 Alessandro Solbiati. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    char c;
    int r=0;
    while  ((c = getchar())!=EOF) {
        if (c=='"') {
            printf("%s", r == 0 ? "``" : "''");
            r == 0 ? r=1 : r=0;
            
        } else printf("%c",c);
    }
    return 0;
}
