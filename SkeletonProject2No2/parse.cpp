// CMSC 330 Advanced Programming Languages
// Project 2 Skeleton
// UMGC CITE
// Spring 2023
// Johnathan Brandstetter


#include <cctype>
#include <iostream>
#include <sstream>

#include <string>

using namespace std;

#include "parse.h"

string parseName(stringstream &in) {
    char alnum;
    string name = "";

    in >> ws;
    while (isalnum(in.peek())) {
        in >> alnum;
        name += alnum;
    }
    return name;
}

