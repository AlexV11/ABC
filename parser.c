#include "parser.h"

int sentencia(void);
int bloque(void);
int declaracion(void);
int blancos(void);
int operacion(void);
int operador(void);
int valor(void);
int funcion(void);
int ciclo(void);
int condicional(void);
int condicion(void);
int op_log_rel(void);

int s(void) {
    token_t token = get_token();

    if (sentencia()) return 1;
    if (bloque()) return 1;
    unget_token(token);
    return 0;
}

int sentencia(void) {
    if (declaracion()) {
        token_t token = get_token();
        if (token.token == TERMINA) {
            if (s()) return 1;
        }
    }

    if (funcion()) {
        token_t token = get_token();
        if (token.token == TERMINA) {
            if (s()) return 1;
        }
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

    if (token.token == VARIABLE) {
        token_t token = get_token();
        if (blancos()) {
            if (token.token == NOM_VAR) {
                token_t token = get_token();
                if (token.token == ASIGNA) {
                    if (operacion()) return 1;
                }
            }
        }
    }
}

int blancos(void) {
    token_t token = get_token();

    if (token.token == BLANCO) {
        if (blancos()) return 1;
    }

    unget_token(token);
    return 1;
}

int operacion(void) {
    if (valor()) return 1;

    token_t token = get_token();
    if (token.token == NOM_VAR) {
        if (operador()) {
            token_t token = get_token();
            if (token.token == NOM_VAR) return 1;
        }
    }

    return 0;
}

int operador(void) {
    token_t token = get_token();

    if (token.token == SUMA) return 1;
    if (token.token == RESTA) return 1;
    if (token.token == MULT) return 1;
    if (token.token == DIV) return 1;

    return 0;
}

int valor(void) {
    token_t token = get_token();

    if (token.token == TRUE) return 1;
    if (token.token == FALSE) return 1;
    if (token.token == TEXTO) return 1;
    if (token.token == NUMERO) return 1;

    return 0;
}

int funcion(void) {
    token_t token = get_token();

    if (token.token == PRINT) {
        token_t token = get_token();
        if (token.token == P_IZQ) {
            token_t token = get_token();
            if (token.token == NOM_VAR) {
                token_t token = get_token();
                if (token.token == P_DER) return 1;
            }
        }
    }

    return 0;
}

int ciclo(void) {
    token_t token = get_token();

    if (token.token == WHILE) {
        token_t token = get_token();
        if (token.token == P_IZQ) {
            if (condicion()) {
                token_t token = get_token();
                if (token.token == P_DER) {
                    token_t token = get_token();
                    if (token.token == DO) {
                        token_t token = get_token();
                        if (token.token == C_IZQ) {
                            if (s()) {
                                token_t token = get_token();
                                if (token.token == C_DER) return 1;
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}

int condicional(void) {
    token_t token = get_token();

    if (token.token == IF) {
        token_t token = get_token();
        if (token.token == P_IZQ) {
            if (condicion()) {
                token_t token = get_token();
                if (token.token == P_DER) {
                    token_t token = get_token();
                    if (token.token == THEN) {
                        token_t token = get_token();
                        if (token.token == C_IZQ) {
                            if (s()) {
                                token_t token = get_token();
                                if (token.token == C_DER) return 1;
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}

int condicion(void) {
    token_t token = get_token();

    if (token.token == NOM_VAR) {
        if (op_log_rel()) {
            token_t token = get_token();
            if (token.token == NOM_VAR) return 1;
        }

        return 1;
    }

    return 0;
}

int op_log_rel(void) {
    token_t token = get_token();

    if (token.token == MAYOR) return 1;
    if (token.token == MENOR) return 1;
    if (token.token == IGUAL) return 1;
    if (token.token == DIFERENTE) return 1;
    if (token.token == MAYOR_IGUAL) return 1;
    if (token.token == MENOR_IGUAL) return 1;

    unget_token(token);
    return 0;
}