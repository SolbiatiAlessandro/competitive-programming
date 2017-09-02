//
//  main.cpp
//  026
// uva 10976
//  Created by Alessandro Solbiati on 29/08/2017.
//  Copyright © 2017 Alessandro Solbiati. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, const char * argv[]) {
    int n,m,count=0;
    while (scanf("%d",&n),n) {
        
        cout << "Case " << ++count << ":\n";
        vector<int> prevs;
        vector<int> sums;
        
        while (n--) {
            
            int nn;
            scanf("%d",&nn);
    
            for (int j=int(prevs.size())-1; j>=0; j--) sums.push_back(nn+prevs[j]);
            prevs.push_back(nn);
        
        }
        
        scanf("%d",&m);
        sort(sums.begin(), sums.end());
        
        while(m--){
            
            int mm,found=0;
            scanf("%d",&mm);
            
            for(int i=0; i<int(sums.size())-1&&!found;i++){
                int next = sums[i+1];
                if (mm<next) {
                    int cur = sums[i];
                    int diff1 = abs(mm-cur);
                    int diff2 = abs(mm-next);
                    if(diff1<diff2){
                        printf("Closest sum to %d is %d.\n",mm,cur);
                        found=1;
                    }
                    else if(diff2<diff1){
                        printf("Closest sum to %d is %d.\n",mm,next);
                        found=1;
                    }
                }
                else if(i==int(sums.size())-2) printf("Closest sum to %d is %d.\n",mm,next);
                
                
            }
        }
    }
}


