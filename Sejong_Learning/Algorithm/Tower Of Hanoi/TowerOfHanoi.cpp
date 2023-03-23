//
//  TowerOfHanoi.cpp
//  Sejong_Learning
//
//  Created by 구동준 on 2023/02/13.
//

#include "TowerOfHanoi.hpp"

TowerOfHanoi::TowerOfHanoi(){
    printf("하노이의 탑\n");
    printf("총 원반의 수 : ");
    cin >> totalFloor;      // 원반의 수 입력
    
    initFloor();            // 층수 정보 초기화
    count = 0;              // 옮긴 횟수 초기화
}
TowerOfHanoi::~TowerOfHanoi(){
    if(floor != NULL) {delete floor;}
}

void TowerOfHanoi::solve(){
    moveFloor(totalFloor, 1, 2, 3);  // 문제 풀기 시작
    printf("총 %d번 옮겼습니다!\n", count);
}
void TowerOfHanoi::initFloor(){
    floor = (int*)calloc(totalFloor, sizeof(int));
    if(floor == NULL) { printf("allocation failed!\n"); return; }
    
    for(int i = 0; i < totalFloor; i++){
        floor[i] = 0;
    }
}
void TowerOfHanoi::moveFloor(int floorNum, int from, int aux, int to){
    if(floorNum == 1) {printf("%d번 층 %d번 기둥에서 %d번 기둥으로 이동\n", floorNum, from, to); count++; return;}
    
    moveFloor(floorNum - 1, from, to, aux);
    printf("%d번 층 %d번 기둥에서 %d번 기둥으로 이동\n", floorNum, from, to);
    count++;
    moveFloor(floorNum - 1, aux, from, to);
    
    /*
    // 구형 코드
     
    // 1층이 아니면 상위 층 조작
    if(floorNum != 1) {moveFloor(floorNum - 1);}
    
    
    
    // n층 탑 위치 변경
    if(floorNum % 2 == 1) {move = 1 + totalFloor%2;}
    else {move = 1 +(totalFloor + 1)%2;}
    
    // 전체 층수가 짝수면 홀수 층은 1칸씩, 짝수 층은 2칸씩 이동
    // 전체 층수가 홀수면 홀수 층은 2칸씩, 짝수 층은 1칸씩 이동
     
    // 이 계산 적용시 n번 탑과 n+3번 탑은 동일한 탑이다.
    // ex) 1번 탑 == 4번 탑 == 7번 탑
     
    floor[floorNum - 1] += move;
    floor[floorNum - 1] %= 3;
    // 탑 옮기기
    
    count++;    // 옮긴 횟수 카운트
    
    // n번 층이 m번 타워로 옮겨졌음을 출력
    printInfo(floorNum);
    
    
    
    // 1층이 아니면 상위 층 조작
    if(floorNum != 1) {moveFloor(floorNum - 1);}
     */
}
/*
 // 구형 코드
 void TowerOfHanoi::printInfo(int floorNum){
     printf("%d층 %lld번 탑으로 이동\n", floorNum, floor[floorNum - 1] + 1);
 }
 */
