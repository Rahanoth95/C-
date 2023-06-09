// CMSC 330 Advanced Programming Languages
// Project 2 Skeleton
// UMGC CITE
// Spring 2023
// Johnathan Brandstetter

// This file contains the class definition of the Ternary class, which is a subclass of SubExpression,
// which in turn is a subclass of the Expression. Because both of its functions are one line functions,
// they are implemented as inline functions. Its constructor initializes the left and right subexpressions
// it inherits from SubExpression by calling the constructor of the SubExpression class. Because
// it is an indirect subclass of Expression it must implement the evaluate function, which it does
// by returning the ternary function of the two subexpressions.


class Ternary : public SubExpression {
public:
    Ternary(Expression *left, Expression *right, Expression *condition) : SubExpression(left, right) {
        this->condition = condition;
    }

    double evaluate() {
        return condition->evaluate() ? left->evaluate() : right->evaluate();
    }

private:
    Expression *condition;
};