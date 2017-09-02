//
//  main.cpp
//  023
// UVA 01237
//  Created by Alessandro Solbiati on 29/08/2017.
//  Copyright © 2017 Alessandro Solbiati. All rights reserved.
//

#include <iostream>
#include <tuple>
#include <string>
#include <vector>

int main(int argc, const char * argv[]) {
    int TC;
    scanf("%d",&TC);
    
    while(TC--){
        
        std::vector<std::tuple<std::string,double,double>> db;
        
        int D;
        scanf("%d",&D);
        while(D--){
            std::string name;
            double H,L;
            
            std::cin >> name;
            std::cin >> L;
            std::cin >> H;
            
            std::tuple<std::string, double, double> elem (name,L,H);
            db.push_back(elem);
        }
        
        int Q;
        scanf("%d",&Q);
        while(Q--){
            double P;
            scanf("%lf",&P);
            
            std::vector<std::string> out;
            
            for (std::vector<std::tuple<std::string,double,double>>::iterator it = db.begin(); it!=db.end(); it++)
                if (P>std::get<1>(*it) && P<std::get<2>(*it))
                    out.push_back(std::get<0>(*it));
            
            if(out.size()==1) std::cout << out[0] << "\n";
            else std::cout << "UNDETERMINED\n";
            }
        
        if(TC!=0) printf("\n");
    }
}


