

%{
    //Program 13: write a flex program to Remove comments from a C program
    #include <stdio.h>
%}

%option noyywrap

%%

"/*"([^*]|[\r\n]|(\*+([^*/]|[\r\n])))*\*+/ {
    // Remove multiline comments
}

"//".* {
    // Remove single-line comments
}

. {
    printf("%s", yytext);
}

%%

int main() {
    yylex();
    return 0;
}