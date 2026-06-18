#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

#include "Lexer.h"
#include "Token.h"

LLEXER_STRUCT* New_LLEXER_STRUCT(char* Source) {
	LLEXER_STRUCT* NewLexerStruct;

	NewLexerStruct->Source = Source;
	NewLexerStruct->Line = 1;
	NewLexerStruct->StrCLine = 0;
	NewLexerStruct->StrC = 0;
	NewLexerStruct->SizeTokenList = 0;
	NewLexerStruct->CapacityTokenList = 256; // initial size
	NewLexerStruct->TokenList = malloc(NewLexerStruct->CapacityTokenList * sizeof(LTOKEN_STRUCT));

	return NewLexerStruct;
}

int AppendToken(LLEXER_STRUCT* self, LTOKEN_STRUCT* TokenStruct) {
	if (self->SizeTokenList > self->CapacityTokenList) {
		self->CapacityTokenList *= 2;

		LTOKEN_STRUCT* NewTokenList = realloc(self->TokenList, self->CapacityTokenList * sizeof(LTOKEN_STRUCT));

		if (NewTokenList == NULL) {
			printf("[Athum]: Failed to reallocate LLEXER_STRUCT->TokenList");

			return 1;
		};

		self->TokenList = NewTokenList;
	};

	self->TokenList[self->SizeTokenList] = *TokenStruct;
	self->SizeTokenList++;

	return 0;
}

int FreeTokens(LLEXER_STRUCT* self) {
	for (size_t Idx = 0; Idx < self->SizeTokenList; Idx++) {
		FreeToken(&self->TokenList[Idx]);
	};

	if (self->TokenList != NULL) {
		free(self->TokenList);
		self->TokenList = NULL;
	};

	if (self->TokenList == NULL) {
		printf("[Athum Warning]: Tried to free already freed lexer tokens list");
	};

	return 0;
}
