#include <iostream>
#include <vector>
using namespace std;

class IntMatrix {
public:
    IntMatrix(IntMatrix& intMatrix) = default;
    explicit IntMatrix(unsigned int n);
    bool voidMatrix();
    IntMatrix transMatrix(unsigned int rowFrom, unsigned int rowTo, int pow);
    IntMatrix exMatrix(unsigned int rowFrom, unsigned int rowTo);
    friend istream & operator>>(istream& is, IntMatrix& Matrix);
    friend ostream & operator<<(ostream& os, IntMatrix& Matrix);
    friend IntMatrix operator+(const IntMatrix& Matrix1, const IntMatrix& Matrix2);
    friend IntMatrix operator-(const IntMatrix& Matrix1, const IntMatrix& Matrix2);
    friend IntMatrix operator*(const IntMatrix& Matrix1, const IntMatrix& Matrix2);
    IntMatrix & operator=(const IntMatrix& Matrix1);
private:
    vector<vector<int>> matrix;
    unsigned int size;
};

IntMatrix::IntMatrix(unsigned int n) : size(n) {
    vector row = vector<int>(n, 0);
    for(int i = 0; i < size; i++) {
        if(i > 0) {
            row[i - 1] = 0;
        }
        row[i] = 1;
        matrix.push_back(row);
    }
}

bool IntMatrix::voidMatrix() {
    for(auto& row : matrix) {
        fill(row.begin(), row.end(), 0);
    }
    return true;
}

IntMatrix IntMatrix::transMatrix(unsigned int rowFrom, unsigned int rowTo, int pow) {
    if(size <= rowFrom || size <= rowTo) {
        cout << "错误的矩阵操作！" << endl;
        return *this;
    } else {
        for(int i = 0; i < size; i++) {
            matrix[rowTo - 1][i] += matrix[rowFrom - 1][i] * pow;
        }
        return *this;
    }
}

IntMatrix IntMatrix::exMatrix(unsigned int rowFrom, unsigned int rowTo) {
    if(size <= rowFrom || size <= rowTo) {
        cout << "错误的矩阵操作！" << endl;
        return *this;
    } else {
        swap(matrix[rowTo - 1], (matrix[rowFrom - 1]));
        return *this;
    }
}

istream & operator>>(istream& is, IntMatrix& Matrix) {
    unsigned int size;
    cout << "请先输入矩阵规模: ";
    is >> size;
    Matrix.size = size;

    Matrix.matrix.resize(size, vector<int>(size, 0));
    cout << "请输入矩阵: " << endl;
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++){
            is >> Matrix.matrix[i][j];
        }
    }
    return is;
}

ostream & operator<<(ostream& os, IntMatrix& Matrix) {
    unsigned int size = Matrix.size;
    cout << "这是一个规模为" << size << "x" << size << "的矩阵" << endl;
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            os << Matrix.matrix[i][j] << " ";
        }
        os << endl;
    }
    return os;
}

IntMatrix operator+(const IntMatrix& Matrix1, const IntMatrix& Matrix2) {
    if(Matrix1.size != Matrix2.size) {
        cout << "矩阵规模不同，无法相加！" << endl;
        return IntMatrix(0);
    } else {
        unsigned size = Matrix1.size;
        IntMatrix result = IntMatrix(size);

        #pragma omp parallel for // 多线程 for 循环
        for(int i = 0; i < size; i++) {
            for(int j = 0; j < size; j++){
                result.matrix[i][j] = Matrix1.matrix[i][j] + Matrix2.matrix[i][j];
            }
        }
        return result;
    }
}

IntMatrix operator-(const IntMatrix& Matrix1, const IntMatrix& Matrix2) {
    if(Matrix1.size != Matrix2.size) {
        cout << "矩阵规模不同，无法相减！" << endl;
        return IntMatrix(0);
    } else {
        unsigned size = Matrix1.size;
        IntMatrix result = IntMatrix(size);

        #pragma omp parallel for // 多线程 for 循环
        for(int i = 0; i < size; i++) {
            for(int j = 0; j < size; j++){
                result.matrix[i][j] = Matrix1.matrix[i][j] - Matrix2.matrix[i][j];
            }
        }
        return result;
    }
}

IntMatrix operator*(const IntMatrix& Matrix1, const IntMatrix& Matrix2) {
    if(Matrix1.size != Matrix2.size) {
        cout << "矩阵规模不同，无法相乘！" << endl;
        return IntMatrix(0);
    } else {
        unsigned size = Matrix1.size;
        IntMatrix result = IntMatrix(size);
        int temp = 0;

        #pragma omp parallel for // 多线程 for 循环
        for(int i = 0; i < size; i++) {
            for(int j = 0; j < size; j++){
                for(int k = 0; k < size; k++){
                    temp += Matrix1.matrix[i][k] * Matrix2.matrix[k][j];
                }
                result.matrix[i][j] = temp;
                temp = 0;
            }
        }
        return result;
    }
}

IntMatrix & IntMatrix::operator=(const IntMatrix& Matrix1) {
    if(this != &Matrix1) {
        this->matrix = Matrix1.matrix;
        this->size = Matrix1.size;
    }
    return *this;
}

int main(){
    system("chcp 65001");
    IntMatrix matrix1 = IntMatrix(5);
    cout << matrix1;
    cin >> matrix1;
    cout << matrix1;
    IntMatrix matrix2 = IntMatrix(5);
    IntMatrix matrix3 = matrix1 + matrix2;
    IntMatrix matrix4 = matrix1 - matrix2;
    IntMatrix matrix5 = matrix2.transMatrix(2, 3, 1);
    IntMatrix matrix6 = matrix2.exMatrix(2, 3);
    IntMatrix matrix7 = IntMatrix(3);
    IntMatrix matrix8 = IntMatrix(5) * IntMatrix(5);
    matrix7 = matrix2;
    cout << matrix2 << matrix3 << matrix4 << matrix5 << matrix6 << matrix7 << matrix8;
    return EXIT_SUCCESS;
}