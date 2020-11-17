clear
clc
hold on
for h=[1,0.5,0.25]
    x=-1:h:1;
    f=x.^2;
    plot(x,f)
end
hold off