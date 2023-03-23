//
//  knackSack.hpp
//  Sejong_Learning
//
//  Created by 구동준 on 2023/02/15.
//

#ifndef knackSack_hpp
#define knackSack_hpp

#include "MainHeader.h"
class Item{
public:
    Item();
    
    void initItem(int n);            // 아이템 정보 초기화
    int retNum();
    int retPrice();             // 아이템 가격 반환
    int retWeight();            // 아이템 무게 반환
    
private:
    int num;
    int price;
    int weight;
};

class KnacksackProblem{
public:
    KnacksackProblem();
    ~KnacksackProblem();
    
    void solve();
private:
    Item * items;                   // 가방에 들어갈 아이템들
    Item ** inBags;
    //int *itemNumInBag;              // 가방에 들어갈 아이템의 번호
    int limitWeight;                // 가방이 수용 할 수 있는 최대 무게
    int totalItems;                 // 모든 아이템들의 수(가방에 안들어가는 거 포함)
    int totalPrice, totalWeight;    // 가방에 들어 간 아이템들의 가격, 무게의 총합
    int howmany;                    // 가방에 들어간 아이템들의 수
    
    void initAllItems();            // 모든 아이템들 초기화
    void getCase(int price, int weight, int it_in_bag);
    void printAllItems();           // 모든 아이템 출력
    void printAllItemsInBag();      // 가방 내 모든 아이템 출력
    void sortItemsByWeight();       // 무게 순으로 모든 아이템 정렬
    void swapItems(Item * tem1, Item * tem2);
    int getMin(int it_in_bag);
    bool isItIn(int temNum, int it_in_bag);
};

#endif /* knackSack_hpp */
