function psdplot(x, option, fs);
    subplot(3,1,1)
    N = length(x);
    n = 0:N-1;
    stem(n, x, '.')
    subplot(3,1,2)
    [Rxx, tau] = xcorr(x, option);
    stem(tau, Rxx, '.')
    subplot(3,1,3)
    [Pxx, f] = freqz(Rxx, 1, 1024, fs);
    Pxx = Pxx.*exp(i*(2*pi/fs)*f*(N-1));
    plot(f, 10*log10(abs(Pxx)))
end