//
//  AlgorithmSolving.cpp
//  Sejong_Learning
//
//  Created by 구동준 on 2023/02/13.
//

#include "AlgorithmSolving.hpp"
AlgorithmSolving::AlgorithmSolving(){
    eQueen = new EightQueen;
    run = 1;
}

void AlgorithmSolving::solve(){
    //printf("check");
    while(run){
        cout
        << "==============================\n"
        << "풀 알고리즘 목록 : \n"
        << "0. 프로그램 종료\n"
        << "1. 8퀸 문제\n"
        << endl
        << "어느 문제를 풀겠습니까? : ";
        
        cin >> algoNum;
        
        switch (algoNum) {
            case 0:
                printf("프로그램을 종료합니다.\n");
                run = 0;
                break;
            case 1:
                solveEightQueen();
                break;
            default:
                printf("제대로 된 입력 부탁 드립니다.");
                break;
        }
        
    }
}
void AlgorithmSolving::solveEightQueen(){
    eQueen->solve();
}
