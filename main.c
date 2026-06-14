#include <stdio.h>

#include "Token/Token.h"

int main() {
	printf("Hello World!\n");

	LTOKEN_STRUCT Example = New_LTOKEN_STRUCT(LTOKEN_STR, "Hello World", 1);

	int Success = PrintToken(&Example, 0);

	if (Success == 1) {
		return 1;
	};

	return 0;
}
