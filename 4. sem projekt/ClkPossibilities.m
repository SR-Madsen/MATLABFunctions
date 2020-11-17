clear
close all
clc

format shorteng


fileID = fopen('ClkPossibs.txt','w')

for n = 1:255
    if (mod(n,2) == 0)
        for i = 1:255
            Clk = (16*10^6)/(n*(i+1));
            fprintf(fileID,'n: %d, i: %d, Clk: %d\n',n,i,Clk);
        end
    end
end

fclose(fileID);
n
i