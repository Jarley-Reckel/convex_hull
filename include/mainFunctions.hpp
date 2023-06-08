#ifndef MAINFUNCTIONS
#define MAINFUNCTIONS

#include "types.hpp"
#include "structs.hpp"
#include <iostream>
#include <fstream>
#include <exception>


void checkPassArgument(int argc);

class unopened_file : public std::exception {

    public:
        virtual const char* what() const throw() { 
            return "Erro: Can't open 5";
        }
};

std::ifstream openFile(std::string fileName);

Point* definePoints(std::ifstream& inputFile);

#endif