function cpsdplot(x, y, option, fs);
    subplot(5,1,1)
    N = length(x);
    n = 0:N-1;
    stem(n, x, '.')
    subplot(5,1,2)
    stem(n, y, '.')
    subplot(5,1,3)
    [Rxy, tau] = xcorr(x, y, option);
    stem(tau, Rxy, '.')
    subplot(5,1,4)
    [Pxy, f] = freqz(Rxy, 1, 1024, fs);
    Pxy = Pxy.*exp(i*(2*pi/fs)*f*(N-1));
    plot(f, 10*log10(abs(Pxy)))
    subplot(5,1,5)
    plot(f, unwrap(angle(Pxy)))
end