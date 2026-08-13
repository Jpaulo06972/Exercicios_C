#ifndef ERROR_H
#define ERROR_H

typedef enum {
    STATUS_SUCCESS = 0,
    ERR_QUEUE_NULL,
    ERR_OUT_OF_MEMORY,
    ERR_QUEUE_EMPTY,
    ERR_INVALID_INPUT
} QueueStatus;

#endif
