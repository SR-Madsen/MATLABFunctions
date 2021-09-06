function crosscorrplot(x, y, option);
    subplot(3,1,1)
    nx = 0:length(x)-1;
    stem(nx, x, '.')
    subplot(3,1,2)
    ny = 0:length(y)-1;
    stem(ny, y, '.')
    subplot(3,1,3)
    [rxy, tau] = xcorr(x, y, option);
    stem(tau, rxy, '.')
end