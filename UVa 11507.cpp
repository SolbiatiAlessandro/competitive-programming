//
//  main.cpp
//  013
//
//  Created by Alessandro Solbiati on 21/08/2017.
//  Copyright © 2017 Alessandro Solbiati. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

char* newval(char* change, char* last){
    
    

    if (!strcmp(change,"No")) return last;
    if (!strcmp(last,"+x")) return change;
    else if (change[1]=='z'&&last[1]=='y') return last;
    else if (change[1]=='y'&&last[1]=='z') return last;
    else if (!strcmp(last,"-x")){
        if(!strcmp(change,"+z")){
            char out[2] = {'-','z'};
            return out;
        }
        else if(!strcmp(change,"-z")){
            char out[2] = {'+','z'};
            return out;
        }
        else if(!strcmp(change,"+y")){
            char out[2] = {'-','y'};
            return out;
        }
        else if(!strcmp(change,"-y")){
            char out[2] = {'+','y'};
            return out;
        }
        else return NULL;
    }
    
    else if(!strcmp(last,"+z")&&!strcmp(change,"+z")){
        char out[2] = {'-','x'};
        return out;
    }
    else if(!strcmp(last,"+z")&&!strcmp(change,"-z")){
        char out[2] = {'+','x'};
        return out;
    }else if(!strcmp(last,"-z")&&!strcmp(change,"+z")){
        char out[2] = {'+','x'};
        return out;
    }
    else if(!strcmp(last,"-z")&&!strcmp(change,"-z")){
        char out[2] = {'-','x'};
        return out;
    }
    else if(!strcmp(last,"+y")&&!strcmp(change,"+y")){
        char out[2] = {'-','x'};
        return out;
    }
    else if(!strcmp(last,"+y")&&!strcmp(change,"-y")){
        char out[2] = {'+','x'};
        return out;
    }else if(!strcmp(last,"-y")&&!strcmp(change,"+y")){
        char out[2] = {'+','x'};
        return out;
    }
    else if(!strcmp(last,"-y")&&!strcmp(change,"-y")){
        char out[2] = {'-','x'};
        return out;
    }
    
    else return NULL;

}


int main(int argc, const char * argv[]) {
    int L;
    while(scanf("%d",&L)==1 & L!=0){
        char last[] = "+x";
        for (int i=0; i<L-1; i++) {
            char change[3];
            cin >> change;
            strcpy(last, newval(change, last));
        }
        printf("%s\n",last);
    }
}
