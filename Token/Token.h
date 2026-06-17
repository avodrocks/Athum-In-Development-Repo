#ifndef TOKEN_H
#define TOKEN_H

#include <stddef.h>

#include "TokenTypes.h"

typedef struct {
	LTOKEN_TYPE TokenType;
	char* Value;
	size_t Index;
	size_t TokenLine;
	size_t TokenPos;

} LTOKEN_STRUCT;

LTOKEN_STRUCT* New_LTOKEN_STRUCT(LTOKEN_TYPE Type, char* Source, size_t Index, size_t WhatLine, size_t WhatStrC);
int PrintToken(LTOKEN_STRUCT* Token, size_t TabSize);

#endif
