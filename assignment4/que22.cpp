#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char* argv[]) {
    // Check if the correct number of command line arguments are provided
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <filename>" << std::endl;
        return 1;
    }

    // Get the filename from the command line arguments
    std::string filename = argv[1];

    // Open the file for reading
    std::ifstream inputFile(filename);
    if (!inputFile) {
        std::cerr << "Error opening file for reading: " << filename << std::endl;
        return 1;
    }

    // Read data from the file
    std::string line;
    std::cout << "Contents of the file:" << std::endl;
    while (std::getline(inputFile, line)) {
        std::cout << line << std::endl;
    }
    inputFile.close();

    // Open the file for writing
    std::ofstream outputFile(filename, std::ios::app); // Open in append mode
    if (!outputFile) {
        std::cerr << "Error opening file for writing: " << filename << std::endl;
        return 1;
    }

    // Write data to the file
    std::string dataToWrite = "This is a new line added to the file.";
    outputFile << dataToWrite << std::endl;
    std::cout << "Data written to the file: " << dataToWrite << std::endl;

    outputFile.close();

    return 0;
}
