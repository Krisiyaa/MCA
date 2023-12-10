%{
#include <stdio.h>
%}

%%

[0-9]+ {
    printf("%s is a digit\n", yytext);
}

[a-zA-Z]+ {
    printf("%s is a word\n", yytext);
}

.   {

}

%%

int yywrap() {}

int main() {
    yylex();
    return 0;
}
