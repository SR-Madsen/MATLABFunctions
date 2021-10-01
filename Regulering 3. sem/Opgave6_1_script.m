close all, clear, clc
%Opgave 6.1 - Igen
%Der �ves dimensionering af serieregultaor med enhedsfeedback.

%F�lgende systemmodel er givet:
Gpnum=3;
Gpden1=[1 1];
Gpden2=[1/2 1];
Gp=tf(Gpnum,Gpden1)*tf(1,Gpden2);

%Dimension�r en PI-regulator, s� systemt for en krydsfrekvens p� 3 rad/s og
%s� fejlen ved et step-input g�r mod nul (type = 1).
%Gc(s) = Kp * (tau*s+1)/(tau*s)

wc = 3;

%Der v�lges en kn�kfrekvens ved en fjerdedel af krydsfrekvensen for at
%minimere p�virkning af fasen

wi = wc/4;
taui = 1/wi

%Forst�rkningen findes ved at finde forst�rkning ved krydsfrekvensen for
%systemet og derfra indstille Kp
[G_wc,P_wc] = bode(Gp,wc)
Kp=1/G_wc

%PI-regulatoren er derfor
Gc = Kp*tf([taui 1],[taui 0])

%�ben-sl�jfesystemet og lukket-sl�jfesystemet:
Go=Gp*Gc
Gl=feedback(Go,1)

step(Gl)