clear, close all, clc;

syms Rlc Rlg Rcc Lc Lg Cc Zo

%fsw = 24000;
%fs = 2*fsw;
%Ts = 1/fs;

%% State-space when vc = C
syms s
A = [-(Rlc)/Lc -1/Lc -Rcc/Lc;
     0 0 1/Cc;
     -Rlc/Lc -(1/Lc+1/Lg) -(Rcc/Lg + Rcc/Lc)];

B = [1/Lc 0;
     0 0;
     1/Lc Rlg/Lg];

C = [1 0 0;
     0 1 Rcc];
D = [0];

Gs = C*inv((s*eye(3)-A))*B + D;
Gs_iL_vi = simplify(expand(Gs(1,1)))

%% Discretization of state-space using ZOH
% WARNING: WILL FAIL
% syms Ts Kc
% Ad = expm(A*Ts);
% Bd = inv(A)*expm(A*Ts-eye(3))*B;
% Cd = C;
% Dd = D;
% GiL_z = Cd*inv((s*eye(3)-Ad))*Bd+Dd;
% GiL_z_simple = simplify(expand(GiL_z));
% 
% Gi_ol_z = GiL_z*Kc;
% Gi_cl_z = Gi_ol_z/(1+Gi_ol_z);
% 
% % G23_cl as state-space
% A_G23 = [0 1; -1/Cc*Lg -Rcc/Lg-Rlg/Lg-Zo/Lg];
% B_G23 = [0; 1];
% C_G23 = [-(Rcc+Rlg+Zo)/(Cc*Lg) (-Cc*Rcc^2+Lg)/(Cc*Lg)];
% D_G23 = [Rcc];
% 
% Ad_G23 = expm(A_G23*Ts);
% Bd_G23 = inv(A_G23)*expm(A_G23*Ts-eye(2))*B_G23;
% Cd_G23 = C_G23;
% Dd_G23 = D_G23;
% G23_z = Cd_G23*inv((s*eye(2)-Ad_G23))*Bd_G23+Dd_G23;
% G23_z_simple = simplify(expand(G23_z));
% 
% % Go transfer function
% Go_nc_z = Gi_cl_z*G23_z;
%Go_nc_z_simple = simplify(expand(Go_nc_z,'ArithmeticOnly',true,'IgnoreAnalyticConstraints',true))
syms Ts t

Ad = ilaplace(inv(s-eye(length(A))-A));
Ad_Ts = subs(Ad,t,Ts)

Bd = int(Ad,0,Ts)*B

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

Gic = Gv*(1/G2);
Gic_simple = simplify(expand(Gic))

% s = 2/Ts*((1-z^-1)/(1+z^-1)) = 2/Ts*((z-1)/(z+1)) (Tustin)
% GiL_z = (1-z^-1)*subs(GiL_simple/s,s,2/Ts*((1-z^-1)/(1+z^-1)));
% GiL_z_simple = simplify(expand(GiL_z))
% 
% Gf_z = (1-z^-1)*subs(Gf/s,s,2/Ts*((1-z^-1)/(1+z^-1)));
% Gf_z_simple = simplify(expand(Gf_z))

GiL_inv = simplify(ilaplace(GiL));
GiL_n = simplify(subs(GiL_inv,t,n*Ts));
GiL_z = simplify(expand((1-z^-1)*ztrans(GiL_n)))

%% Test til udregning af overføringsfunktionen for iC/iC*
syms s C L R Z K
G1 = 1/(L*s+R);
G2 = 1/(C*s);
Gf1 = G2/(1+G2/Z);
Gf2 = G1*Gf1*C*s/(1+G1*Gf1*C*s);
Gc = K*Gf2/(1+K*Gf2);
simplify(Gc)

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
% syms Kc Td
% 
% Gic_ol = Kc*GiL_simple%*exp(-s*Td)
% Gic_cl = Gic_ol/(1+Gic_ol);
% Gic_cl_simple = simplify(expand(Gic_cl))
% 
% Gic_ol_z = Kc*GiL_z_simple;
% Gic_cl_z = Gic_ol_z/(1+Gic_ol_z);
% Gic_cl_z_simple = simplify(expand(Gic_cl_z))

%% Transfer function for Go
% Go_nc = Gic_cl*Gf;
% Go_nc_simple = simplify(expand(Go_nc))
% 
% Go_nc_z = Gf_z_simple*Gic_cl_z_simple;
% Go_nc_simple_z = simplify(expand(Go_nc_z))

%% Transfer function for PR controller
syms Kp Kr omega_0 omega_w s Ts z omega_warp KT n t
G_pr_s = (2*Kr*omega_w*s)/(s^2+2*omega_w*s+omega_0^2)

% s = 2/Ts*((1-z^-1)/(1+z^-1)) = 2/Ts*((z-1)/(z+1)) (Tustin)
G_pr_z = subs(G_pr_s,s,2/Ts*((1-z^-1)/(1+z^-1)));
G_pr_z_simple = simplify(expand(G_pr_z));

% s = omega_warp/(tan((omega_warp*Ts)/2))*((1-z^-1)/(1+z^-1)) (pre-warped
% Tustin)
G_pr_z = subs(G_pr_s,s,KT*((z-1)/(z+1)));
G_pr_z_simple = simplify(expand(G_pr_z))

G_pr_test = (2*KT*Kr*omega_w*(z^-1 - z^-2))/(KT^2 - 2*KT^2*z^-1 + KT^2*z^-2 + 2*omega_w*KT - 2*omega_w*KT*z^-2 + omega_0^2 + 2*omega_0^2*z^-1 + omega_0^2*z^-2);


% Impulse invariant
G_pr_n = ilaplace(G_pr_s);
G_pr_nT = subs(G_pr_n,t,n*Ts);
G_pr_z = Ts*ztrans(G_pr_nT);
G_pr_z_simple = simplify(expand(G_pr_z))


%% Transfer function for lead-lag network
syms omega_max s kf KT z
G_ll_s = omega_max*((s+kf*omega_max)/(kf*s+omega_max));

% s = omega_warp/(tan((omega_warp*Ts)/2))*((1-z^-1)/(1+z^-1)) (pre-warped
% Tustin)
G_ll_z = subs(G_ll_s,s,KT*((z-1)/(z+1)));
G_ll_z_simple = simplify(expand(G_ll_z));

G_ll_s = ((1+s*(1/(sqrt(kf)*omega_max)))/(1+s*kf*1/(sqrt(kf)*omega_max)));
G_ll_z = subs(G_ll_s,s,KT*((z-1)/(z+1)));
G_ll_z_simple = simplify(expand(G_ll_z))

%% Transfer function for Generalized Integrator
syms omega_mark omega_c s z
G_GI_s = (omega_mark^2*s)/(s^2 + omega_c*s + omega_mark^2);

% s = FOH

%% Transfer function for second order differential equation
% Seriously need to use MATLAB because it's messing with me.
syms vi Lc ddt ddt2 Rlc il ic Rcc vcap Cc io
eq1 = Lc*ddt*il + Rlc*il + ic*Rcc + vcap
eq1_2 = subs(eq1,ic,Cc*ddt*vcap);
eq1_3 = subs(eq1_2,il,Cc*ddt*vcap+io)
eq1_3_2 = vcap + Rlc*io + Rlc*Cc*ddt*vcap + Lc*ddt*io + Lc*Cc*ddt2*vcap + Cc*Rcc*ddt*vcap;
eq1_setup=vi==eq1_3_2;
eq1_sol = solve(eq1_setup,ddt2)