//
//  main.cpp
//  012
//
//  Created by Alessandro Solbiati on 20/08/2017.
//  Copyright © 2017 Alessandro Solbiati. All rights reserved.
//

#include <iostream>
#include <vector>

class RFP {
public:
    std::string name;
    float price;
    float compliance;
    
    RFP(std::string n,float p,float c) : name(n), price(p), compliance(c) { }
};

bool compare_compliance(const RFP& a, const RFP& b){
    return a.compliance<b.compliance;
}

bool compare_price(const RFP& a, const RFP& b){
    return a.price<b.price;
}


int main(int argc, const char * argv[]) {
    
    int nr,np,count=1;
    while (scanf(" %d %d",&nr,&np) == 2) {
        
        std::vector<RFP> vRFP;
        std::vector<RFP> vvRFP;
        std::string line;
        
       
        for (int i=0; i<nr; i++) std::cin >> line;
        
        for (int i=0; i<np; i++) {
            
            float pr; int f;
            std::cin >> line;
            scanf("%f %d",&pr,&f);
            float c = float(f)/float(nr);
            
            RFP * newRFP = new RFP (line,pr,c);
            vRFP.push_back(*newRFP);
            
            for (int i=0; i<f; i++) std::cin >> line;
            
        }
        
        std::sort(std::begin(vRFP), std::end(vRFP), compare_compliance);
        
        float best_compliance = vRFP[vRFP.size()-1].compliance;
        
        for (int i=0; i<vRFP.size(); i++)
            if (vRFP[i].compliance==best_compliance)
                vvRFP.push_back(vRFP[i]);
        
        std::sort(std::begin(vvRFP), std::end(vvRFP), compare_price);
        
        printf("RFP #%d\n",count);
        std::cout << vvRFP[vvRFP.size()-1].name << "\n";
        
        
        
    }
    return 0;
}

