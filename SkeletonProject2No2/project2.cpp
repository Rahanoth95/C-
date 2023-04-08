// CMSC 330 Advanced Programming Languages
// Project 2 Skeleton
// UMGC CITE
// Spring 2023

// This file contains the main function for the project 2 skeleton. It reads an input file named input.txt
// that contains one statement that includes an expression following by a sequence of variable assignments.
// It parses each statement and then evaluates it.

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

#include "expression.h"
#include "subexpression.h"
#include "symboltable.h"
#include "parse.h"

SymbolTable symbolTable;

void parseAssignments(stringstream &in);

int main() {
    const int SIZE = 256;
    Expression *expression;
    char paren, comma, line[SIZE];
    ifstream fin("input.txt");
    while (true) {
        symbolTable.init();
        fin.getline(line, SIZE);
        if (!fin)break;
        stringstream in(line, ios_base::in);
        in >> paren;
        cout << line << " ";
        expression = SubExpression::parse(in);
        in >> comma;
        parseAssignments(in);
        double result = expression->evaluate();
        cout << "Value = " << result << endl;
    }
    return 0;
}

//definition of the function parseAssignments()
void parseAssignments(stringstream &in) {
    char assignop, delimiter;
    string variable;
    double value;
    symbolTable.init();
    do {
        variable = parseName(in);
        in >> ws >> assignop >> value >> delimiter;
        symbolTable.insert(variable, value);
    } while (delimiter == ',');

}
   
