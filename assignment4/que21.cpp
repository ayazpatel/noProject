#include <iostream>
#include <fstream>

int main() {
    const char* filename = "data.bin";
    const int dataSize = 5;
    int writeData[dataSize] = {10, 20, 30, 40, 50};
    int readData[dataSize] = {0};

    // Write data to a binary file
    std::ofstream outFile(filename, std::ios::binary);
    if (!outFile) {
        std::cerr << "Error opening file for writing!" << std::endl;
        return 1;
    }
    outFile.write(reinterpret_cast<const char*>(writeData), sizeof(writeData));
    outFile.close();

    // Read data from the binary file
    std::ifstream inFile(filename, std::ios::binary);
    if (!inFile) {
        std::cerr << "Error opening file for reading!" << std::endl;
        return 1;
    }
    inFile.read(reinterpret_cast<char*>(readData), sizeof(readData));
    inFile.close();

    // Display the read data
    std::cout << "Data read from file:" << std::endl;
    for (int i = 0; i < dataSize; ++i) {
        std::cout << readData[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
