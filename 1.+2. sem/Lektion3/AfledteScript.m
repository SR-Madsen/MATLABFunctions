clc, clear
edit('filception')
fileID=fopen('filception.m','w');
fprintf(fileID, '%%This file calculates tangent line at point x=2\n syms x f\n f=x^2-x-3\n Afledte=diff(f);\n L=subs(f,x,2)+subs(Afledte,x,2)*(x-2)')
fclose(fileID);
run filception
edit('filception')