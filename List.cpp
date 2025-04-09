#include "List.h"

#include <iostream>
#include <fstream>
#include <algorithm>

List::List(const std::vector<int> inputData){
    this->data = inputData;
    this->index = 0;
}

List::List(const std::string& filename){
    std::ifstream file(filename, std::ios::in);
    std::string line;

    while (std::getline(file, line)) {
        
        int num = std::stoi(line);
        this->data.push_back(num);
    }

    this->index = 0;
}

List::List(){
    this->index = 0;
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

size_t List::getSize(){
    return this->data.size();
}

bool List::isEmpty(){
    if(this->index > this->data.size() - 1){
        return true;
    }
    return false;
}

/**
 * @brief Načte celá čísla ze souboru a vrátí je jako vektor.
 * 
 * @param filename Cesta k textovému souboru.
 * @return std::vector<int> Vektor načtených čísel.
 */

std::vector<int> readInt(const std::string& filename){
    std::vector<int> data;
    std::ifstream file(filename, std::ios::in);
    std::string line;

    while (std::getline(file, line)) {
        
        int num = std::stoi(line);
        data.push_back(num);
    }

    return data;
}


void List::testMerge(const std::vector<std::string>& files){

    std::vector<int> mergedData;

    for (const std::string& filename : files) {
        std::vector<int> tempData = readInt(filename);
        mergedData.insert(mergedData.end(), tempData.begin(), tempData.end());
    }

    std::sort(mergedData.begin(), mergedData.end());

    std::cout << "\n" << "-----TEST-----\n";
    for (int x : mergedData) {
        std::cout << x << " ";
    }
    std::cout << "\n";

    if(this->data == mergedData){
        std::cout << "DATA SE SHODUJI\n";
    }
    else{
        std::cout << "CHYBA\n";
    }
}


std::vector<int> List::getData(){
    return this->data;
}