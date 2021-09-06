function [rxx, tau] = own_xcorr(x);
    N = length(x);
    tau = -(N-1):(N-1);
    rxx = zeros(1, 2*N-1);
    for ki = 0:N-1
        for n = 1:(N-ki)
            rxx(N+ki) = rxx(N+ki)+x(n+ki)*x(n);
        end
        rxx(N-ki) = rxx(N+ki);
    end
    rxx = rxx/N;
end