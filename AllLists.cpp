/**
 * @file AllLists.cpp
 * @brief Implementace třídy AllLists pro správu kolekce seznamů.
 * 
 * Tento soubor obsahuje definice metod třídy `AllLists`, která spravuje více seznamů (List)
 * a umožňuje zjištění celé velikosti seznamu, vrácení seznamu jako instanci List,
 * dále obsahuje hlavní algoritmus tohoto projektu pro sloučení seznamů. 
 * 
 * @see AllLists
 * @see List
 */

#include "AllLists.h"

#include <limits>
#include <algorithm>
#include <queue>
#include <functional>
#include <iostream>


AllLists::AllLists(int k,const std::vector<std::string> filenames){
    this->count = k;

    for(int i = 0;i < k; i++){
        List newList(filenames[i]);
        this->folder.push_back(newList);
    }
}


/**
 * @details
 * Algoritmus využívá prioritní frontu k udržení aktuálních minimálních hodnot z každého seznamu.
 * Pokud ve frontě zůstane pouze jedna hodnota, zbytek příslušného seznamu je přidán najednou.
 */
List AllLists::mergeLists(){

    std::vector<int> mergedList;
    mergedList.reserve(this->wholeSize());
    

    using Element = std::pair<int,int>;
    std::priority_queue<Element, std::vector<Element>, std::greater<>> currentNums; 
    

    // Načte první hodnoty
    for(size_t i = 0; i < this->count; ++i){
        if(!this->folder[i].isEmpty()) {
            currentNums.push({this->folder[i].nextIndex(), i});
        }
    }

    // Hlavní slučovací cyklus – dokud nebudou všechny seznamy prázdné kromě jednoho.
    while(!currentNums.empty()) {
        
        // Pokud už jsou všechny seznamy prázdné, až na poslední
        if(currentNums.size() == 1){
            auto[value, index] = currentNums.top();
            currentNums.pop();
                
            mergedList.push_back(value);
            
            // Přidání zbytku seznamu najednou
            if(!this->folder[index].isEmpty()){
                std::vector<int> data = this->folder[index].getData();
                mergedList.insert(mergedList.end(), data.begin() + this->folder[index].getIndex(), data.end());
            }
            break;
        }
    
        auto[value, index] = currentNums.top();
        currentNums.pop();
    
        mergedList.push_back(value);

        if (!this->folder[index].isEmpty()) {
            currentNums.push({this->folder[index].nextIndex(), index});
        }
    }
    
    return List(mergedList);
}

size_t AllLists::wholeSize(){
    size_t  sum = 0;

    for(size_t i = 0;i < this->count;i++){
        sum += this->folder[i].getSize();
    }
    return sum;
}

