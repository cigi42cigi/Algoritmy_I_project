#pragma once

#include <vector>
#include <string>


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

        void testMerge(const std::vector<std::string>& files);


    private:
        std::vector<int> data;
        unsigned int index;
};