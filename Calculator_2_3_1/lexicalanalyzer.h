#ifndef MYCALC_2_LEXICALANALYZER_H
#define MYCALC_2_LEXICALANALYZER_H

typedef enum {
    INITIAL_STATUS,
    IN_INT_PART_STATUS,
    DOT_STATUS,
    IN_FRAC_PART_STATUS
} LexerStatus;


void parse_line(char *buf);
#endif //MYCALC_2_LEXICALANALYZER_H
