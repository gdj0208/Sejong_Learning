//
//  TowerOfHanoi.hpp
//  Sejong_Learning
//
//  Created by 구동준 on 2023/02/13.
//

#ifndef TowerOfHanoi_hpp
#define TowerOfHanoi_hpp

#include "MainHeader.h"
class TowerOfHanoi{
public:
    TowerOfHanoi();
    ~TowerOfHanoi();
    
    void solve();
private:
    int totalFloor;             // 탑의 층수
    //int *floor;
    //int move;
    unsigned long long count;   // 탑 옮긴 횟수
    
    //void initFloor();
    void moveFloor(int floorNum, int from, int aux, int to);    //탑 옮기기
    //void printInfo(int floorNum);
};

#endif /* TowerOfHanoi_hpp */
