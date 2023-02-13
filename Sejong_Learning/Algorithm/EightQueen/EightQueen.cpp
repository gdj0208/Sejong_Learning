//
//  EightQueen.cpp
//  Sejong_Learning
//
//  Created by 구동준 on 2023/02/13.
//

#include "EightQueen.hpp"

EightQueen::EightQueen(){count = 0;}
void EightQueen::solve(){
    getPos(0);
    printf("경우의 수 : %d\n", count);
}

void EightQueen::getPos(int xpos){
    // x좌표가 7이면 모든 좌표 출력
    if(xpos == limit) {count++; printAllData();}
    // x좌표가 7이 아니면 다음 x좌표의 y좌표값 설정
    else {
        
        for(int ypos = 0; ypos < limit; ypos++){
            
            
            // 룩의 규칙(직선상에 겹치지 않을 것) 위반시 생략
            if(outOfRookRule(ypos+1, xpos)) {continue;}
            // 비숍의 규칙(대각선에 겹치지 않을 것) 위반시 생략
            if(outOfBishopRule(ypos + 1, xpos)) {continue;}
            
            
            x[xpos] = ypos + 1; // 지정된 x좌표의 y좌표값 설정
            getPos(xpos + 1);   // 다음 x좌표의 y좌표값 설정
        }
        
    }
}
bool EightQueen::outOfRookRule(int ypos, int xpos){
    for(int i = 0; i < xpos; i++){if(ypos == x[i]) {return true;}}
    
    return false;
}
bool EightQueen::outOfBishopRule(int ypos, int xpos){
    
    // ↗️대각선 확인
    for(int xloc = 0; xloc < xpos; xloc++){
        if(xpos + ypos == xloc + x[xloc]) {
            return true;
        }
    }
    
    // ↘️대각선 확인
    for(int xloc = 0; xloc < xpos; xloc++){
        if(xpos - ypos == xloc - x[xloc]) {
            return true;
        }
    }
    
    return false;
}
void EightQueen::printAllData(){
    for(int i = 0; i < limit; i++){
        printf("%d ", x[i]);
    }
    printf(": %d\n", count);
}
