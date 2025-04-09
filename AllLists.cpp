#include "AllLists.h"

#include <limits>
#include <algorithm>

unsigned int AllLists::defaultCapacity = 100;

AllLists::AllLists(int k,const std::vector<std::string> filenames){
    this->capacity = defaultCapacity;
    this->count = k;
    this->folder = new List[this->capacity];

    for(size_t i = 0;i < k; i++){
        List newList(filenames[i]);
        this->folder[i] = newList;
    }
}

AllLists::~AllLists(){
    delete[] this->folder;
    this->folder = nullptr;
}

List AllLists::mergeLists(){

    std::vector<int> mergedList;
    mergedList.reserve(this->wholeSize());
    
    std::vector<bool> alreadyEmpty(this->count, false);

    // Hlavní slučovací cyklus – dokud nebudou všechny seznamy prázdné kromě jednoho.
    for(size_t j = 0;j < this->wholeSize();j++){
        if (std::count(alreadyEmpty.begin(), alreadyEmpty.end(), true) == this->count - 1) {
            break;
        }
        
        int lowest = std::numeric_limits<int>::max();
        int nList = 0;
        
        // Hledá nejmenší číslo napříč seznamy.
        for(size_t i = 0;i < this->count;i++){
            if(this->folder[i].isEmpty()){
                if(!alreadyEmpty[i]){
                    alreadyEmpty[i] = true;
                }
                continue;
            }
            
            if(this->folder[i].getAtIndex() < lowest){                
                lowest = this->folder[i].getAtIndex();
                nList = i;
            }
        }        

        mergedList.push_back(lowest);
        this->folder[nList].increaseIndex();    
    }
    
    // Přidání posledního seznamu najednou.
    for(size_t i = 0;i < alreadyEmpty.size();i++){
        if(alreadyEmpty[i]){ 
            std::vector<int> data = this->folder[i].getData();
            
            mergedList.insert(mergedList.end(),data.begin() + this->folder[i].getIndex(), data.end());
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
