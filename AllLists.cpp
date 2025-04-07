#include "AllLists.h"

#include <limits>

unsigned int AllLists::defaultCapacity = 100;

AllLists::AllLists(int k, std::vector<std::string> filenames){
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
    
    int emptyLists = 0;

    for(size_t j = 0;j < this->wholeSize();j++){
        /*if(emptyLists == this->count - 1){
            break;
        }*/
        // PRIDANI PRO PRAZDNE LISTY??


        int lowest = std::numeric_limits<int>::max();
        int nList = 0;
        
        for(size_t i = 0;i < this->count;i++){
            if(this->folder[i].getAtIndex() < lowest){
                
                if(this->folder[i].isEmpty()){
                    emptyLists++;
                    continue;
                }
                
                lowest = this->folder[i].getAtIndex();
                nList = i;
            }
        }        
        
        mergedList.push_back(lowest);
        this->folder[nList].increaseIndex();
        
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


List AllLists::getList(int index){
    return this->folder[index];
}


