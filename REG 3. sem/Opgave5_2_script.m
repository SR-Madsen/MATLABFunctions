%Opgave 5.10. �ben-sl�jfeoverf�ringsfunktion er givet for et system med
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

%Det bem�rkes, at gainmargin er -11,6 dB. Da den i opgave b skal v�re 5 dB,
%skal den �ndres med 5-(-11,6) = 16,6 dB = 6,76.
K=10/6.76;

Gnum=[K];
Gden1=[1/4 1];
Gden2=[1/4 2/5 1];

Gs = tf(Gnum,Gden1)*tf(1,Gden2)
margin(Gs)

%Fasemargin afl�ses til 23,7 grader. Denne skal i opgave c v�re 45 grader.
%Det sted, der resulterer i -135 grader p� grafen, afl�ses, og forst�rkning
%justeres. Forst�rkningen afl�ses til 2.86 dB = 1.39

K=10/6.76/1.39;

Gnum=[K];
Gden1=[1/4 1];
Gden2=[1/4 2/5 1];

Gs = tf(Gnum,Gden1)*tf(1,Gden2)
margin(Gs)

%Dette resulterer i den korrekte fasemargin. Gainmargin er her 7,89 dB.
