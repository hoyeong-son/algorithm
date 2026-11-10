#include <stdlib.h>
#include <stdbool.h>

int** subsets(int* nums, int nums_size, int* return_size, int** return_column_sizes) {
        // Total Combinations: 2^n
        *return_size = 1 << nums_size;

        int **results = (int**)malloc(sizeof(int*) * (*return_size));
        *return_column_sizes = (int*)malloc(sizeof(int) * (*return_size));

        for (unsigned int mask = 0; mask < *return_size; mask++) {
                results[mask] = (int*)malloc(sizeof(int) * nums_size);
                int count = 0;

                for (int i = 0; i < nums_size; i++) {
                        if ((mask & (1 << i)) != 0) {
                                results[mask][count++] = nums[i];
                        }
                }

                (*return_column_sizes)[mask] = count;
        }

        return results;
}
