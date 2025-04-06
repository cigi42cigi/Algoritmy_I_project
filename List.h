#pragma once

#include <vector>
#include <string>

class List{
    public:
        List(std::vector<int> inputData);
        List(const std::string& filename);

        int getIndex();
        void printList();
        void increaseIndex();
        int getAtIndex();
        int getSize();
        bool isEmpty();



    private:
        std::vector<int> data;
        unsigned int index;
};