#ifndef TOKEN_H
#define TOKEN_H

#include <stddef.h>

#include "TokenTypes.h"

typedef struct {
	LTOKEN_TYPE TokenType;
	char* Value;
	size_t Index;

} LTOKEN_STRUCT;

LTOKEN_STRUCT New_LTOKEN_STRUCT(LTOKEN_TYPE Type, char* Source, size_t Index);
int PrintToken(LTOKEN_STRUCT* Token, size_t TabSize);

#endif
