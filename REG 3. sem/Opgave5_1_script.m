close all, clear, clc
opengl hardware

%Tegn Bodeplot for åben-sløjfesystemet i figur 5.49.

Gnom=25*[1 1];
Gden1=[1 0];
Gden2=[1 2];
Gden3=[1 2 16];
Gs=tf(Gnom,Gden1)*tf(1,Gden2)*tf(1,Gden3)

Gf = feedback(Gs,1)
bode(Gf)
step(Gf)