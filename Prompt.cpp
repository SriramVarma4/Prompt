#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>

std::unordered_map<std::string, std::string> symbolToWord = {
    {"B2", " beta "},
    {"mm", " millimeters "},
    {"cm", " centimeters "},
    {"m", " meters "},
    {"=", " equals "},
    {"≠", " not equal to "},
    {"≈", " approximately equal to "},
    {"≡", " is equivalent to "},
    {">", " is greater than "},
    {"<", " is less than "},
    {">=", " is greater than or equal to "},
    {"<=", " is less than or equal to "},
    {"∞", " infinity "},
    {"∑", " summation "},
    {"∫", " integral "},
    {"∆", " delta "},
    {"∇", " nabla "},
    {"∂", " partial derivative "},
    {"∀", " for all "},
    {"∃", " there exists "},
    {"∴", " therefore "},
    {"∵", " because "},
    {"+", " plus "},
    {"-", " minus "},
    {"×", " multiplied by "},
    {"÷", " divided by "},
    {"^", " to the power of "},
    {"(", " open parenthesis "},
    {")", " close parenthesis "},
    {"{", " open brace "},
    {"}", " close brace "},
    {"[", " open bracket "},
    {"]", " close bracket "},
    {";", ". "},
    {",", ", "},
    {"!", " factorial "},
    {"%", " percent "},
    {"π", " pi "},
    {"μ", " micro "},
    {"α", " alpha "},
    {"β", " beta "},
    {"γ", " gamma "},
    {"δ", " delta "},
    {"ε", " epsilon "},
    {"θ", " theta "},
    {"λ", " lambda "},
    {"μ", " mu "},
    {"ρ", " rho "},
    {"σ", " sigma "},
    {"τ", " tau "},
    {"φ", " phi "},
    {"χ", " chi "},
    {"ω", " omega "},
    {"∠", " angle "},
    {"∩", " intersection "},
    {"∪", " union "},
    {"∈", " element of "},
    {"∉", " not an element of "},
    {"∅", " empty set "},
    {"∑", " summation "},
    {"∆", " delta "},
    {"∇", " nabla "},
    {"∂", " partial derivative "},
    {"∀", " for all "},
    {"∃", " there exists "},
    {"∴", " therefore "},
};

std::string convertToWords(const std::string& input) {
    std::stringstream output;
    std::stringstream ss(input);
    std::string element;

    while (std::getline(ss, element, ' ')) {
        if (symbolToWord.count(element) > 0) {
            output << symbolToWord[element];
        } else {
            output << element;
        }
    }

    return output.str();
}

int main() {
    std::ifstream inputFile("input.csv");
    if (!inputFile) {
        std::cout << "Failed to open input file." << std::endl;
        return 1;
    }

    std::ofstream outputFile("output.csv");
    if (!outputFile) {
        std::cout << "Failed to create output file." << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        std::stringstream ss(line);
        std::string field;
        std::stringstream convertedLine;

        while (std::getline(ss, field, ',')) {
            std::string convertedField = convertToWords(field);
            convertedLine << convertedField << ",";
        }

        std::string convertedRow = convertedLine.str();
        convertedRow.pop_back(); 
        outputFile << convertedRow << std::endl;
    }

    return 0;
}

