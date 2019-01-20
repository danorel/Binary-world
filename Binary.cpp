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
    reverse_binary(number1, size1);
    reverse_binary(number2, size2);
    if(size1 == size2) *size = size1 + 1;
    else *size = (size1 > size2) ? size1 : size2;
    int current_digit;
    for(int index = 0; index < *size - 1; index++){
        current_digit = (number1[index] - '0') + (number2[index] - '0');
        if(static_cast<int>(result[index] >= 48) && static_cast<int>(result[index] <= 49)){
            if(current_digit == 2){
                result[index + 1] = static_cast<char>(49);
            } else {
                current_digit += static_cast<int>(result[index]) - 48;
                if(current_digit == 2){
                    result[index] = static_cast<char>(48);
                    result[index + 1] = static_cast<char>(49);
                } else {
                    result[index] = static_cast<char>(48 + current_digit);
                }
            }
        } else {
            if(current_digit == 2){
                result[index] = static_cast<char>(48);
                result[index + 1] = static_cast<char>(49);
            } else {
                result[index] = static_cast<char>(48 + current_digit);
            }
        }
    }
    if(static_cast<int>(result[*size - 1]) != 48 && static_cast<int>(result[*size - 1]) != 49){
        reverse_binary(result, *size - 1);
        result[*size - 1] = '0';
    } else {
        reverse_binary(result, *size);
    }
}

void Library::reverse_binary(char *binary_number, int size) {
    char *temporary_number = new char[size];
    for(int start_index = 0, end_index = size - 1; start_index != size - 1; start_index++, end_index--){
        temporary_number[start_index] = binary_number[end_index];
    }
    for(int start_index = 0; start_index != size - 1; start_index++){
        binary_number[start_index] = temporary_number[start_index];
    }
}


