//
//  main.cpp
//  005
//
//  Created by Alessandro Solbiati on 16/08/2017.
//  Copyright © 2017 Alessandro Solbiati. All rights reserved.
//

#include <iostream>
#include <string>

int main(){
    int TC;
    std::string s;
    std::cin >> TC;
    while(TC--){
        std::cin >> s;
        
        if (!s.compare("1")||!s.compare("4")||!s.compare("78")) printf("+\n");
        else if (!s.compare(s.size()-2, 2, "35")) printf("-\n");
        else if (s[0]=='9' && s[s.length()-1]=='4') printf("*\n");
        else if (s.find("190")==0) printf("?\n");
        
        }
        
    
}
