#include <unistd.h>
#include <stdlib.h>
#include <omp.h>
#include <stdio.h>
#define THREADS 10
#define N 100000000
int main()
{
    int i;
    printf("Running %d iterations on %d threads statically.\n", N, THREADS);
#pragma omp parallel for schedule(static) num_threads(THREADS)
    for (i = 0; i < N; i++)
    {
        /* a loop that doesn’t take very long */
    }
    /* all threads done */
    printf("All done!\n");
    return 0;
}