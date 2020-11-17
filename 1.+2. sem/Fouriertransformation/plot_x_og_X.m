%Funktion til at plotte x(n) og X(k)
%Der plottes en diskret funktion og den Fourier-transformation
function plot_x_og_X (x,N,fs);
subplot(3,1,1)
n=0:N-1;
plot(n,x)

subplot(3,1,2)
X=(1/N)*fftshift(fft(x,N));
f=((-N/2):(N/2-1))*fs/N;
stem(f,abs(X),'.')

subplot(3,1,3)
nuller=find(0.001>abs(X));
X(nuller)=0;
stem(f,angle(X),'.')
end