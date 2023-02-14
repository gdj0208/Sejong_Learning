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
    int totalFloor;
    int *floor;
    int move;
    unsigned long long count;
    
    void initFloor();
    void moveFloor(int floorNum);
    void printInfo(int floorNum);
};

#endif /* TowerOfHanoi_hpp */
