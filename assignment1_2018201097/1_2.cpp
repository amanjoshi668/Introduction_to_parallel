#include<bits/stdc++.h>
using namespace std;
typedef vector<int> Row;
typedef vector<Row> Matrix;
Matrix matrix_multiply_banded(Matrix &A, Matrix &B, int pA, int qA, int pB, int qB, int n)
{
    Matrix C(A.size(), Row(B[0].size(), 0));
    for (auto i = 0; i < n; i++)
    {
        for (auto j = 0; j < n; j++)
        {
            auto k_start = max(max(0, i-pA), max(0, j-qB));
            auto k_end = min(min(i+qA, n-1), min(j+pB, n-1));
            for (auto k = k_start; k <= k_end; k++)
            {
                auto xA = i-k+qA<n?i -k +qA:0;
                auto xB = k-j+qB<n?k-j+qB:0;
                C[i][j] += A[xA][k] * B[xB][j];
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
int main(){
    cout << "Enter number of rows and columns in Matrix A:" << endl;
    int n;
    cout << "enter row size of square matrices\n";
    cin >> n;
    cout << "enter p and q i.e. lower bandwidth and upper bandwidth of first matrix\n";
    int pA, qA;
    cin >> pA >> qA;
    int row_A_band = pA + qA + 1;
    int col_A_band = n;
    Matrix A_band(row_A_band, Row(col_A_band));
    cout << "Enter banded matrix\n";
    for (int i = 0; i < row_A_band; i++)
    {
        for (int j = 0; j < col_A_band; j++)
        {
            cin >> A_band[i][j];
        }
    }
    //A_band={{0,4,1,4},{1,4,3,3},{3,2,1,0}};

    cout << "enter p and q i.e. lower bandwidth and upper bandwidth of second matrix\n";
    int pB, qB;
    cin >> pB >> qB;
    int row_B_band = pB + qB + 1;
    int col_B_band=n;
    Matrix B_band(row_B_band, Row(col_B_band));
    cout << "Enter banded matrix\n";
    for (int i = 0; i < row_B_band; i++)
    {
        for (int j = 0; j < col_B_band; j++)
        {
            cin >> B_band[i][j];
        }
    }
    auto C = matrix_multiply_banded(A_band, B_band, pA, qA, pB, qB, n);
    print_matrix(C);
    return 0;
}