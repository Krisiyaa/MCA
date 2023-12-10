
%{
    //Program 15: write a flex program to Check for valid hexadecimal numbers
#include <stdio.h>
%}

%%

0[xX][0-9a-fA-F]+ {
    printf("%s is a valid hexadecimal number\n", yytext);
}

. {
    printf("Invalid hexadecimal number: %s\n", yytext);
}

%%

int yywrap(){}

int main() {
    yylex();
    return 0;
}