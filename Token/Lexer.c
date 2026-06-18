#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

#include "Lexer.h"
#include "Token.h"

LLEXER_STRUCT* New_LLEXER_STRUCT(char* Source, size_t SourceSize) {
	LLEXER_STRUCT* NewLexerStruct;

	NewLexerStruct->Source = Source;
	NewLexerStruct->SizeSource = SourceSize;
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

	if (self->Source != NULL) {
		free(self->Source);
		self->Source = NULL;
	};

	if (self->TokenList == NULL) {
		printf("[Athum Warning]: Tried to free already freed lexer tokens list");
	};

	if (self->Source == NULL) {
		printf("[Athum Warning]: Tried to free already freed lexer source");
	};

	return 0;
}

char PeekNextCharacter(LLEXER_STRUCT* self, size_t N) {
	return self->Source[self->StrC + N];
}

char AdvanceToNextCharacter(LLEXER_STRUCT* self) {
	self->StrC += 1;

	return self->Source[self->StrC - 1];
}

void GetTokensFromCurrent(LLEXER_STRUCT* self) {
	// TODO impl
}

void GetTokensFromSource(); // TODO impl
