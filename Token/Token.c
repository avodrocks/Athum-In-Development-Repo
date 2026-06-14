#include <stdint.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdint.h>

#include "../Misc.h"

#include "Token.h"

const char* LTOKEN_TYPE_MAP[] = {
	"LTOKEN_EOF", "LTOKEN_NUM",
	"LTOKEN_STR", "LTOKEN_SHB",
	"LTOKEN_CMT", "LTOKEN_IDT",
	"LTOKEN_SYM", "LTOKEN_RES",
};

LTOKEN_STRUCT New_LTOKEN_STRUCT(LTOKEN_TYPE Type, char* Source, size_t Index) {
	return (LTOKEN_STRUCT){
		.TokenType = Type, .Value = Source, .Index = Index,
	};
}

int PrintToken(LTOKEN_STRUCT* Token, size_t TabSize) {
	char* IndentString = GetIndent(TabSize);

	if (IndentString == NULL) {
		printf("[Athum]: Cannot proceed printing token, failed memory allocation.");

		return 1;
	};

	printf("%sToken #%d:\n", IndentString, (uint_fast8_t)Token->Index);
	printf("%s	Type: %s\n", IndentString, LTOKEN_TYPE_MAP[Token->TokenType]);
	printf("%s	Value: \"%s\"\n", IndentString, Token->Value);

	free(IndentString);
	IndentString = NULL;

	return 0;
};
