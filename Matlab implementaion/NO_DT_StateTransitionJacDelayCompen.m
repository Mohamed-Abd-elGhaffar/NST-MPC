function [J,B] = NO_DT_StateTransitionJacDelayCompen(x,u,td_dot,sample_time)
%%state vector is [q mass_actual mass_fictitious mass_dot_fictitious C_1 tau K_I omega_n zeta]
%%with sampling time of 0.01
C_3=1.5;
C_1=183.55;
tau=0.05;
K_I=0.2149;
omega_n=56.31;
zeta=0.43;
theta_0=double(0.1701);
Sample_Time=double(sample_time);
L=double(0.03);
W=double(0.09*sin(max(u,theta_0)-theta_0));
% m_bev=(C_1/0.03)*max(L,W)*(min(L,W)^(C_3));
tau=tau/(1-td_dot);
A=[-1/tau 0 0 0;(1-td_dot) 0 0 0;0 0 0 1;K_I*omega_n^2 0  -omega_n^2 -2*zeta*omega_n];
B=[1/tau 0 0 0].';
dx_dx=Sample_Time*A+eye(4);
J = [dx_dx];
if W>L
    dm_dw=(C_1/0.03)*L^(C_3);
else
    dm_dw=(C_1/0.03)*C_3*W^(C_3-1)*L;
end
if u>theta_0
    dW_du=0.09*cos(u-theta_0);
else
    dW_du=double(0);
end
dm_du=dm_dw*dW_du;
B=[B]*dm_du;
end