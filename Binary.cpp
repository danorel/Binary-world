//
// Created by Dan Orel on 1/20/19.
//

#include "Binary.h"

void Library::show_result(char *number, int size) {
    for(int index = 0; index < size; index++){
        std::cout << number[index];
    }
    std::cout << std::endl;
}

void Library::add_binary_numbers(char *number1, int size1, char *number2, int size2, char *result, int *size) {
    if(size1 == size2) *size = size1 + 1;
    else *size = (size1 > size2) ? size1 : size2;
    int current_digit;
    for(int index = 0; index < *size - 1; index++){
        current_digit = (number1[index] - '0') + (number2[index] - '0');
        if(current_digit == 2) {
            if(static_cast<int>(result[index]) >= 48 && static_cast<int>(result[index]) <= 49) {
                result[index] = static_cast<char>(static_cast<int>(result[index]));
            } else {
                result[index] = static_cast<char>(48);
            }
            result[index + 1] = static_cast<char>(49);
        } else {
            if(static_cast<int>(result[index]) >= 48 && static_cast<int>(result[index]) <= 49){
                result[index] = static_cast<char>(current_digit + static_cast<int>(result[index]));
            } else {
                result[index] = static_cast<char>(current_digit + 48);
            }
            if(static_cast<int>(result[index]) == 2){
                result[index + 1] = static_cast<char>(49);
                result[index] = static_cast<char>(48);
            }
        }
    }
    if(static_cast<int>(result[*size - 1]) != 48 && static_cast<int>(result[*size - 1]) != 49){
        result[*size - 1] = '0';
    }
}

