#include <bits/stdc++.h>
using namespace std;
struct CSR
{
    int len;
    vector<int> rows;
    vector<int> cols;
    vector<int> values;
};
typedef vector<int> Row;
typedef vector<Row> Matrix;
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
Matrix multiply(CSR &A, CSR &B)
{
    Matrix result(A.rows.size(), Row(A.rows.size(), 0));
    for (auto i = 0; i < A.rows.size() - 1; i++)
    {
        for (auto j = A.rows[i]; j < A.rows[i + 1]; j++)
        {
            auto rB = A.cols[j];
            if (A.cols[j] > B.rows.size())
                continue;
            for (auto k = B.rows[rB]; k < B.rows[rB + 1]; k++)
            {
                result[i][B.cols[k]] += B.values[k] * A.values[j];
            }
        }
    }
    return result;
}
CSR take_input()
{
    CSR A_CSR;
    // A_CSR.values = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    // A_CSR.cols = {0, 3, 0, 1, 3, 0, 2, 3, 4, 2, 3, 4};
    // A_CSR.rows = {0, 2, 5, 9, 11, 12};
    // return A_CSR;
    cout << "enter no. of non zero elements\n";
    cin >> A_CSR.len;
    cout << "enter non zero values\n";
    for (int i = 0; i < A_CSR.len; i++)
    {
        int x;
        cin >> x;
        A_CSR.values.push_back(x);
    }
    cout << "enter zero index based column indices of above elements\n";
    for (int i = 0; i < A_CSR.len; i++)
    {
        int ind;
        cin >> ind;
        A_CSR.cols.push_back(ind);
    }
    cout << "enter size of row_pointers array i.e. 1 plus no. of rows\n";
    int x;
    cin >> x;
    cout << "enter row pointers\n";
    for (int i = 0; i < x; i++)
    {
        int ind;
        cin >> ind;
        A_CSR.rows.push_back(ind);
    }
    return A_CSR;
}
int main()
{
    cout << "Enter Details of Matrix A" << endl;
    auto A = take_input();
    cout << "Enter Details of Matrix B" << endl;
    auto B = take_input();
    auto C = multiply(A, B);
    cout << "Matrix C = AxB" << endl;
    print_matrix(C);
    return 0;
}