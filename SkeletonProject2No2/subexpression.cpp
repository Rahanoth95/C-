#include <iostream>
#include <sstream>

using namespace std;

#include "expression.h"
#include "subexpression.h"
#include "operand.h"
#include "plus.h"
#include "minus.h"
#include "times.h"
#include "divide.h"
#include "and.h"
#include "greaterThan.h"
#include "lessThan.h"
#include "ternary.h"
#include "xor.h"
#include "quaternary.h"
#include "unary.h"
#include "modulo.h"



SubExpression::SubExpression(Expression *left, Expression *right) {
    this->left = left;
    this->right = right;
}

Expression *SubExpression::parse(stringstream &in) {
    Expression* left;
    Expression* right;
    Expression* third;

    Expression* condition;
    char operation, paren;


    /* This is where the program determines which of the three tupes of <exp> needs to be built.*/
    left = Operand::parse(in);

    //IF else statements then switch statement
    in >> operation;

    if (operation == '~') {// Unary Expression
        in >> paren;
        return new Unary(left,NULL); //Passing a NULL as the second argument as the negation operation really only functions on one operand

    } else if (operation == '?') {//ternary Expression
        right = Operand::parse(in);
        in >> paren;
        condition = Operand::parse(in);
        in >> paren;
        return new Ternary(left, right, condition);


    } else if (operation == '#') {//ternary Expression
        right = Operand::parse(in);
        in >> paren;
        third = Operand::parse(in);
        in >> paren;
        condition = Operand::parse(in);
        in >> paren;
        return new Quaternary(left, right, third, condition);

    } else {//Every other Expression

        //These two operations need to be performed for every case that follows
        right = Operand::parse(in);
        in >> paren;

        switch (operation) {
            case '+':
                return new Plus(left, right);
            case '-':
                return new Minus(left, right);
            case '*':
                return new Times(left, right);
            case '/':
                return new Divide(left, right);
            case '&':
                return new And(left, right);
            case '>':
                return new GreaterThan(left, right);
            case '<':
                return new LessThan(left, right);
            case '^':
                return new Xor(left, right);
            case '%':
                return new Modulo(left, right);
        }
    }
    return 0;
}
        