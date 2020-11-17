close all, clear, clc
%Opgave 6.2 - Igen
%Serieregulator. Systemmodel er givet ved:
Gpnum=3;
Gpden1=[1 1];
Gpden2=[1/2 1];
Gp=tf(Gpnum,Gpden1)*tf(1,Gpden2);

%Controller er en lag-kompensator:
%Gc(s) = Kp*(tau*s+1)/(beta*tau*s+1)

%Bestem controlleren, så DC-forstærkning er 40 dB og fasemargin er 55
%grader.

%Kp anvendes til at indjustere DC-forstærkningen.
Kp = 10^(40/20)/dcgain(Gp)

%Der vælges en knækfrekvens på fire gange mindre krydsfrekvensen, hvor
%lag-regulatoren giver -14 grader til fasen. Da der ønskes en fasemargin på
%55 grader, kan krydsfrekvensen findes der, hvor fasen er:
G_pP = 55 - 180 + 14
bode(Gp)

%Dette findes ved 2,1 rad/s
wc = 2.1
wi = 2.1/4
taui = 1/wi

%Ved denne krydsfrekvens aflæses forstærkningen til -1, hvilket skal
%indjusteres med beta-værdien
beta = Kp/(10^(1/20)) %jf. slutværdi = 20*log(Kp/beta)

%Den samlede overføringsfunktion for regulatoren er derfor
Gc = Kp*tf([taui 1],[beta*taui 1])

%Åben-sløjfen er dermed:
Go = tf(Gc*Gp)
margin(Go)

%Fasemargin er 54,7 grader, og DC-forstærkning er 40 dB

%Lukket-sløjfen:
Gl = feedback(Go,1)
bode(Gl)
step(Gl)