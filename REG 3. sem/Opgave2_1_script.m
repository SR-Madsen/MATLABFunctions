clear
close all
clc

m=1000;
b=50;
F1=500;

%Ligev�gt
F10=F1
v0=sqrt(F10/b)

%Linearisering omkring ligev�gtspunktet
[num, den] = linmod('Opgave2_1',F10,v0)

%Overf�ringsfunktionen
g = tf(num, den)