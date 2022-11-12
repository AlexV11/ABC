#include "parser.h"

int sentencia(void);
int bloque(void);
int declaracion(void);
int reasignacion(void);
int operacion(void);
int operador(void);
int valor(void);
int funcion(void);
int ciclo(void);
int condicional(void);
int condicion(void);
int op_log_rel(void);

int s(void) {
    if (bloque()) return 1;
    if (sentencia()) return 1;

    token_t token = get_token();
    if(token.token == FIN) return 1;
    if(token.token == C_DER) {
        unget_token(token);
        return 1;
    }
    unget_token(token);
    return 0;
}

int sentencia(void) {
    if (declaracion()) {
        token_t token = get_token();
        if (token.token == TERMINA) {
            if (s()) return 1;
        }
        unget_token(token);
    }
    if (funcion()) {
        token_t token = get_token();
        if (token.token == TERMINA) {
            if (s()) return 1;
        }
        unget_token(token);
    }
    if (reasignacion()) {
        token_t token = get_token();
        if (token.token == TERMINA) {
            if (s()) return 1;
        }
        unget_token(token);
    }
    return 0;
}

int bloque(void) {
    if (ciclo() && s()) return 1;
    if (condicional() && s()) return 1;
    return 0;
}

int declaracion(void) {
    token_t token = get_token();
    if (VARIABLE == token.token) {
        token_t token = get_token();
        if (NOM_VAR == token.token) {
            token_t token = get_token();
            if (ASIGNA == token.token) {
                if (operacion()) return 1;
            }
            unget_token(token);
        }
        unget_token(token);
    }
    unget_token(token);
    return 0;
}

int reasignacion(void) {
    token_t token = get_token();
    if (NOM_VAR == token.token) {
        token_t token = get_token();
        if (ASIGNA == token.token) {
            if (operacion()) return 1;
        }
        unget_token(token);
    }
    unget_token(token);
    return 0;
}

int operacion(void) {
    if (valor()) return 1;
    token_t token = get_token();
    
    if (NOM_VAR == token.token) {
        if (operador()) {
            token_t token = get_token();
            if (NOM_VAR == token.token) return 1;
            unget_token(token);
        }
    }
    unget_token(token);
    return 0;
}

int operador(void) {
    token_t token = get_token();

    if (SUMA == token.token) return 1;
    if (RESTA == token.token) return 1;
    if (MULT == token.token) return 1;
    if (DIV == token.token) return 1;

    unget_token(token);
    return 0;
}

int valor(void) {
    token_t token = get_token();
    

    if (NUMERO == token.token) return 1;
    if (TEXTO == token.token) return 1;
    if (TRUE == token.token) return 1;
    if (FALSE == token.token) return 1;

    unget_token(token);
    return 0;
}

int funcion(void) {
    token_t token = get_token();
    if (PRINT == token.token) {
        token_t token = get_token();
        if (P_IZQ == token.token) {
            token_t token = get_token();
            if (NOM_VAR == token.token) {
                token_t token = get_token();
                if (P_DER == token.token) return 1;
                unget_token(token);
            }
            unget_token(token);
        }
        unget_token(token);
    }
    unget_token(token);
    return 0;
}

int ciclo(void) {
    token_t token = get_token();
    if (WHILE == token.token) {
        token_t token = get_token();
        if (P_IZQ == token.token) {
            if (condicion()) {
                token_t token = get_token();
                if (P_DER == token.token) {
                    token_t token = get_token();
                    if (DO == token.token) {
                        token_t token = get_token();
                        if (C_IZQ == token.token) {
                            if (s()) {
                                token_t token = get_token();
                                if (C_DER == token.token) return 1;
                                unget_token(token);
                            }
                        }
                        unget_token(token);
                    }
                    unget_token(token);
                }
                unget_token(token);
            }
        }
        unget_token(token);
    }
    unget_token(token);                    
    return 0;
}

int condicional(void) {
    token_t token = get_token();
    if (IF == token.token) {
        token_t token = get_token();
        if (P_IZQ == token.token) {
            if (condicion()) {
                token_t token = get_token();
                if (P_DER == token.token) {
                    token_t token = get_token();
                    if (THEN == token.token) {
                        token_t token = get_token();
                        if (C_IZQ == token.token) {
                            if (s()) {
                                token_t token = get_token();
                                if (C_DER == token.token) return 1;
                                unget_token(token);
                            }
                        }
                        unget_token(token);
                    }
                    unget_token(token);
                }
                unget_token(token);
            }
        }
        unget_token(token);
    }
    unget_token(token);
    return 0;
}

int condicion(void) {
    token_t token = get_token();
    if (NOM_VAR == token.token) {
        if (op_log_rel()) {
            token_t token = get_token();
            if (NOM_VAR == token.token) return 1;
            unget_token(token);
        }
    }
    if (NOM_VAR == token.token) return 1;
    unget_token(token);
    return 0;
}

int op_log_rel(void) {
    token_t token = get_token();

    if (IGUAL == token.token) return 1;
    if (MAYOR == token.token) return 1;
    if (MENOR == token.token) return 1;
    if (MAYOR_IGUAL == token.token) return 1;
    if (MENOR_IGUAL == token.token) return 1;
    if (DIFERENTE == token.token) return 1;

    unget_token(token);
    return 0;
}