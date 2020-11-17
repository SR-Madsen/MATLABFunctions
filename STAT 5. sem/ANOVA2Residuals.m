function [R,VR,CM] = ANOVA2Residuals(M,n)
sz = size(M);
a = sz(1)/n;
b = sz(2);

cellmeans = zeros(a,b);
for i = 1:a
    rows = [1 + (i-1)*n; n + (i-1)*n];
    for j = 1:b
        cellmeans(i,j) = mean(M(rows(1):rows(2),j));
    end
end
R = zeros(sz);
VR = zeros(1,0);
for it = 1:n*a
    i = ceil(it/n);
    for j = 1:b
        R(it,j) = M(it,j) - cellmeans(i,j);
        VR = [VR R(it,j)];
    end
end
CM = cellmeans;
end