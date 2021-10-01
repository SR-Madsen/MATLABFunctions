clear
close all
clc

syms t %plot af C
rx=cos(t); %x-delen af vektoren
ry=sin(t); %y-delen af vektoren
rz=t; %z-delen af vektoren
tint=[0 2*pi]; %interval

fplot3(rx,ry,rz)
hold on

%plot af F

[x,y,z] = meshgrid([-1:1:1],[-1:1:1],[-1:1:1]);

u=(y-1).*z; %x-delen af feltet
v=x.*z; %y-delen af feltet
w=x.*(y-1); %z-delen af feltet

quiver3(x,y,z,u,v,w)