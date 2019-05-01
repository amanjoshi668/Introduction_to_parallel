import numpy as np
import scipy.linalg
import copy


def LU(A):
    n = A.shape[0]
    for k in range(n - 1):
        A[k+1:n, k] = A[k+1:n, k]/A[k, k]
        for i in range(k+1, n):
            A[i, k+1: n] = A[i, k+1:n] - A[i, k]*A[k, k+1:n]
    return A

def LU_upper_hessenberg(A):
    n = A.shape[0]
    for k in range(n - 1):
        A[k+1:n, k] = A[k+1:n, k]/A[k, k]
        A[k+1, k+1: n] = A[k+1, k+1:n] - A[k+1, k]*A[k, k+1:n]
    return A

def LU_lower_hessenberg(A):
    n = A.shape[0]
    for k in range(n - 1):
        A[k+1:n, k] = A[k+1:n, k]/A[k, k]
        for i in range(k+1, n):
            A[i, k+1] = A[i, k+1] - A[i, k]*A[k, k+1]
    return A

def forward(L, b):
    n = b.shape[0]
    y = np.zeros((n,1))
    for i in range(n):
        y[i][0] = b[i][0]
        for j in range(i):
            y[i][0] -= L[i][j] * y[j][0]
        # y[j] /= L[i][i]
    return y

def backward(B, y):
    n = y.shape[0]
    x = np.zeros((n,1))
    for i in reversed(range(n)):
        x[i][0] = y[i][0]
        for j in range(i+1, n):
            x[i][0] -= B[i][j] * x[j][0]
        x[i][0] /= B[i][i]
    return x

def solve(A, b):
    A = LU(A)
    y = forward(A, b)
    x = backward(A, y)
    return x

if __name__ == "__main__":
    A = np.random.random((3, 3))*5
    b = np.random.random((3,1))*5
    x = solve(A, b)
    print(A, b, x)