#ifndef _LEXER_
#define _LEXER_

#include <stdio.h>
#include <ctype.h>
#include "token.h"

extern token_t get_token(FILE *f);

#endif