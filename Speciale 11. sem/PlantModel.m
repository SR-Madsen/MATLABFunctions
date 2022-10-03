clear, close all, clc;


syms Rlc Rlg Rcc Lc Lg Cc Zo

%% State-space when vc = C
syms s
A = [-(Rlc+Rcc)/Lc Rcc/Lc -1/Lc;
     Rcc/Lg -(Rlg+Rcc)/Lg 1/Lg;
     1/Cc -1/Cc 0];

B = [1/Lc 0;
     0 -1/Lg;
     0 0];

C = [1 0 0];
D = [0 0];

Gs = C*inv((s*eye(3)-A))*B + D;
Gs_iL_vi = Gs(1,1)


%% Transfer function for vc
syms s

G1 = 1/(s*Lc+Rlc)
G2 = 1/(s*Cc) + Rcc
G3 = 1/(s*Lg+Rlg+Zo)

Gv = (G1*(G2/(1+G2*G3)))/(1 + G1*(G2/(1+G2*G3)))
Gv_simple = simplify(expand(Gv))

Gf = G2/(1+G2*G3)
GiL = G1/(1+G1*Gf)
GiL_simple = simplify(expand(GiL))

%% Transfer function with Laplace voltage divider for vc
syms s

vc = ((1/(s*Cc)+Rcc)*(s*Lg+Rlg+Zo)/(1/(s*Cc)+Rcc+s*Lg+Rlg+Zo)) / (s*Lc+Rlc+((1/(s*Cc)+Rcc)*(s*Lg+Rlg+Zo)/(1/(s*Cc)+Rcc+s*Lg+Rlg+Zo)))
vc_simple=simplify(expand(vc))