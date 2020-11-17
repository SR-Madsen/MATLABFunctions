clear
clc
function [h,l,yN,yO,yC,yU,t] = oscillator_plot( )%do not change this line
    t=(0:0.01:4*pi);
    yN=cos(9*t);
    yO=0.5*exp(-4*t)+0.5*exp(-0.3*t); 
    yC=exp(-2*t)+t.*exp(-2*t);
    yU=exp(-3*t).*(cos(8*t)+sin(8*t));
    hold on
    h=plot(t,yN,'b',t,yO,'r.',t,yC,'r.',t,yU,'k','LineWidth',3);
    xlabel('time, s')
    ylabel('voltage, V')
    title('Oscillators')
    l=legend('yN=Undamped','yO=Overdamped','yC=Overdamped','yU=Underdamped');
end