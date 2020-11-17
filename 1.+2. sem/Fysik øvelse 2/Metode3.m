T = %periodetiden
r = %radius for den ydre cylinder
s = 2*pi*r %tilbagelagt strækning
s/T = %hastighed for cylinderen

alfa1 = %accelerationen for cylinderen
alfa2 = %decelerationen for cylinderen

m1 = %loddets masse
g = 9.82; %tyngdeaccelerationen

m1*(g-alfa1*r)*r-tau_f=I*alfa1
-tau_f = I*alfa2
%%2 ligninger med 2 ubekendte