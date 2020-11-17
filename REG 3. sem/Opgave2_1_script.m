clear
close all
clc

m=1000;
b=50;
F1=500;

%Ligevægt
F10=F1
v0=sqrt(F10/b)

%Linearisering omkring ligevægtspunktet
[num, den] = linmod('Opgave2_1',F10,v0)

%Overføringsfunktionen
g = tf(num, den)