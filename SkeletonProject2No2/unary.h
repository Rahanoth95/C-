// CMSC 330 Advanced Programming Languages
// Project 2 Skeleton
// UMGC CITE
// Spring 2023
// Johnathan Brandstetter

class Unary : public SubExpression {
public:
    Unary(Expression *left, Expression *right) : SubExpression(left, right) {
    }

    double evaluate() {
        return ~(int)(left ->evaluate());
    }
};