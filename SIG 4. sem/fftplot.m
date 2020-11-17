function fftplot(x,N,fs);
subplot(2,1,1)
n = 0:N-1;
stem(n,x,'.')
subplot(2,1,2)
X=fft(x,N);
f=(0:N-1)*fs/N;
stem(f,abs(X),'.')
end