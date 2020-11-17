p=rand(1,10);
q=ones(10);
save('pqfile','p')
save('pqfile','q','-append')
clear
load('pqfile','q')
openvar('q')