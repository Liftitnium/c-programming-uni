#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <assert.h>
#include <math.h>
#include <time.h>
// used a struct to pass multiple arguments to threads
typedef struct {
    float *list;
    int start;
    int end;
    double partial_sum;
} ThreadData;

void* thread_compute_average(void* arg) {
    ThreadData* data = (ThreadData*)arg;
    double sum = 0.0;
    for (int i = data->start; i < data->end; i++)
        sum += data->list[i];
    data->partial_sum = sum;
    return NULL;
}
// calculating both averages and comapring them at the end to make sure my parallel code is correct
double compute_average_single(float* list, int size) {
    double sum = 0.0;
    for (int i = 0; i < size; i++)
        sum += list[i];
    return sum / size;
}

double compute_average_parallel(float* list, int size, int n_threads) {
    pthread_t threads[n_threads];
    ThreadData data[n_threads];
    int chunk = size / n_threads;

    for (int i = 0; i < n_threads; i++) {
        data[i].list = list;
        data[i].start = i * chunk;
        data[i].end = (i == n_threads - 1) ? size : (i + 1) * chunk;
        pthread_create(&threads[i], NULL, thread_compute_average, &data[i]);
    }

    double total = 0.0;
    for (int i = 0; i < n_threads; i++) {
        pthread_join(threads[i], NULL);
        total += data[i].partial_sum;
    }

    return total / size;
}

void* thread_generate_random(void* arg) {
    ThreadData* data = (ThreadData*)arg;
    for (int i = data->start; i < data->end; i++)
        data->list[i] = (float)rand() / (float)RAND_MAX;
    return NULL;
}
// edited on the original code in the notes to make it match my style of codeing
float* generate_random_list_parallel(int size, int n_threads) {
    float* list = malloc(size * sizeof(float));
    pthread_t threads[n_threads];
    ThreadData data[n_threads];
    int chunk = size / n_threads;
   
    for (int i = 0; i < n_threads; i++) {
        data[i].list = list;
        data[i].start = i * chunk;
        data[i].end = (i == n_threads - 1) ? size : (i + 1) * chunk;
        pthread_create(&threads[i], NULL, thread_generate_random, &data[i]);
    }

    for (int i = 0; i < n_threads; i++)
        pthread_join(threads[i], NULL);

    return list;
}

int main(void) {
    srand((unsigned)time(NULL));

    int size = 1000000;
    int n_threads = 4;
// You can change n_threads to test with different numbers of threads
    float* list = generate_random_list_parallel(size, n_threads);
    double avg_parallel = compute_average_parallel(list, size, n_threads);
    double avg_single = compute_average_single(list, size);

    printf("Single-threaded: %.6f\n", avg_single);
    printf("Multi-threaded (%d): %.6f\n", n_threads, avg_parallel);
    assert(fabs(avg_parallel - avg_single) < 1e-6);
  
    free(list);
    return 0;
}
