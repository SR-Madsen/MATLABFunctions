clear, close all, clc;

syms Rlc Rlg Rcc Lc Lg Cc Zo

%fsw = 24000;
%fs = 2*fsw;
%Ts = 1/fs;

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

%% Transfer function for vc/iL
syms s Ts n z t

G1 = 1/(s*Lc+Rlc)
G2 = 1/(s*Cc) + Rcc
G3 = 1/(s*Lg+Rlg+Zo)

Gv = (G1*(G2/(1+G2*G3)))/(1 + G1*(G2/(1+G2*G3)))
Gv_simple = simplify(expand(Gv))

Gf = G2/(1+G2*G3)
GiL = G1/(1+G1*Gf)
GiL_simple = simplify(expand(GiL))

% s = 2/Ts*((1-z^-1)/(1+z^-1)) = 2/Ts*((z-1)/(z+1)) (Tustin)
GiL_z = (1-z^-1)*subs(GiL_simple/s,s,2/Ts*((1-z^-1)/(1+z^-1)));
GiL_z_simple = simplify(expand(GiL_z))

Gf_z = (1-z^-1)*subs(Gf/s,s,2/Ts*((1-z^-1)/(1+z^-1)));
Gf_z_simple = simplify(expand(Gf_z))

% s = (1-z^-1)/Ts (Backward Euler)
%sub = (1-z^-1)/Ts;
%GiL_z = (1-z^-1)*subs(GiL_simple/s,s,sub)
%GiL_z_simple = simplify(expand(GiL_z))

%Gf_z = (1-z^-1)*subs(Gf/s,s,sub)
%Gf_z_simple = simplify(expand(Gf_z))

% s = (z-1)/Ts (Forward Euler)
%sub = (z-1)/Ts;

%Gf_z = (1-z^-1)*subs(Gf/s,s,sub)
%Gf_z_simple = simplify(expand(Gf_z))


%% Transfer function with Laplace voltage divider for vc
syms s

vc = ((1/(s*Cc)+Rcc)*(s*Lg+Rlg+Zo)/(1/(s*Cc)+Rcc+s*Lg+Rlg+Zo)) / (s*Lc+Rlc+((1/(s*Cc)+Rcc)*(s*Lg+Rlg+Zo)/(1/(s*Cc)+Rcc+s*Lg+Rlg+Zo)))
vc_simple=simplify(expand(vc))

%% Transfer function for Gic
syms Kc Td

Gic_ol = Kc*GiL_simple%*exp(-s*Td)
Gic_cl = Gic_ol/(1+Gic_ol);
Gic_cl_simple = simplify(expand(Gic_cl))

Gic_ol_z = Kc*GiL_z_simple;
Gic_cl_z = Gic_ol_z/(1+Gic_ol_z);
Gic_cl_z_simple = simplify(expand(Gic_cl_z))

%% Transfer function for Go
Go_nc = Gic_cl*Gf;
Go_nc_simple = simplify(expand(Go_nc))

Go_nc_z = Gf_z_simple*Gic_cl_z_simple;
Go_nc_simple_z = simplify(expand(Go_nc_z))

%% Transfer function for PR controller
syms Kp Kr omega_0 omega_w
G_pr_s = (2*Kr*omega_w*s)/(s^2+2*omega_w*s+omega_0^2)

% s = 2/Ts*((1-z^-1)/(1+z^-1)) = 2/Ts*((z-1)/(z+1)) (Tustin)
G_pr_z = subs(G_pr_s,s,2/Ts*((1-z^-1)/(1+z^-1)))
G_pr_z_simple = simplify(expand(G_pr_z))