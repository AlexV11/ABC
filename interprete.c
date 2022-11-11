#include "parser.h"

void mostrar_token(token_t);

int main(int argc, char const **args) {
    if (argc != 2)
    {
        fprintf(stderr, "USO: %s archivo\n", args[0]);
        return 1;
    }
    f = fopen(args[1], "r");
    if (s()) {
        fprintf(stdout, "OK\n");
        return 0;
    } else {
        fprintf(stderr, "ERROR\n");
        return 1;
    }
}

void mostrar_token(token_t t)
{
    char *s_tokens[] = {
        "P_IZQ",
        "P_DER",
        "C_IZQ",
        "C_DER",
        "RESTA",
        "SUMA",
        "MULT",
        "DIV",
        "MAYOR",
        "MAYOR_IGUAL",
        "MENOR",
        "MENOR_IGUAL",
        "IGUAL", 
        "DIFERENTE", 
        "ASIGNA", 
        "TERMINA", 
        "NUMERO", 
        "TEXTO", 
        "TRUE", 
        "FALSE", 
        "VARIABLE", 
        "PRINT", 
        "NOM_VAR", 
        "BLANCO", 
        "WHILE", 
        "DO",
        "IF", 
        "THEN", 
        "FIN", 
        "ERROR"
    };

    printf("Tipo: %s\n", s_tokens[t.token]);
    printf("Lexema: %s\n", t.lexema);
    printf("-----------------\n");
}