#pragma once

#include <string>
#include <vector>

#include "List.h"


class AllLists{
    public:
        AllLists(int k, vector<std::string> filenames);
        ~AllLists();

        List mergeLists();
        size_t wholeSize(); 

    private:
        List* folder;
        unsigned int capacity;
        unsigned int count;

        static unsigned int defaultCapacity;

};