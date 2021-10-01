function X = dft_matrix(x,N)
W = dftmtx(N);
X = W*x';
end