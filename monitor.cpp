// Giovanni Bruno Travassos de Carvalho - 11506849

#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<thread>
#include<iostream>
#include<barreira.h>

#define THREADS 10
#define MAX_CARACTERES 55000

using namespace std;
 
class Monitor{
   pthread_barreira_t barr;
   FILE* arquivo;

   public:
   Monitor(FILE*);
   void Ler(FILE*);
   void Escrever(FILE*, String);
  };

 Monitor::Monitor(FILE* arquivo) {
 	this->arquivo = arquivo;
 	arquivo = fopen("arquivoLPII.txt", "a");
 }

 void Monitor::Ler(FILE* arquivo){
 	String result;
	this->arquivo = arquivo;
 	fgets(result, MAX_CARACTERES, arquivo);
 	printf("Texto Lido: %s", result);	
 }

void Monitor::Escrever(FILE* arquivo, String texto){
	this->arquivo = arquivo;
	fprintf(arquivo, "%s", texto);
} 

void* monitor(void* parametro){
	long int p = (long int)parametro;
	printf("Iniciando Monitor da Thread=%d.\n",p);
	int i = 0;
	while (i<100000000) i++;

	int rc = c.monitor();

      if(rc != 0 && rc != PTHREAD_BARRIER_SERIAL_THREAD) {
      printf("ERRO\n");
      exit(-1);
    }

	printf("Thread num=%d passou da barreira.\n",p);

	return (void*) p;
}
    
int main (int argc, char **argv) {
	pthread_t t1;
	pthread_t t2;
	pthread_t t3;
	pthread_t t4;
	pthread_t t5;
	pthread_t t6;
	pthread_t t7;
	pthread_t t8;
	pthread_t t9;
	pthread_t t10;

	int rc1, rc2, rc3, rc4, rc5, rc6, rc7, rc8, rc9, rc10;
	int t=0;
	printf("Initializing...\n");

	rc1= pthread_create(&t1,NULL,monitor,(void *)t++);
	rc2= pthread_create(&t2,NULL,monitor,(void *)t++);
	rc3= pthread_create(&t3,NULL,monitor,(void *)t++);
	rc4= pthread_create(&t4,NULL,monitor,(void *)t++);
	rc5= pthread_create(&t5,NULL,monitor,(void *)t++);
	rc6= pthread_create(&t6,NULL,monitor,(void *)t++);
	rc7= pthread_create(&t7,NULL,monitor,(void *)t++);
	rc8= pthread_create(&t8,NULL,monitor,(void *)t++);
	rc9= pthread_create(&t9,NULL,monitor,(void *)t++);
	rc10= pthread_create(&t10,NULL,monitor,(void *)t++);

	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	pthread_join(t3, NULL);
	pthread_join(t4, NULL);
	pthread_join(t5, NULL);
	pthread_join(t6, NULL);
	pthread_join(t7, NULL);
	pthread_join(t8, NULL);
	pthread_join(t9, NULL);
	pthread_join(t10, NULL);

	return 0;
}

int main(){
	thread td[THREADS];
	int i;
	FILE* arquivo; 

	for(i=0; i<THREADS; i++){
		td[i].Ler(arquivo);
		td[i].Escrever(arquivo, "%dº-Thread\n", i);
	}
	
	return 0;
}

