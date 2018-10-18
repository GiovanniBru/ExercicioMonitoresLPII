#ifndef BARRIER_H_
#define BARRIER_H_
#include <pthread.h>
#include <errno.h>

//typedef int barreirattr_t;

typedef struct{
    pthread_mutex_t mutex;
    pthread_cond_t cond;
    int count;
    int current;
} pthread_barreira_t;

void iniciar_barreira(pthread_barreira_t, int);
void barreira(pthread_barreira_t);

