#include <iostream>
#include <fstream>

int main() {
    // Open the source file in read mode
    std::ifstream sourceFile("source.txt", std::ios::binary);
    // Open the destination file in write mode
    std::ofstream destinationFile("destination.txt", std::ios::binary);

    // Check if the source file was opened successfully
    if (!sourceFile) {
        std::cerr << "Error opening source file!" << std::endl;
        return 1;
    }

    // Check if the destination file was opened successfully
    if (!destinationFile) {
        std::cerr << "Error opening destination file!" << std::endl;
        return 1;
    }

    // Copy contents from source file to destination file
    destinationFile << sourceFile.rdbuf();

    // Close the files
    sourceFile.close();
    destinationFile.close();

    std::cout << "File copied successfully!" << std::endl;

    return 0;
}
