# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
void* task(void* arg){
// Simulate a task that takes some time
// Takes about 2 seconds on my machine
for (volatile long i = 0; i < 2000000000L; i++);
return NULL;
}
int main(){
const int num_threads = 12;
pthread_t threads[num_threads];
time_t start_time = time(NULL);
// Launch all threads
for(int i = 0; i < num_threads; i++){
pthread_create(&threads[i], NULL, task, NULL);
}
// Wait for all threads to finish
for(int i = 0; i < num_threads; i++){
pthread_join(threads[i], NULL);
}
time_t end_time = time(NULL);
printf("Total time taken for %d threads: %ld seconds\n", num_threads, end_time - start_time);
return 0;
}