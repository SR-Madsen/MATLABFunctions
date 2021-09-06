function autocorrplot(x, option)
    subplot(2,1,1)
    n = 0:length(x)-1;
    stem(n, x, '.')
    subplot(2,1,2)
    [rxx, tau] = xcorr(x, option);
    stem(tau, rxx, '.')
end