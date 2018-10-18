#include <barreira.h>
#include <pthread.h>
#include <errno.h>

void iniciar_barreira(pthread_barreira_t pbarreira, int count){
	if(count == 0){
        errno = EINVAL;
        return -1;
    }
     if(pthread_mutex_init(barreira->mutex, 0) < 0){
        return -1;
    }
    if(pthread_cond_init(barreira->cond, 0) < 0){
        pthread_mutex_destroy(barreira->mutex);
        return -1;
    }
    barreira->current = count;
    barreira->count = 0;

    return 0;
}

void barreira(pthread_barreira_t pbarreira){
	int i;

	pthread_mutex_lock(&(pbarreira->mutex));

	pbarreira->current++;

	if(pbarreira->current < pbarreira->count){
		pthread_mutex_unlock(&(pbarreira->mutex));
		sem_wait(&(pbarreira->cond));
	}else{
		for(i=0; i < pbarreira->count -1; i++){
			sem_post(&(pbarreira->cond));
		}
		pbarreira->current = 0;
		pthread_mutex_unlock (&(pbarreira->mutex));
	}

}


