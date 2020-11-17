function [R] = ANOVAResiduals(M)
    M = M';
    SZ = size(M);
    R = zeros(SZ);
    ydd = mean(M, 'all');
    for i = 1:SZ(1)
        yid = mean(M(i,:));
        for j = 1:SZ(2)
            ydj = mean(M(:,j));
            R(i,j) = M(i,j) - yid - ydj + ydd;
        end
    end
    R = R';
end

