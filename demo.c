#include <stdio.h>

int main() {
    int r, s;
    int testCounter = 0;
    do {
        testCounter++;
        int x = 0;
        int y = 0;
        #pragma omp parallel sections num_threads(2)
        {
            #pragma omp section
            {
                x = 1;
                r = y;
            }

           #pragma omp section
            {
                y = 1;
                s = x;
            }
        }
    } while (r != 0 || s != 0);

    printf("try: %i\n", testCounter);
    printf("r: %i, s: %i\n", r, s);
    return 0;
}
