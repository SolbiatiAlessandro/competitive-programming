//
//  main.cpp
//  014
//
//  Created by Alessandro Solbiati on 21/08/2017.
//  Copyright © 2017 Alessandro Solbiati. All rights reserved.
//

#include <iostream>
#include <algorithm>


int main(int argc, const char * argv[]) {
    std::string s = "9876543210";
    std::sort(s.begin(),s.end());
    char* end; int inN;
    
    while (scanf("%d",&inN)==1&&inN!=0) {
        
        int NA=1;
        do {
            std::string s1 = s.substr(5);
            std::string s2 = s.substr(0, 5);
    
            int f1 = std::strtod(s1.c_str(), &end);
            int f2 = std::strtod(s2.c_str(), &end);
            
            
            if(inN==f1/f2 && 0==f1%f2){
                printf("%s / %s = %d\n",s1.c_str(),s2.c_str(),inN);
                NA=0;
            }
        } while (std::next_permutation(s.begin(),s.end()));
        if (NA) printf("There are no solutions for %d\n",inN);
    }
}


