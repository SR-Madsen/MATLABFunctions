%Opgave 5.10. Åben-sløjfeoverføringsfunktion er givet for et system med
%enhedstilbagekobling.

close all, clear, clc;
opengl hardware;

%Funktionen ved K = 10
K = 10;

Gnum=[K];
Gden1=[1/4 1];
Gden2=[1/4 2/5 1];

Gs = tf(Gnum,Gden1)*tf(1,Gden2)
margin(Gs)

%Det bemærkes, at gainmargin er -11,6 dB. Da den i opgave b skal være 5 dB,
%skal den ændres med 5-(-11,6) = 16,6 dB = 6,76.
K=10/6.76;

Gnum=[K];
Gden1=[1/4 1];
Gden2=[1/4 2/5 1];

Gs = tf(Gnum,Gden1)*tf(1,Gden2)
margin(Gs)

%Fasemargin aflæses til 23,7 grader. Denne skal i opgave c være 45 grader.
%Det sted, der resulterer i -135 grader på grafen, aflæses, og forstærkning
%justeres. Forstærkningen aflæses til 2.86 dB = 1.39

K=10/6.76/1.39;

Gnum=[K];
Gden1=[1/4 1];
Gden2=[1/4 2/5 1];

Gs = tf(Gnum,Gden1)*tf(1,Gden2)
margin(Gs)

%Dette resulterer i den korrekte fasemargin. Gainmargin er her 7,89 dB.
