#include "AllLists.h"

#include <limits>


unsigned int AllLists::defaultCapacity = 100;

AllLists::AllLists(int k, vector<std::string> filenames){
    this->capacity = defaultCapacity;
    this->count = k;
    this->folder = new List[this->capaity];

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
    

    int lowest = std::numeric_limits<int>::max();
    int nList = 0;

    for(size_t i = 0;i < this->count;i++){
        if(this->folder[i].getAtIndex() < lowest){
            if(!this->folder[i].isEmpty()){
                continue;
            }
            
            lowest = this->folder[i].getAtIndex();
            nList = i;
        }
    }        

    mergedList.push_back(lowest);
    this->folder[nList].increaseIndex();


}