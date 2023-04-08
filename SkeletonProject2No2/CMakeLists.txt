cmake_minimum_required(VERSION 3.24)
project(SkeletonProject2No2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(.idea)

add_executable(SkeletonProject2No2
        .idea/.gitignore
        .idea/modules.xml
        .idea/projectexpressioncpp.iml
        .idea/workspace.xml
        and.h
        divide.h
        expression.h
        greaterThan.h
        lessThan.h
        literal.h
        minus.h
        project2.cpp
        operand.cpp
        operand.h
        parse.cpp
        parse.h
        plus.h
        subexpression.cpp
        subexpression.h
        symboltable.cpp
        symboltable.h
        ternary.h
        times.h
        variable.cpp
        variable.h
        xor.h ternary.h
        quaternary.h
        unary.h modulo.h)
