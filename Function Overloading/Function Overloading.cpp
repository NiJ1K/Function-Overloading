//#include <iostream>
//
//int findGCD(int a, int b) {
//    if (b == 0) {
//        return a;
//    }
//    else {
//        return findGCD(b, a % b);
//    }
//}
//
//int main() {
//    int num1, num2;
//
//    std::cout << "Enter the first number: ";
//    std::cin >> num1;
//
//    std::cout << "Enter the second number: ";
//    std::cin >> num2;
//
//    int gcd = findGCD(num1, num2);
//
//    std::cout << "Greatest Common Divisor: " << gcd << std::endl;
//
//    return 0;
//}


#include <iostream>

const int MAX_SIZE = 100;

void initializeMatrix(int matrix[][MAX_SIZE], int size) {
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            matrix[i][j] = 0;
}

void initializeMatrix(double matrix[][MAX_SIZE], int size) {
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            matrix[i][j] = 0.0;
}

void initializeMatrix(char matrix[][MAX_SIZE], int size) {
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            matrix[i][j] = ' ';
}

template <typename T>
void printMatrix(const T matrix[][MAX_SIZE], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            std::cout << matrix[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

template <typename T>
T findMaxOnDiagonal(const T matrix[][MAX_SIZE], int size) {
    T maxElement = matrix[0][0];
    for (int i = 1; i < size; ++i) {
        if (matrix[i][i] > maxElement) {
            maxElement = matrix[i][i];
        }
    }
    return maxElement;
}

template <typename T>
T findMinOnDiagonal(const T matrix[][MAX_SIZE], int size) {
    T minElement = matrix[0][0];
    for (int i = 1; i < size; ++i) {
        if (matrix[i][i] < minElement) {
            minElement = matrix[i][i];
        }
    }
    return minElement;
}

template <typename T>
void sortMatrixRows(T matrix[][MAX_SIZE], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size - 1; ++j) {
            for (int k = 0; k < size - j - 1; ++k) {
                if (matrix[i][k] > matrix[i][k + 1]) {
                    T temp = matrix[i][k];
                    matrix[i][k] = matrix[i][k + 1];
                    matrix[i][k + 1] = temp;
                }
            }
        }
    }
}

int main() {
    int intMatrix[MAX_SIZE][MAX_SIZE];
    double doubleMatrix[MAX_SIZE][MAX_SIZE];
    char charMatrix[MAX_SIZE][MAX_SIZE];
    int size;

    std::cout << "Enter matrix size: ";
    std::cin >> size;

    initializeMatrix(intMatrix, size);
    initializeMatrix(doubleMatrix, size);
    initializeMatrix(charMatrix, size);

    printMatrix(intMatrix, size);
    printMatrix(doubleMatrix, size);
    printMatrix(charMatrix, size);

    intMatrix[0][0] = 1;
    intMatrix[1][1] = 2;
    intMatrix[2][2] = 3;
    printMatrix(intMatrix, size);

    int maxInt = findMaxOnDiagonal(intMatrix, size);
    int minInt = findMinOnDiagonal(intMatrix, size);
    std::cout << "Max Element on Diagonal: " << maxInt << std::endl;
    std::cout << "Min Element on Diagonal: " << minInt << std::endl;

    sortMatrixRows(intMatrix, size);
    printMatrix(intMatrix, size);

    return 0;
}



