#include <bits/stdc++.h>
using namespace std;

typedef vector<int> Row;
typedef vector<Row> Matrix;
Matrix matrix_multiply(Matrix &A, Matrix &B)
{
    Matrix C(A.size(), Row(B[0].size(), 0));
    for (auto i = 0; i < A.size(); i++)
    {
        for (auto j = 0; j < B[0].size(); j++)
        {
            for (auto k = 0; k < B.size(); k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}
Matrix generate_random_matrix(int m, int n)
{
    Matrix A(m, Row(n));
    for (auto i = 0; i < m; i++)
    {
        for (auto j = 0; j < n; j++)
        {
            A[i][j] = rand() % 1000;
        }
    }
    return A;
}
void print_matrix(Matrix &A)
{
    for (auto i = 0; i < A.size(); i++)
    {
        for (auto j = 0; j < A[0].size(); j++)
        {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    return;
}
int main()
{
    cout << "Enter number of rows and columns in Matrix A:" << endl;
    int m, n;
    cin >> m >> n;
    Matrix A = generate_random_matrix(m, n);
    cout << "Enter diensions of matrix B:" << endl;
    cin >> m >> n;
    Matrix B = generate_random_matrix(m, n);
    cout << "Matrix A:" << endl;
    print_matrix(A);
    cout << "Matrix B:" << endl;
    print_matrix(B);
    cout << "Multiplied matrix C = A x B is:" << endl;
    auto C = matrix_multiply(A, B);
    print_matrix(C);
    return 0;
}