#include "Binary.h"

int main() {
    srand(time(NULL));

    // Class object & numbers sizes declaration
    Library library;
    int first_size, second_size, result_size;

    // Input numbers sizes
    std::cout << "Enter the size of the first number: ";
    std::cin >> first_size;
    std::cout << "Enter the size of the second number: ";
    std::cin >> second_size;

    if(first_size == second_size) result_size = first_size + 1;
    else result_size = (first_size > second_size) ? first_size : second_size;

    // Binary numbers declaration
    char *binary_number1 = new char[first_size];
    char *binary_number2 = new char[second_size];
    char *binary_result = new char[result_size];
    int *result_size_ptr = &result_size;

//     48 stands for 0 in ASCII
//     49 stands for 1 in ASCII

    // Randomly creating the binary first number
    for(int counter = 0; counter < first_size; counter++){
        binary_number1[counter] += 48 + round(rand() % 2);
    }

    // Randomly creating the binary second number
    for(int counter = 0; counter < second_size; counter++){
        binary_number2[counter] += 48 + round(rand() % 2);
    }

    // Visualising the numbers on the screen
    library.show_result(binary_number1, first_size);
    library.show_result(binary_number2, second_size);

    // Adding two binary numbers
    library.add_binary_numbers(binary_number1, first_size, binary_number2, second_size, binary_result, result_size_ptr);
    // Showing the result of their summary
    library.show_result(binary_result, *result_size_ptr);

    return 0;
}