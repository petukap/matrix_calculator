#include "matrix.h"
#include <iostream>

int main() {
    try {
        Matrix A = create_matrix(2, 2);
        Matrix B = create_matrix(2, 2);

        // Вариант 8
        matrix_fill(A, 3.0);
        matrix_fill(B, 4.0);

        std::cout << "Matrix A:" << std::endl;
        print_matrix(A);
        
        std::cout << "Matrix B:" << std::endl;
        print_matrix(B);

        Matrix sum = matrix_add(A, B);
        std::cout << "Sum A + B:" << std::endl;
        print_matrix(sum);

        Matrix product = matrix_multiply(A, B);
        std::cout << "Product A * B:" << std::endl;
        print_matrix(product);

        free_matrix(A);
        free_matrix(B);
        free_matrix(sum);
        free_matrix(product);

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}