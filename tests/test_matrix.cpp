#include <gtest/gtest.h>
#include "matrix.h"
#include <stdexcept>

// Нормальные случаи
TEST(MatrixTest, CreateMatrix_Normal) {
    Matrix A = create_matrix(3, 4);
    EXPECT_EQ(A.rows, 3);
    EXPECT_EQ(A.cols, 4);
    EXPECT_NE(A.data, nullptr);
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 4; ++j)
            EXPECT_DOUBLE_EQ(A.data[i][j], 0.0);
    free_matrix(A);
}

TEST(MatrixTest, Addition_Normal) {
    Matrix A = create_matrix(2, 2);
    Matrix B = create_matrix(2, 2);
    matrix_fill(A, 1.0);
    matrix_fill(B, 2.0);
    
    Matrix C = matrix_add(A, B);
    EXPECT_DOUBLE_EQ(C.data[0][0], 3.0);
    EXPECT_DOUBLE_EQ(C.data[1][1], 3.0);
    
    free_matrix(A); free_matrix(B); free_matrix(C);
}

TEST(MatrixTest, Multiplication_Normal) {
    double a_data[] = {1, 2, 3, 4};
    double b_data[] = {5, 6, 7, 8};
    Matrix A = matrix_from_array(a_data, 2, 2);
    Matrix B = matrix_from_array(b_data, 2, 2);
    
    Matrix C = matrix_multiply(A, B);
    EXPECT_DOUBLE_EQ(C.data[0][0], 19.0);
    EXPECT_DOUBLE_EQ(C.data[0][1], 22.0);
    EXPECT_DOUBLE_EQ(C.data[1][0], 43.0);
    EXPECT_DOUBLE_EQ(C.data[1][1], 50.0);
    
    free_matrix(A); free_matrix(B); free_matrix(C);
}

// Индивидуальное задание (Вариант 8)
TEST(MatrixTest, FillConstant_Normal) {
    Matrix A = create_matrix(3, 3);
    matrix_fill(A, 9.99);
    for(int i = 0; i < 3; ++i)
        for(int j = 0; j < 3; ++j)
            EXPECT_DOUBLE_EQ(A.data[i][j], 9.99);
    free_matrix(A);
}

// Некорректные случаи
TEST(MatrixTest, CreateMatrix_InvalidSize) {
    EXPECT_THROW(create_matrix(0, 3), std::invalid_argument);
    EXPECT_THROW(create_matrix(3, -1), std::invalid_argument);
}

TEST(MatrixTest, Addition_SizeMismatch) {
    Matrix A = create_matrix(2, 2);
    Matrix B = create_matrix(3, 3);
    EXPECT_THROW(matrix_add(A, B), std::invalid_argument);
    free_matrix(A); free_matrix(B);
}

TEST(MatrixTest, Multiplication_SizeMismatch) {
    Matrix A = create_matrix(2, 3);
    Matrix B = create_matrix(2, 2);
    EXPECT_THROW(matrix_multiply(A, B), std::invalid_argument);
    free_matrix(A); free_matrix(B);
}