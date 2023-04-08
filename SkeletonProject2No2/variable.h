// CMSC 330 Advanced Programming Languages
// Project 2 Skeleton
// UMGC CITE
// Spring 2023
// Johnathan Brandstetter
// This file contains the class definition of the Variable class. The variable is represented by its
// name, which the construcor initializes. Because this class is a subclass of Operand which in turn is
// a subclass of Expression, it must implement the function evaluate, whose body is defined in variable.cpp.

class Variable : public Operand {
public:
    Variable(string name) {
        // Add if statement to check for underscores in the name
        if (name[0] == '_') {
            throw "Error: Underscores not allowed in the first character";
        }
        this->name = name;
    }

    double evaluate();

private:
    string name;
};

