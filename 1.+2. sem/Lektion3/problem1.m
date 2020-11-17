x=-5:0.5:5;
f1=x.^2;
f2=10*x;
save('f1mat','f1','x','-v7.3')
save('f2mat','f2','x','-v7.3')
clear
load('f1mat')
load('f2mat', 'f2')

hold on
plot(x,f1,'.-k'); plot(x,f2,'.-k')
title('Plot over to grafer')
xlabel('x-aksen')
ylabel('y-aksen')
hold off