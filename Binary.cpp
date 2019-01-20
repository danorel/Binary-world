//
// Created by Dan Orel on 1/20/19.
//

#include "Binary.h"

// Output the binary number on the screen
void Library::show_result(char *binary_number, int size) {
    for(int index = 0; index < size; index++){
        std::cout << binary_number[index];
    }
    std::cout << std::endl;
}

void Library::add_binary_numbers(char *binary_number1, int first_size, char *binary_number2, int second_size, char *result, int *result_size) {
    if(first_size == second_size){
        reverse_binary(binary_number1, first_size);
        reverse_binary(binary_number2, second_size);
        int current_digit;
        for(int index = 0; index < *result_size - 1; index++){
            current_digit = (binary_number1[index] - '0') + (binary_number2[index] - '0');
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
        if(static_cast<int>(result[*result_size - 1]) != 48 && static_cast<int>(result[*result_size - 1]) != 49){
            reverse_binary(result, *result_size - 1);
            result[*result_size - 1] = '0';
        } else {
            reverse_binary(result, *result_size);
        }
    }
}

// Reversing the binary number in normal view
void Library::reverse_binary(char *binary_number, int size) {
    char *temporary_number = new char[size];
    for(int start_index = 0, end_index = size - 1; start_index != size; start_index++, end_index--){
        temporary_number[start_index] = binary_number[end_index];
    }
    for(int start_index = 0; start_index != size; start_index++){
        binary_number[start_index] = temporary_number[start_index];
    }
}


