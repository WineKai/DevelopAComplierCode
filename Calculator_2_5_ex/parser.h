
#ifndef CALCULATOR_2_3_1_PARSER_H
#define CALCULATOR_2_3_1_PARSER_H

#define LINE_BUF_SIZE (1024)

static void  my_get_token(Token *token);

static void unget_token(Token *token);

static double  parse_primary_expression();

static double parse_term();

double parse_expression();

double pParse_line(void);

#endif //CALCULATOR_2_3_1_PARSER_H
