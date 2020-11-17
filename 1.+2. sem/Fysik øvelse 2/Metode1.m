d1 = %diameter af den indre cylinder
d2 = %diameter af den ydre cylinder
l1 = %bredde af den indre cylinder
l2 = %bredde af den ydre cylinder
h =  %tykkelse af den ydre cylinder

%Massen findes som volumen gange densitet = V*p = V*7500
%Volumen skal udregnes
V_indre = (2*pi*d1*l1)
V_ydre = ((2*pi*(d2/2)^2)-(2*pi*(d1/2)^2)+(2*pi*(d2/2)^2*l2))*h

M = (V_indre + V_ydre)*7500
M1 = V_indre * 7500
M2 = V_ydre * 7500
I = 1/2*M2*((d1/2)^2+(d2/2)^2)+1/2*m1*(d1/2)^2