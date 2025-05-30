/*
 * assemble.c
 *
 *  
 *      Author: Naseem
 */

#ifndef PARSE_H
#define PARSE_H

#include <ctype.h>
#include <string.h>

#include "util.h"
#include "list.h"

/**
 * Converts line of *!macro expanded!* assembly source code to individual string tokens based on the language
 * specification in the assignment
 *
 * @param line line of assembly source code
 * @return list of strings where each string is a token from the line in reverse order
 */
List* tokenize(char* line);

/**
 * Convert's opcode string rep (from source code) to integer number rep based on
 * the spec in the assignment
 *
 * @param opcode opcode string rep
 * @return the opcode integer rep. returns -1 if undefined opcode string is provided
 */
int get_opcode(char* opcode);

/**
 * Converts operand token from source code form to type value
 * string form where the first character is the type of operand (label-l,register-r,immediate-i)
 * and the rest of the characters are the string rep of the operand. remove's white space
 *
 * @param start pointer to the start of the operand in the line string
 * @param end pointer to the end of the operand in the line string
 * @param type_val a string in which to put the type value string copy of the line string segment containing the operand
 */
void parse_tok(char *start, char *end, char* type_val);

/**
 * Converts a line of source code to the individual tokens that make it up.
 *
 * @param line the line string to parse
 * @param type a reference to a byte in which to put the type of token
 * @param tokens a zeroed array of character to put the token strings in
 * @param num_tokens a reference to an integer in which to put the number of tokens extracted from the line
 */
void parse_line(char* line, byte *type, char tokens[MAX_TOKENS_PER_LINE][MAX_TOKEN_LEN], int *num_tokens);

#endif /* PARSE_H_ */
