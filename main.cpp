#include "Binary.h"

int main() {
    srand(time(NULL));

    Library library;
    char *binary_number1 = new char[5];
    char *binary_number2 = new char[5];
    char *binary_result = new char[6];
    int size;
    int *result_size = &size;

    // 48 stands for 0 in ASCII
    // 49 stands for 1 in ASCII
    for(int counter = 0; counter < 5; counter++){
        binary_number1[counter] += 48 + round(rand() % (50 - 48));
        binary_number2[counter] += 48 + round(rand() % (50 - 48));
    }
    library.show_result(binary_number1, 5);
    library.show_result(binary_number2, 5);

    library.add_binary_numbers(binary_number1, 5, binary_number2, 5, binary_result, result_size);
    library.show_result(binary_result, *result_size);


    return 0;
}