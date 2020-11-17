r = %radius
m = %cylinderens masse
g = 9.82; %tyngdeaccelerationen
theta_0 = %90, 45 eller 15 grader = 1/2 * pi , 1/4 * pi , 1/12 * pi
theta_t = theta_0 * sin(w*t) %vinkel
T = %periodetiden
w = T/(2*pi);

w = sqrt((m*g*r)/I)
%Isoler I?
