/* 
 * Author: Jeramy Dichiera
 * Created on March 7, 2017, 9:13 AM
 * File:   main.cpp
 *
 * Purpose: This console application allows users to create a list of their CD
 * collection. The program will capture record  and artist data from the user and 
 * store that information in a file saved to the hard drive.
 * 
 * Input: Record and artist information entered through the console.
 * 
 * Output: A file that holds the record and artist information.
 * 
 * Exceptions:
 */

#include <iostream>
#include <string>
#include <fstream>

void saveRecord(std::string fileName);
void displayCollection(std::string fileName);


int main(int argc, char** argv) {
    const std::string FILE_NAME = "collection.txt";
    int menuOption = 0;
    
    do
    {
        std::cout << "--== Main Menu ==--" << std::endl;
        std::cout << "1. Enter record information" << std::endl;
        std::cout << "2. Display record information" << std::endl;
        std::cout << "3. End program" << std::endl;
        std::cin >> menuOption;
        std::cin.ignore(100, '\n');
        std::cout << std::endl;
        
        if(menuOption == 1){
            saveRecord(FILE_NAME);
        }else if(menuOption == 2){
            displayCollection(FILE_NAME);
        }
        
        std::cout << std::endl;
    }while(menuOption != 3);
    return 0;
}

void saveRecord(std::string fileName){
    std::string recordName = "";
    std::string artistName = "";
    
    std::ofstream outFile;
    outFile.open(fileName, std::ios::app);
    
    if(outFile.is_open()){
        std::cout << "Record name (-1 to stop): ";
        getline(std::cin, recordName);
        while(recordName != "-1"){
            std::cout << "Artist's name: ";
            getline(std::cin, artistName);
            outFile << recordName << '#' << artistName << std::endl;
            
            std::cout << "Record name (-1 to stop): ";
            getline(std::cin, recordName);
        }
        outFile.close();
    }else{
        std::cout << fileName << " could not be opened" << std::endl;
    }
}

void displayCollection(std::string fileName){
    std::string recordName = "";
    std::string artistName = "";
    
    std::ifstream inFile;
    inFile.open(fileName, std::ios::in);
    
    if(inFile.is_open()){
        getline(inFile, recordName, '#');
        getline(inFile, artistName);
        
        while(!inFile.eof()){
            std::cout << recordName << " , " << artistName << std::endl;
            
            getline(inFile, recordName, '#');
            getline(inFile, artistName);
        }
        inFile.close();
    }else{
        std::cout << fileName << " could not be opened" << std::endl;
    }
}

