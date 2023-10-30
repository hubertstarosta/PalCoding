#include "engine.h"
#include "util.h"

bool run_statements(struct context *ctx, const char **input, struct error *err) {
    // Skip the whitespace at the beginning of the input.
    skip_whitespace(input);

    // Check if we are at a valid end of a sequence of statements, in which case, do nothing.
    if (**input == '\0' || **input == '}')
        return true;

    // Otherwise, run a single statement and then the rest of the statements.
    return run_statement(ctx, input, err) && run_statements(ctx, input, err);
}

bool run_statement(struct context *ctx, const char **input, struct error *err) {
    skip_whitespace(input); // Skip any leading whitespace

    if(starts_with(*input, "ENQ(")){
        *input = *input + 4; // Skip "ENQ("
        int value;
        if (eval_expression(ctx, input, err, &value)) {
            enqueue(&ctx->q, value);
            if (**input == ')') {
                *input += 1; // Skip ")"
                return true;
            }
        }
        return false;
    }

    if(starts_with(*input, "ASSERT")){
        *input = *input + 6;
        bool condition;
        if (eval_condition(ctx, input, err, &condition)) {
            if(condition == false){
                err->pos = *input;
                err->desc = "Failed Assert";
                return false;  // This should be false, not true
            }
            return true;
        }
        return false;
    }

    if(starts_with(*input, "x") || starts_with(*input, "y")) {
        char v = **input;
        *input = *input + 2; // Skip variable and equal sign
        int val;
        if (eval_expression(ctx, input, err, &val)) {
            if (v == 'x') {
                ctx->x = val;
            } else {
                ctx->y = val;
            }
            return true;
        }
        return false;
    }

    err->pos = *input;
    err->desc = "not one of 3 statements";
    return false;
}

bool eval_expression(struct context *ctx, const char **input, struct error *err, int *out) {
    if (**input == 'x' || **input == 'y') {
        *out = (**input == 'x') ? ctx->x : ctx->y;
        (*input)++;
        return true;
    }

    if (parse_integer(input, err, out)) {
        return true;
    }

    if(starts_with(*input, "DEQ")){
        *input = *input + 3;
        if(dequeue(&ctx->q, out)){
            return true;
        }
        else{
            err->pos = *input;
            err->desc = "empty queue";
            return false;
        }
    }

    err->pos = *input;
    err->desc = "not one of three";

    return false;
}

bool eval_condition(struct context *ctx, const char **input, struct error *err, bool *out) {
    if (starts_with(*input, "EMPTY")){
        *input = *input+5;
        *out = queue_empty(&ctx->q);
        return true;
    }

    if (eval_expression(ctx, input, err, (int *) out)) {
        int left_value = *out;
        skip_whitespace(input); // Skip whitespace after left expression
        if (starts_with(*input, "=")) {
            *input += 1; // Skip "="
            int right_value;
            if (eval_expression(ctx, input, err, &right_value)) {
                *out = (left_value == right_value);
                return true;
            }
        }
    }

    if (eval_expression(ctx, input, err, (int *) out)) {
        int left_value = *out;
        skip_whitespace(input); // Skip whitespace after left expression
        if (starts_with(*input, "<")) {
            (*input)++; // Skip "<"
            int right_value;
            if (eval_expression(ctx, input, err, &right_value)) {
                *out = (left_value < right_value);
                return true;
            }
        }
    }

    err->pos = *input;
    err->desc = "not 1 of three";
    return false;
}

bool parse_integer(const char **input, struct error *err, int *out) {
    const char *before = *input;
    int result = (int) strtol(before, (char **) input, 10);

    if (*input == before) {
        err->pos = before;
        err->desc = "expected an integer";
        return false;
    } else {
        *out = result;
        return true;
    }
}
