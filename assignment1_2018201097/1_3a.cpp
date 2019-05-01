#include <bits/stdc++.h>
using namespace std;
typedef vector<int> Row;
typedef vector<Row> Matrix;
struct entry
{
    entry(int r, int c, int v)
    {
        this->row = r;
        this->col = c;
        this->val = v;
    }
    void print()
    {
        cout << "Row: " << this->row << "\t"
             << "Column: " << this->col << "\t"
             << "Value: " << this->val << endl;
    }
    int row, col, val;
};
bool cmp_row(entry &A, entry &B)
{
    if (A.row == B.row)
        return A.col < B.col;
    return A.row < B.row;
}
bool cmp_col(entry &A, entry &B)
{
    if (A.col == B.col)
        return A.row < B.row;
    return A.col < B.col;
}
struct COO
{
    vector<entry> info;
    COO()
    {
    }
    COO(vector<int> &row, vector<int> &col, vector<int> &values)
    {
        for (auto i = 0; i < row.size(); i++)
        {
            this->info.push_back(entry(row[i], col[i], values[i]));
        }
    }
    void sort_rows()
    {
        sort(this->info.begin(), this->info.end(), cmp_row);
    }
    void sort_cols()
    {
        sort(this->info.begin(), this->info.end(), cmp_col);
    }
    void add_entry(int r, int c, int v)
    {
        this->info.push_back(entry(r, c, v));
    }
    void print()
    {
        for (auto i = 0; i < this->info.size(); i++)
            info[i].print();
    }
};
COO multiply(COO A, COO B)
{
    A.sort_rows();
    B.sort_cols();
    COO result;
    for (auto i = 0; i < A.info.size();)
    {
        auto row = A.info[i].row;
        for (auto j = 0; j < B.info.size();)
        {
            int col = B.info[j].col;
            int cur_i = i;
            int cur_j = j;
            auto sum = 0;

            while (cur_i < A.info.size() && A.info[cur_i].row == row && cur_j < B.info.size() && B.info[cur_j].col == col)
            {

                if (A.info[cur_i].col < B.info[cur_j].row)
                    cur_i++;

                else if (A.info[cur_i].col > B.info[cur_j].row)
                    cur_j++;
                else
                    sum += A.info[cur_i++].val * B.info[cur_j++].val;
            }

            if (sum)
                result.add_entry(row, col, sum);

            while (j < B.info.size() && B.info[j].col == col)
                j++;
        }

        while (i < A.info.size() && A.info[i].row == row)
            i++;
    }
    return result;
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
int main()
{
    auto M = generate_random_matrix(3, 5);
    auto N = generate_random_matrix(3, 5);
    auto A = COO(M[0], M[1], M[2]);
    auto B = COO(N[0], N[1], N[2]);
    auto C = multiply(A, B);
    cout << "Matrix A: " << endl;
    A.print();
    cout << "Matrix B: " << endl;
    B.print();
    cout << "Matrix C = AxB: " << endl;
    C.print();
    return 0;
}