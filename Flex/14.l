
%{
    //Program 14: Write a program to Check for valid IP addresses
#include <stdio.h>
%}

%%

([0-9]|[1-9][0-9]|1[0-9]{2}|2[0-4][0-9]|25[0-5])\.
([0-9]|[1-9][0-9]|1[0-9]{2}|2[0-4][0-9]|25[0-5])\.
([0-9]|[1-9][0-9]|1[0-9]{2}|2[0-4][0-9]|25[0-5])\.
([0-9]|[1-9][0-9]|1[0-9]{2}|2[0-4][0-9]|25[0-5]) {
    printf("%s is a valid IP address\n", yytext);
}

. {
    printf("Invalid IP address: %s\n", yytext);
}

%%

int yywrap(){}

int main() {
    yylex();
    return 0;
}
