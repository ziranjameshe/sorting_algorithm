// Selection Sort

#include <iostream>
#include <stdio.h>

bool compare_array(int array_a[], int array_b[], int array_size) {
    for (int i = 0; i < array_size; i++) {
        if (array_a[i] != array_b[i]) {
            printf("array_a[%d] = %d != array_b[%d] = %d\n", i, array_a[i], i, array_b[i]);
            return false;
        }
    }
    return true;
}

void insertion_sort(int array_to_sort[], int array_size) {

    int j;

    for (int i = 1; i < array_size; i++) {

        for (j = i; j > 0; j--) {

            if (array_to_sort[j - 1] > array_to_sort[j]) {

                std::swap(array_to_sort[j - 1], array_to_sort[j]);

            } else {

                break;
            }
        }
    }
}

int main() {

    const int array_size                   = 10;
    // int array_to_sort_mine[array_size]     = {25, 64, 333, 12, 22, 11};
    // int array_to_sort_official[array_size] = {25, 64, 333, 12, 22, 11};

    int array_to_sort_mine[array_size];
    int array_to_sort_official[array_size];

    int random_value = 0;
    for(int i = 0; i < array_size; i++) {
        random_value = std::rand() % 123;
        array_to_sort_mine[i]     = random_value;
        array_to_sort_official[i] = random_value;
    }

    std::copy(array_to_sort_mine, array_to_sort_mine + array_size, std::ostream_iterator<int>(std::cout, " "));
    std::printf("\n\n");

    insertion_sort(array_to_sort_mine, array_size);
    std::sort(array_to_sort_official, array_to_sort_official + array_size);

    std::printf("Mine: ");
    std::copy(array_to_sort_mine, array_to_sort_mine + array_size, std::ostream_iterator<int>(std::cout, " "));
    std::printf("\n");

    std::printf("std : ");
    std::copy(array_to_sort_official, array_to_sort_official + array_size, std::ostream_iterator<int>(std::cout, " "));
    std::printf("\n\n");

    if (compare_array(array_to_sort_mine, array_to_sort_official, array_size) == true) {
        printf("Success!\n");
    } else {
        printf("Fail!\n");
    }
}
