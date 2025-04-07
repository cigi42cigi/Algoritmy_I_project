/*

MERGE SORT
MAIN

urls:
https://www.programiz.com/dsa/merge-sort

*/

#include "List.cpp"
#include "AllLists.cpp"

#include <algorithm>


using std::cout, std::vector, std::string;

vector<int> readInt(const std::string& filename);
void test();


int main(int argc, char* argv[]){

    vector<std::string> files = {"test_data/0.txt", "test_data/1.txt", "test_data/2.txt"};

    AllLists allLists(3, files);

    /*
    List list = allLists.getList(0);
    list.printList();
    */

    List merged = allLists.mergeLists();
    
    cout << "Merged list:\n";
    merged.printList();

    cout << "\n\n" << "TEST\n";
    test();


    return 0;
}

void test(){
    
    vector<int> vec1 = readInt("test_data/0.txt");
    vector<int> vec2 = readInt("test_data/1.txt");
    vector<int> vec3 = readInt("test_data/2.txt");
       
    vec1.insert(vec1.end(),vec2.begin(),vec2.end());
    vec1.insert(vec1.end(),vec3.begin(),vec3.end());
    
    std::sort(vec1.begin(),vec1.end());

    for (int x : vec1) {
        cout << x << " ";
    }

}


vector<int> readInt(const std::string& filename){
    vector<int> data;
    
    std::ifstream file(filename, std::ios::in);
    
    std::string line;

    while (std::getline(file, line)) {
        
        int num = std::stoi(line);
        data.push_back(num);
    }

    return data;
}