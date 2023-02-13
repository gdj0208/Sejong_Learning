//
//  main.cpp
//  Sejong_Learning
//
//  Created by 구동준 on 2023/01/27.
//  깃허브에 올리는 법 : Source Control/Commit

//#include "MainHeader.h"
#include "AlgorithmSolving.hpp"


#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include <math.h>
//#include <time.h>
#define dwarf_num 9
#define ori_num 7

using namespace std;
/*
 
class Calculater{
public:
    Calculater();
    ~Calculater();
    
    void run();
private:
};

int main() {
    //srand(time(NULL));
    
    Calculater * calculater = new Calculater;
    if(calculater == NULL) {printf("allocation failed!\n"); return -1;}
    
    calculater->run();
    
    free(calculater);
    calculater = NULL;
    
}
 */

int main(){
    AlgorithmSolving * algSolve = new AlgorithmSolving;
    if(algSolve == NULL) {printf("Allocation failed!\n"); return -1;}
    
    algSolve->solve();
    
    delete algSolve;
}
