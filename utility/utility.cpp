#include <iostream>

void fill_arrays_with_random_values(int array_a[], int array_b[], int array_size, int seed = 100) {

    int random_value;
    for(int i = 0; i < array_size; i++) {
        random_value = std::rand() % seed;
        array_a[i] = random_value;
        array_b[i] = random_value;
    }

    std::copy(array_a, array_a + array_size, std::ostream_iterator<int>(std::cout, " "));
    std::printf("\n\n");
}

bool compare_array(int array_a[], int array_b[], int array_size) {

    std::printf("Mine: ");
    std::copy(array_a, array_a + array_size, std::ostream_iterator<int>(std::cout, " "));
    std::printf("\n");

    std::printf("std : ");
    std::copy(array_b, array_b + array_size, std::ostream_iterator<int>(std::cout, " "));
    std::printf("\n\n");

    for (int i = 0; i < array_size; i++) {
        if (array_a[i] != array_b[i]) {
            printf("array_a[%d] = %d != array_b[%d] = %d\n", i, array_a[i], i, array_b[i]);
            printf("Fail!\n");
            return false;
        }
    }

    printf("Success!\n");
    return true;
}

