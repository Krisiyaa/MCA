
%{
    //Program 9: Write  a flex program to Check for valid email addresses
#include <stdio.h>
%}

%%

[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,} {
    printf("%s is a valid email address\n", yytext);
}

.*  {
    printf("Invalid input: %s\n", yytext);
}
%%


int yywrap(){}

int main() {
    yylex();
    return 0;
}
