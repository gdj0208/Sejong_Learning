//
//  AlgorithmSolving.hpp
//  Sejong_Learning
//
//  Created by 구동준 on 2023/02/13.
//

#ifndef AlgorithmSolving_hpp
#define AlgorithmSolving_hpp

#include "MainHeader.h"
#include "EightQueen.hpp"

using namespace std;

class AlgorithmSolving{
public:
    AlgorithmSolving();
    //~AlgorithmSolving();
    
    void solve();
    
private:
    class EightQueen * eQueen;
    int algoNum;
    bool run;
    
    void solveEightQueen();
};

#endif /* AlgorithmSolving_hpp */
