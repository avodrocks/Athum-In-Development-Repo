#ifndef TOKEN_TYPES_H
#define TOKEN_TYPES_H

typedef enum {
	LTOKEN_EOF, // lua end of file token
	LTOKEN_NUM, // number (ints and floats) tokens
	LTOKEN_STR, // string/long string token
	LTOKEN_SHB, // shebang token
	LTOKEN_CMT, // lua comment/long comment token
	LTOKEN_IDT, // identifier/variable name token
	LTOKEN_SYM, // lua symbol token
	LTOKEN_RES, // lua reserved/keyword token

} LTOKEN_TYPE;

#endif
