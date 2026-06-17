#include <stddef.h>
#include <stdlib.h>

#include "Lexer.h"
#include "Token.h"

LLEXER_STRUCT* New_LLEXER_STRUCT(char* Source) {
	LLEXER_STRUCT* NewLexerStruct;

	NewLexerStruct->Source = Source;
	NewLexerStruct->Line = 1;
	NewLexerStruct->StrCLine = 0;
	NewLexerStruct->StrC = 0;
	NewLexerStruct->SizeTokenList = 256; // initial size
	NewLexerStruct->TokenList = malloc(NewLexerStruct->SizeTokenList * sizeof(LTOKEN_STRUCT));

	return NewLexerStruct;
}

int AppendToken(LLEXER_STRUCT* self, LTOKEN_STRUCT* TokenStruct) {
	return -1; // TODO
}
