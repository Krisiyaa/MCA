%{
    //Program 12: write a flex program to Convert lowercase letters to uppercase
    #include <stdio.h>
%}

%%

[a-z] {
    printf("%c", yytext[0] - 32);
}

\n {
    printf("\n");
}

. {
    printf("%s", yytext);
}

%%

int yywrap(){}

int main() {
    yylex();
    return 0;
}