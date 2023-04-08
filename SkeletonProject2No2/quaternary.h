// CMSC 330 Advanced Programming Languages
// Project 2 Skeleton
// UMGC CITE
// Spring 2023
// Johnathan Brandstetter

class Quaternary : public SubExpression {
public:
    Quaternary(Expression* left, Expression* right, Expression* third, Expression* condition) : SubExpression(left, right), third(third){
        this ->condition = condition;
    }

    double evaluate() {
        double condVal = condition->evaluate();
        if (condVal < 0) {
            return left->evaluate();
        }

        else if (condVal == 0) {
            return right->evaluate();
        }

        else {
            return third->evaluate();
        }
    }

private:
    Expression* third;
    Expression* condition;
};