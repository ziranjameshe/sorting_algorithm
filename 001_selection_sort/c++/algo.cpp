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

void selection_sort(int array_to_sort[], int array_size) {

    int min_value_index;

    for (int i = 0; i < array_size - 1; i++) {

        min_value_index = i;

        for (int j = i; j < array_size; j++) {
            if (array_to_sort[j] < array_to_sort[min_value_index]) {
                min_value_index = j;
            }
        }

        std::swap(array_to_sort[i], array_to_sort[min_value_index]);

    }
}

int main() {

    const int array_size                  = 1000000;
    // int array_to_sort_mine[array_size]     = {25, 64, 333, 12, 22, 11};
    // int array_to_sort_official[array_size] = {25, 64, 333, 12, 22, 11};

    int array_to_sort_mine[array_size];
    int array_to_sort_official[array_size];

    int random_value = 0;
    for(int i = 0; i < array_size; i++) {
        random_value = std::rand() % 100;
        array_to_sort_mine[i]     = random_value;
        array_to_sort_official[i] = random_value;
    }

    std::copy(array_to_sort_mine, array_to_sort_mine + array_size, std::ostream_iterator<int>(std::cout, " "));
    std::printf("\n\n");

    selection_sort(array_to_sort_mine, array_size);
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
