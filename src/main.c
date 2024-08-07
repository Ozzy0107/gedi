#include <stdio.h>
#include "analyzer.h"

int main (int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <file>\n", argv[0]);
		return 1;
	}

	const char *filename = argv[1];
	if (analyze_file(filename) != 0)
	{
		fprintf(stderr, "Impossible to analyze the file %s\n");
		return 1;
	}

	return 0;
}
