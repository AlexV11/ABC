#include "lexer.h"

void mostrar_token(token_t);
int main(int argc, char const **args)
{
    if(argc !=2){
        fprintf(stderr, "USO: %s archivo\n", args[0]);
    }
    FILE *f = fopen(args[1], "r");
    token_t t;
    while((t = get_token(f)).token != FIN){
        mostrar_token(t);
    }
    return 0;
}

void mostrar_token(token_t t){
    char *s_tokens[] = {"P_IZQ", "P_DER", "C_IZQ", "C_DER", "SUMA", "RESTA", "MULT", "DIV", "MAYOR", "MAYOR_IGUAL", "MENOR", "MENOR_IGUAL", "IGUAL", "DIFERENTE", "ASIGNA", "TERMINA", "NUMERO", "TEXTO", "TRUE", "FALSE", "VARIABLE", "NOM_VAR", "BLANCO", "WHILE", "DO", "IF", "THEN", "FIN", "ERROR"};

    printf("Tipo: %s\n",s_tokens[t.token]);
    printf("Lexema: %s\n", t.lexema);
}