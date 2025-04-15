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


AllLists::AllLists(int k,const std::vector<std::string> filenames){
    this->count = k;

    for(int i = 0;i < k; i++){
        List newList(filenames[i]);
        this->folder.push_back(newList);
    }
}

List AllLists::mergeLists(){

    std::vector<int> mergedList;
    mergedList.reserve(this->wholeSize());
    
    std::vector<bool> alreadyEmpty(this->count, false);
    std::vector<int> currentNum(this->count, 0);
    

    // Načte první hodnoty
    for(size_t i = 0; i < this->count; ++i){
        if(!this->folder[i].isEmpty()) {
            currentNum[i] = this->folder[i].getAtIndex();
        }
    }


    // Hlavní slučovací cyklus – dokud nebudou všechny seznamy prázdné kromě jednoho.
    for(size_t j = 0;j < this->wholeSize();j++){
        if (std::count(alreadyEmpty.begin(), alreadyEmpty.end(), true) == this->count - 1) {
            break;
        }
        
        int lowest = std::numeric_limits<int>::max();
        int nList = 0;
        
        // Hledá nejmenší číslo z bufferu čísel.
        for(size_t i = 0;i < currentNum.size();i++){
            if(this->folder[i].isEmpty()){
                if(!alreadyEmpty[i]){
                    alreadyEmpty[i] = true;
                }
                continue;
            }
            
            if(currentNum[i] < lowest){                
                lowest = currentNum[i] ;
                nList = i;
            }
        }        

        mergedList.push_back(lowest);
        currentNum[nList] = this->folder[nList].nextIndex();   
    }


    // Přidání posledního seznamu najednou.
    for(size_t i = 0; i < this->count; i++) {
        if (!this->folder[i].isEmpty()) {
            std::vector<int> data = this->folder[i].getData();
            mergedList.insert(mergedList.end(), data.begin() + this->folder[i].getIndex(), data.end());
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

List AllLists::getList(const unsigned int index){
    return this->folder[index];
}
