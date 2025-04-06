#include "List.h"

#include <iostream>


List::List(std::vector<int> inputData){
    this->data = inputData;
    this->count = 0;
}

List::List(const std::string& filename){
    std::ifstream file(filename, std::ios::in);
    
    std::string line;

    while (std::getline(file, line)) {
        
        int num = std::stoi(line);
        this->data.push_back(num);
    }
}

int List::getIndex(){
    return this->index;
}

void List::printList(){

    for(size_t i = 0;i < this->data.size();i++){
        std::cout << this->data[i] << " ";
    }
    std::cout << "\n";
}

void List::increaseIndex(){
    this->index++;
}

int List::getAtIndex(){
    return this->data[this->index];
}

int List::getSize(){
    return this->data.size();
}

bool List::isEmpty(){
    if(this->index == this->data.size() - 1){
        return true;
    }
    return false;
}