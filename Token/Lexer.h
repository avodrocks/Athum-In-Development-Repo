#ifndef LEXER_H
#define LEXER_H

#include <stddef.h>

#include "Token.h"

typedef struct {
	char* Source;
	size_t SizeSource;
	size_t StrC;
	size_t Line;
	size_t StrCLine;
	size_t SizeTokenList;
	size_t CapacityTokenList;
	LTOKEN_STRUCT* TokenList;
} LLEXER_STRUCT;

LLEXER_STRUCT* New_LLEXER_STRUCT(char* Source, size_t SourceSize);
int AppendToken(LLEXER_STRUCT* self, LTOKEN_STRUCT* TokenStruct);
int FreeTokens(LLEXER_STRUCT* self);
char PeekNextCharacter(LLEXER_STRUCT* self, size_t N);
char AdvanceToNextCharacter(LLEXER_STRUCT* self);
void GetTokensFromCurrent(LLEXER_STRUCT* self);
void GetTokensFromSource(); // TODO impl

#endif
