function [P] = poisson_prob(lambda,x,t)
%DENNE FUNKTION UDREGNER SANDSYNLIGHEDEN FOR ET BESTEMT UDFALD I EN
%POISSON-FORDELING

x;
P = ((lambda*t)^x)/(factorial(x))*exp(-lambda*t);

end