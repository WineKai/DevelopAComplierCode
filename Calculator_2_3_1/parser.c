#include <stdio.h>
#include <stdlib.h>
#include "token.h"

static Token st_look_ahead_token;
static int  st_look_ahead_token_exists;

static void  my_get_token(Token *token) {
    if (st_look_ahead_token_exists) {
        *token = st_look_ahead_token;
        st_look_ahead_token_exists = 0;
    } else {
        get_token(token);
    }
}

static void unget_token(Token *token) {
    st_look_ahead_token = *token;
    st_look_ahead_token_exists = 1;
}

double parse_expression(void);

static double  parse_primary_expression() {
    Token  token;

    my_get_token(&token);
    if (token.kind == NUMBER_TOKEN) {
        return token.value;
    }
    fprintf(stderr, "syntax error. \n");
    exit(1);
    return 0.0;
}

static double parse_term() {
    double v1;
    double v2;
    Token token;
    // primary_expression的解析函数
    v1 = parse_primary_expression();
    for (;;) {
        my_get_token(&token);
        // 循环扫描 * / 以外的字符
        if (token.kind != MUL_OPERATOR_TOKEN && token.kind != DIV_OPERATOR_TOKEN) {
            // 将记号返回
            unget_token(&token);
            break;
        }
        // primary_expression的解析函数
        v2 = parse_primary_expression();
        if (token.kind == MUL_OPERATOR_TOKEN) {
            v1 *= v2;
        } else if (token.kind == DIV_OPERATOR_TOKEN) {
            v1 /= v2;
        }
    }
    return v1;
}

double parse_expression() {
    double v1;
    double v2;
    Token token;

    v1 = parse_term();
    for (;;) {
        my_get_token(&token);
        if (token.kind != ADD_OPERATOR_TOKEN && token.kind != SUB_OPERATOR_TOKEN) {
            unget_token(&token);
            break;
        }
        v2 = parse_term();
        if (token.kind == ADD_OPERATOR_TOKEN) {
            v1 += v2;
        } else if (token.kind == SUB_OPERATOR_TOKEN) {
            v1 -= v2;
        } else {
            unget_token(&token);
        }
    }
    return v1;
}

double pParse_line(void) {
    double value;

    st_look_ahead_token_exists = 0;
    value = parse_expression();

    return value;
}


