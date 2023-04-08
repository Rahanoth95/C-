// CMSC 330 Advanced Programming Languages
// Project 2 Skeleton
// UMGC CITE
// Spring 2023
// Johnathan Brandstetter


// This file contains the class definition of the SubExpression class, which is a subclass of Expression.
// Because it does not implement the abstract function evaluate, it is an abstract class. SubExpression
// objects are represented with the left and right subexpressions. The body of its constructor and the
// static (class) function parse are defined in subexpression.cpp.

class SubExpression : public Expression {
public:
    //constructor
    SubExpression(Expression *left, Expression *right);
    //declare a static function parse()
    static Expression *parse(stringstream &in);

protected:
    //declare the variables
    Expression *left;
    Expression *right;
};    