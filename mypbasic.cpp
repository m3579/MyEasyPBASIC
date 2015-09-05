/*
 * mybasic.cpp
 *
 * /MyEasyPBASIC/Sources/src/mybasic.cpp
 *
 *       Author: Mihir Kasmalkar
 * Date created: Sep 4, 2015
 *
 *      Purpose: The entry point for the compiler.
 *
 *        Usage:
 *              $ mypbasic
 *              Displays information about the MyEasyPBASIC compiler
 *
 *              $ mypbasic file
 *              Compiles the given file
 *
 *        Notes:
 *
 */

#include <iostream>

#include "Lexer.hpp"
#include "Parser.hpp"
#include "cleancode.h"

#define VERSION 0.1

using namespace lexer;
using namespace token;
using namespace parser;
using namespace node;

void compile(const char* filename);

int main(int argc, const char* argv[])
{
    // Skip the first argument (program name)
    argv++;
    argc--;

    if (argc == 0) {
        std::cout << "My Easy PBASIC\n"
                  << "It's PBASIC for today\n"
                  << "Version " << VERSION << "\n";
    }

    else if (argc == 1) {
        compile(argv[0]);
    }
    
    else {
        std::cout << "I could not recognize this command\n"
                  << "$ pbasic [file]\n"
                  << "\n";
    }
}

createTokenType(TTYPE_INT);

createNodeType(NTYPE_INT);

bool isNumber(const char character);

void compile(const char* filename)
{
    Lexer lexer("1");

    setLexer(lexer);

    makeTest(sc)
    {
        const char currChar = sc.getCurrentChar();
        if (isNumber(currChar)) {
            return Token(currChar, TTYPE_INT);
        }

        return Token();
    }
    endTest

    Parser parser(lexer);

    createTerminal(firstTerminal)
    forTokenType(TTYPE_INT)
    withId("Integer")
    {
        astAction(tm)
        {
            return Node(tm.getCurrentToken(), NTYPE_INT);
        }
    }
    endTerminal

    parser.addTerminal(firstTerminal);

    ast::SyntaxTree tree(parser.createSyntaxTree());

    tree.print("");

}

bool isNumber(const char character)
{
    if (character == '1'
        || character == '2'
        || character == '3'
        || character == '4'
        || character == '5'
        || character == '6'
        || character == '7'
        || character == '8'
        || character == '9'
        || character == '0') {

        return true;
    }

    return false;
}
