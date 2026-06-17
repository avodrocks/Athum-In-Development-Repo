#ifndef LEXER_H
#define LEXER_H

#include <stddef.h>

#include "Token.h"

typedef struct {
	char* Source;
	size_t StrC;
	size_t Line;
	size_t StrCLine;
	size_t SizeTokenList;
	LTOKEN_STRUCT* TokenList;
} LLEXER_STRUCT;

LLEXER_STRUCT* New_LLEXER_STRUCT(char* Source);
int AppendToken(LLEXER_STRUCT* self, LTOKEN_STRUCT* TokenStruct);

#endif
