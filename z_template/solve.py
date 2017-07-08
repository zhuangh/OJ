import numpy as np
a = np.array([[3,1], [1,2]])
b = np.array([9,8])
x = np.linalg.solve(a, b)
print(x) 


from scipy.sparse.linalg import gmres
from scipy.sparse import csc_matrix
# create some matrices
M = csc_matrix(np.random.rand(5, 5))
print(M)
b = np.random.rand(5, 1)
print(b)
x = gmres(M, b)
print(x)
