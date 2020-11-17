m1 = %loddets masse
m2 = %cylinderens masse
g = 9.82; %tyngdeaccelerationen
h_m1 = %loddets højde i meter
v = %loddets hastighed

E_pot = m1*g*h_m1

E_kinm1 = 1/2*m1*v^2

E_kinm2 = E_pot - E_kinm1


T = %periodetiden
w = (2*pi)/T
E_kinm2 = 1/2*I*w^2
I = (2*E_kinm2)/w^2