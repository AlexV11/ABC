#ifndef _TOKEN_
#define _TOKEN_
#define LEXEMA 65

enum tokens{
        P_IZQ, 
        P_DER, 
        C_IZQ, 
        C_DER,
        RESTA,
        SUMA,
        MULT,
        DIV,
        MAYOR,
        MAYOR_IGUAL,
        MENOR,
        MENOR_IGUAL,
        IGUAL,
        DIFERENTE,
        ASIGNA,
        TERMINA,
        NUMERO,
        TEXTO,
        TRUE,
        FALSE,
        VARIABLE,
        PRINT,
        NOM_VAR,
        BLANCO,
        WHILE,
        DO,
        IF,
        THEN,
        FIN,
        ERROR
    };

typedef struct token{
    unsigned long posicion;
    char lexema[LEXEMA];
    int token;
}token_t;

#endif