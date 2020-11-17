function [P] = binomial_prob(n,p,x)
%DENNE FUNKTION UDREGNER SANDSYNLIGHEDEN FOR ET BESTEMT UDFALD I EN
%BINOMIAL FORDELING

x;
P = factorial(n)/(factorial(n-x)*factorial(x))*p^x*(1-p)^(n-x);

end

