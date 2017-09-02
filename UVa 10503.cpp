//
//  main.cpp
//  28
//
//  Created by Alessandro Solbiati on 01/09/2017.
//  Copyright © 2017 Alessandro Solbiati. All rights reserved.
//

#include <iostream>
#include <vector>
#include <tuple>
#include <cstring>

using namespace std;\
int n,m,flag;
vector<tuple<int,int>> tuples;
tuple<int,int> seq[14];
tuple<int,int> ti,tf;

void rec(int c){
    if(flag && c==n+1 && get<0>(tf)==get<1>(seq[c-1])){
        printf("YES\n");
        flag=0;
    }
    else if(flag){
        for(vector<tuple<int,int>>::iterator it=tuples.begin();it!=tuples.end();it++){
            if (get<0>(*it)==get<1>(seq[c-1])) {
                seq[c]=*it;
                tuples.erase(it);
                rec(c+1);
                tuples.push_back(*it);
                
            }
            else if(get<1>(*it)==get<1>(seq[c-1])){
                swap(get<0>(*it), get<1>(*it));
                seq[c]=*it;
                tuples.erase(it);
                rec(c+1);
                tuples.push_back(*it);
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    while(scanf("%d",&n)==1&&n!=0){
        scanf("%d",&m);
        
        memset(seq, 0, sizeof(seq));
        tuples.clear();
        flag=1;
        
        int first,second;
        
        scanf("%d %d",&first,&second);
        ti = make_tuple(first,second);
        seq[0]=(ti);
        
        scanf("%d %d",&first,&second);
        tf = make_tuple(first,second);
        
        while (m--) {
            scanf("%d %d",&first,&second);
            tuple<int,int> e (first,second);
            tuples.push_back(e);
        }
    
        rec(1);
        
        if(flag==1) printf("NO\n");
    }
}


