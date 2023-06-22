#include "monty.h"

/**
 * _closefile - Close a given file.
 *
 * @file: The memory address to the file to close
 *
 **/
void _closefile(FILE *file)
{
	fclose(file);
}
