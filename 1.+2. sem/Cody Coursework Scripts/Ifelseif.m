clear
clc
x=[1 2 3];
y=[4 5 6].';
z = x*y;
if z == 20
    mes = 'red'; f=3*x+1; 
elseif z > 20
    mes = 'blue'; f=3*y+1;
else
    mes = 'green'; f=3*z+1;
end