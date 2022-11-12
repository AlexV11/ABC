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

    if (blancos() && sentencia() && blancos()) return 1;
    if (blancos() && bloque() && blancos()) return 1;

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
}

int bloque(void) {
    if (ciclo() && s()) return 1;
    if (condicional() && s()) return 1;
}

int declaracion(void) {
    token_t token = get_token();
    if (VARIABLE == token.token) {
        if (blancos()) {
            token = get_token();
            if (NOM_VAR == token.token) {
                if (blancos()) {
                    token = get_token();
                    if (ASIGNA == token.token) {
                        if (blancos()) {
                            if (operacion()) return 1;
                        }
                    }
                }
            }
        }
    }
}

int blancos(void) {
    token_t token = get_token();
    if (BLANCO == token.token) {
        if (blancos()) return 1;
    }
    unget_token(token);
    return 1;
}

int operacion(void) {
    if (valor()) return 1;

    token_t token = get_token();
    if (NOM_VAR == token.token) {
        if (blancos()) {
            if (operador()) {
                if (blancos()) {
                    token_t token = get_token();
                    if (NOM_VAR == token.token) return 1;
                }
            }
        }
    }
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
            if (blancos()) {
                token_t token = get_token();
                if (NOM_VAR == token.token) {
                    if (blancos()) {
                        token_t token = get_token();
                        if (P_DER == token.token) return 1;
                    }
                }
            }
        }
    }
}

int ciclo(void) {
    token_t token = get_token();
    if (WHILE == token.token) {
        if (blancos()) {
            token_t token = get_token();
            if (P_IZQ == token.token) {
                if (blancos()) {
                    if (condicion()) {
                        if (blancos()) {
                            token_t token = get_token();
                            if (P_DER == token.token) {
                                if (blancos()) {
                                    token_t token = get_token();
                                    if (DO == token.token) {
                                        if (blancos()) {
                                            token_t token = get_token();
                                            if (C_IZQ == token.token) {
                                                if (blancos()) {
                                                    if (s()) {
                                                        if (blancos()) {
                                                            token_t token = get_token();
                                                            if (C_DER == token.token) return 1;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

int condicional(void) {
    token_t token = get_token();
    if (IF == token.token) {
        if (blancos()) {
            token_t token = get_token();
            if (P_IZQ == token.token) {
                if (blancos()) {
                    if (condicion()) {
                        if (blancos()) {
                            token_t token = get_token();
                            if (P_DER == token.token) {
                                if (blancos()) {
                                    token_t token = get_token();
                                    if (THEN == token.token) {
                                        if (blancos()) {
                                            token_t token = get_token();
                                            if (C_IZQ == token.token) {
                                                if (blancos()) {
                                                    if (s()) {
                                                        if (blancos()) {
                                                            token_t token = get_token();
                                                            if (C_DER == token.token) return 1;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

int condicion(void) {
    token_t token = get_token();
    if (NOM_VAR == token.token) {
        if (blancos()) {
            if (op_log_rel()) {
                if (blancos()) {
                    token_t token = get_token();
                    if (NOM_VAR == token.token) return 1;
                }
            }
        }
    }

    unget_token(token);

    if (NOM_VAR == token.token) return 1;
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