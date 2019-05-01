import numpy as np


def house(x):
    v = x/(x[0] + np.copysign(np.linalg.norm(x), x[0]))
    v[0] = 1
    return v

def make_householder(a):
    H = np.identity(a.shape[0])
    v = house(a)
    norm = np.dot(v,v)
    B = np.dot(v[:, None], v[None, :])
    B = (2/norm) * B
    H -= B 
    return H

def backward(B, y):
    n = y.shape[0]
    x = np.zeros((n,1))
    for i in reversed(range(n)):
        x[i][0] = y[i][0]
        for j in range(i+1, n):
            x[i][0] -= B[i][j] * x[j][0]
        x[i][0] /= B[i][i]
    return x

def myqr(A):
    m, n = A.shape
    Q = np.eye(m)
    for i in range(n - (m == n)):
        H = np.identity(m)
        H[i:, i:] = make_householder(A[i:, i])
        A = np.dot(H, A)
        Q = np.dot(Q, H)
    return Q, A

def myqr_hessenberg(A):
    m, n = A.shape
    Q = np.identity(m)
    for i in range(n - (m == n)):
        H = np.identity(m)
        H[i:, i:] = make_householder_hessenberg(A[i:, i])
        A = np.dot(H, A)
        Q = np.dot(Q, H)
    return Q, A

def make_householder_hessenberg(a):
    H = np.eye(a.shape[0])
    v=house(a[0:2])
    norm = np.dot(v,v)
    B = np.dot(v[:, None], v[None, :])
    B = (2/norm) * B
    H[0:2, 0:2] -= B 
    return H

def solve(A, b):
    Q, R = myqr(A)
    b = np.dot(Q.T, b)
    x = backward(R, b)
    return x