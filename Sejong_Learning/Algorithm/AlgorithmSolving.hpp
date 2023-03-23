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
#include "TowerOfHanoi.hpp"
#include "knackSack.hpp"

using namespace std;

/*
 풀 문제 목록
 1. 8퀸 (해결)
 2. 하노이 탑 (해결)
 3. 출장 세일즈맨 문제(TSP)
 4. 배낭문제
 5. 그래프 색상문제
 6. 최대 흐름 문제
 7. 빈 포장 문제
 8. 가장 긴 공통 시퀀스(LCS)
 9. 0-1 행렬 곱셈 문제
 10. 작업 예약 문제
 11. 부분 집합 합 문제
 12. 파티션 문제
 13. 부분 배낭 문제
 */

class AlgorithmSolving{
public:
    AlgorithmSolving();
    //~AlgorithmSolving();
    
    void solve();
    
private:
    class EightQueen * eQueen;
    class TowerOfHanoi* tower;
    class KnacksackProblem* bag;
    
    int algoNum;                    // 몇번 문제를 풀 건지 결정
    bool run;
};

#endif /* AlgorithmSolving_hpp */
