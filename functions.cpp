/*

    FUNKCE

*/


vector<int> readIntsFromFile(const string& filename){
    vector<int> inputData;
    std::ifstream file(filename, std::ios::in);
    
    string line;

    while (std::getline(file, line)) {
        
        int num = std::stoi(line);
        inputData.push_back(num);
    }

    return inputData;
}