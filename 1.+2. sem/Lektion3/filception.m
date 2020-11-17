%This file calculates tangent line at point x=2
 syms x f
 f=x^2-x-3
 Afledte=diff(f);
 L=subs(f,x,2)+subs(Afledte,x,2)*(x-2)