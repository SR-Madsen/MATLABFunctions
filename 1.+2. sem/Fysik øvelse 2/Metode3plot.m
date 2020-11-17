clear, close all, clc
opengl hardware

xlsread("metode3.xlsx")

n=ans(:,1);
T=ans(:,2);

plot(n,T)

w=(2*pi)./T

plot(n,w)
title('Vinkelhastighed per periode')
xlabel('Periodenummer')
ylabel('Vinkelhastighed')