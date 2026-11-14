/**
 * @file matrix.h
 * @brief Библиотека для работы с матрицами.
 * @author Студент
 * @version 0.1
 */

#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

/**
 * @brief Структура матрицы.
 * Хранит двумерный динамический массив и его размеры.
 * @warning Память освобождается через free_matrix().
 */
struct Matrix {
    double** data; ///< Указатель на двумерный массив.
    int rows;      ///< Количество строк.
    int cols;      ///< Количество столбцов.
};

/**
 * @brief Создание матрицы заданного размера.
 * @param rows Количество строк (> 0).
 * @param cols Количество столбцов (> 0).
 * @return Matrix Инициализированная нулями матрица.
 * @exception std::invalid_argument Если rows <= 0 или cols <= 0.
 */
Matrix create_matrix(int rows, int cols);

/**
 * @brief Освобождение памяти, занятой матрицей.
 * @param m Матрица для освобождения.
 */
void free_matrix(Matrix m);

/**
 * @brief Сложение двух матриц.
 * @param a Первая матрица.
 * @param b Вторая матрица.
 * @return Matrix Результат сложения.
 * @exception std::invalid_argument Если размеры не совпадают.
 */
Matrix matrix_add(Matrix a, Matrix b);

/**
 * @brief Умножение двух матриц.
 * @param a Матрица M×N.
 * @param b Матрица N×K.
 * @return Matrix Результат M×K.
 * @exception std::invalid_argument Если cols(a) != rows(b).
 */
Matrix matrix_multiply(Matrix a, Matrix b);

/**
 * @brief Вывод матрицы в консоль.
 * @param m Матрица для вывода.
 */
void print_matrix(Matrix m);

/**
 * @brief Создание матрицы из одномерного массива.
 * @param data Указатель на массив данных.
 * @param rows Количество строк.
 * @param cols Количество столбцов.
 * @return Matrix Новая матрица.
 */
Matrix matrix_from_array(double* data, int rows, int cols);

/**
 * @brief Заполнение матрицы заданным значением (Вариант 8).
 * @param m Матрица для заполнения.
 * @param value Значение, которым заполняется матрица.
 */
void matrix_fill(Matrix m, double value);

#endif // MATRIX_H