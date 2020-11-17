clear
clc
function [y1, y2] = functWithIf(x1, x2) %do not change this line
if x1==x2
    y1=x1, y2=x2
else
    if x1>x2
        y1=x1
        y2=x1+x2
    else
        y1=x2
        y2=x1+x2
    end
end