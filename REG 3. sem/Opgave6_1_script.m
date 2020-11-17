close all, clear, clc
%Opgave 6.1 - Igen
%Der øves dimensionering af serieregultaor med enhedsfeedback.

%Følgende systemmodel er givet:
Gpnum=3;
Gpden1=[1 1];
Gpden2=[1/2 1];
Gp=tf(Gpnum,Gpden1)*tf(1,Gpden2);

%Dimensionér en PI-regulator, så systemt for en krydsfrekvens på 3 rad/s og
%så fejlen ved et step-input går mod nul (type = 1).
%Gc(s) = Kp * (tau*s+1)/(tau*s)

wc = 3;

%Der vælges en knækfrekvens ved en fjerdedel af krydsfrekvensen for at
%minimere påvirkning af fasen

wi = wc/4;
taui = 1/wi

%Forstærkningen findes ved at finde forstærkning ved krydsfrekvensen for
%systemet og derfra indstille Kp
[G_wc,P_wc] = bode(Gp,wc)
Kp=1/G_wc

%PI-regulatoren er derfor
Gc = Kp*tf([taui 1],[taui 0])

%Åben-sløjfesystemet og lukket-sløjfesystemet:
Go=Gp*Gc
Gl=feedback(Go,1)

step(Gl)