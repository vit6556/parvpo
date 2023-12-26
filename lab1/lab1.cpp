#include <stdio.h>
#include <stdlib.h>
#include <omp.h>


int main(int argc, char** argv) {
    const int count = 2000000000;
    const int threads = 20;
    const int random_seed = 920215;
    const int iterations = 100;
    double start_time, end_time, total;
    int* array = 0;
    int  max = -1;

    srand(random_seed);

    array = (int*)malloc(count*sizeof(int));
    for (int i = 0; i < count; ++i) { 
        array[i] = rand();
    }

    start_time = omp_get_wtime();
    for (int j = 0; j < iterations; ++j) {
        #pragma omp parallel num_threads(threads) shared(array, count) reduction(max: max) default(none)
        {
            #pragma omp for
            for(int i = 0; i < count; ++i) {
                if(array[i] > max) { max = array[i]; };
            }
        }
    }
    end_time = omp_get_wtime();
    printf("Work time: %f\n", end_time - start_time);

    free(array);

    return(0);
}
