//
//  EightQueen.hpp
//  Sejong_Learning
//
//  Created by 구동준 on 2023/02/13.
//

#ifndef EightQueen_hpp
#define EightQueen_hpp

#include "MainHeader.h"
#define limit 8

/*
 8퀸 문제
 
 1. 체스판에서 서로 먹을 수 없는 퀸 8마리를 배치하는 문제
 2. 배치할 수 있는 경우의 수와 각 예시를 보여 줄 것.
*/

class EightQueen{
public:
    EightQueen();
    ~EightQueen();
    
    void solve();           // 이 클래스의 메인 함수
private:
    int x[8];               // 각 x좌표에 해당되는 y좌표
    unsigned int count;     // 퀸을 배치 할 수 있는 모든 경우의 수
    
    void getPos(int xpos);  // 각 x좌표에 y좌표를 배치(인자 : x 좌표)
    void printAllData();    // 체스판 데이터 출력(x에 해당되는 y 출력)
    bool outOfRookRule(int ypos, int xpos);
    // 인자에 해당되는 좌표에 가로 세로로 먹을 수 있는 퀸이 있는지 확인
    bool outOfBishopRule(int ypos, int xpos);
    // 인자에 해당되는 좌표에 대각선으로 먹을 수 있는 퀸이 있는지 확인
};

#endif /* EightQueen_hpp */
