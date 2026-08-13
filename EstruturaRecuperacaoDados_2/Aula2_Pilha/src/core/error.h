#ifndef ERROR_H
#define ERROR_H

typedef enum {
    STATUS_SUCCESS = 0,
    ERR_STACK_NULL,
    ERR_OUT_OF_MEMORY,
    ERR_STACK_EMPTY,
    ERR_INVALID_INPUT
} StackStatus;

#endif
