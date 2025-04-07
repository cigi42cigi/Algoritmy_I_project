#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <fstream>

class List{
    public:
        List(std::vector<int> inputData);
        List(const std::string& filename);
        List();

        int getIndex();
        void printList();
        void increaseIndex();
        int getAtIndex();
        size_t getSize();
        bool isEmpty();



    private:
        std::vector<int> data;
        unsigned int index;
};