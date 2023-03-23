//
//  knackSack.cpp
//  Sejong_Learning
//
//  Created by 구동준 on 2023/02/15.
//

#include "knackSack.hpp"

// [[ knacksack ]] ///////////////////////////
KnacksackProblem::KnacksackProblem()
{
    srand(time(NULL));
    
    limitWeight = rand()% 10 + 10;
    
    totalItems = rand()% 5 + 5;
    totalPrice = 0;
    howmany = 0;
    
    items = (Item*)calloc(totalItems, sizeof(Item));
    if(items == NULL) {printf("allocation failed!\n");}
    
    inBags = (Item**)calloc(totalItems, sizeof(Item*));
    if(inBags == NULL) {printf("allocation failed!\n");}
    
    initAllItems();
}
KnacksackProblem::~KnacksackProblem(){
    if(items != NULL) {delete items;}
    if(inBags != NULL) {delete inBags;}
}
void KnacksackProblem::solve(){
    sortItemsByWeight();
    printAllItems();
    
    getCase(0,0,0);
    printAllItemsInBag();
}
void KnacksackProblem::initAllItems(){
    for(int i = 0; i < totalItems; i++){
        items[i].initItem(i);
    }
}
void KnacksackProblem::getCase(int price, int weight, int it_in_bag){
    
    int it_num = getMin(it_in_bag);
    if(it_in_bag >= totalItems) {
        howmany = it_in_bag;
        totalWeight = weight;
        printAllItemsInBag();
    }
    else {
        for(int i = it_num; i < totalItems; i++){
            if(isItIn(it_num, it_in_bag)) {it_num++; continue;}
            
            inBags[it_in_bag] = &items[i];
            getCase(inBags[it_in_bag]->retPrice() + price, inBags[it_in_bag]->retWeight() + weight, it_in_bag + 1);
        }
        // 현재 가방에 중첩해서 아이템들이 들어가는 상태
    }
}
void KnacksackProblem::printAllItemsInBag(){
    printf("\n안에 들어있는 아이템 정보들은 다음과 같습니다.\n");
    for(int i = 0; i < howmany; i++){
        printf("%d번 ", inBags[i]->retNum());
    }
    printf("\n총 무게 : %d\n", totalWeight);
}
void KnacksackProblem::printAllItems(){
    printf("\n모든 아이템의 정보는 다음과 같습니다.\n");
    for(int i = 0; i < totalItems; i++){
        printf("%d(번호 : %d | 무게 : %d | 가격 : %d)\n", i + 1, items[i].retNum(), items[i].retWeight(), items[i].retPrice());
    }
    printf("\n총 아이템 개수 : %d\n", totalItems);
    printf("가방의 무게 제한 : %d\n", limitWeight);
}
void KnacksackProblem::sortItemsByWeight(){
    
    // 무게 순으로 정렬
    for(int i = 0; i < totalItems; i++){
        for(int j = 0; j < totalItems - 1; j++){
            if(items[j].retWeight() > items[j+1].retWeight()) {swapItems(&items[j], &items[j+1]);}
        }
    }
    
    // 무게 순으로 정렬 후 같은 무게 사이 가격 정렬
    for(int i = 0; i < totalItems; i++){
        for(int j = 0; j < totalItems - 1; j++){
            if(items[j].retWeight() == items[j+1].retWeight()
               && items[j].retPrice() < items[j+1].retPrice()) {swapItems(&items[j], &items[j+1]);}
        }
    }
}
void KnacksackProblem::swapItems(Item * tem1, Item * tem2){
    Item tmp = *tem1;
    *tem1 = *tem2;
    *tem2 = tmp;
}
bool KnacksackProblem::isItIn(int temNum, int it_in_bag){
    for(int i = 0; i < it_in_bag; i++){
        if(inBags[i] == &items[temNum]){return true;}
    }
    return false;
}
int KnacksackProblem::getMin(int it_in_bag){
    int item = 0;
    
    for(int i = 1; i <= it_in_bag; i++){
        if(item == items[i].retNum()) {i = 0; item++;}
    }
    
    return item;
}

// [[ item ]] ////////////////////////////
Item::Item(){}
void Item::initItem(int i){
    num = i + 1;
    //printf("가격 : ");
    price = rand() % 10 + 1;
    //printf("무게 : ");
    weight = rand() % 5 + 1;
}
int Item::retNum(){return num;}
int Item::retPrice(){return price;}
int Item::retWeight(){return weight;}

