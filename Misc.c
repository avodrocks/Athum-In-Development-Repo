#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

#include "Misc.h"

char* GetIndent(size_t Size) {
	char* IndentString = malloc(Size + 1 * sizeof(char));

	if (IndentString == NULL) {
		printf("[Athum]: Failed to allocate memory for -> IndentString");

		return NULL;
	};

	for (size_t Index = 0; Index < Size; Index++) {
		IndentString[Index] = '\t';
	};

	IndentString[Size] = '\0';

	return IndentString;
}
