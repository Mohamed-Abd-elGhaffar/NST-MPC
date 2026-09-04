function [J,B] = StateTransitionJacDelayCompen(x,u,scale,td_dot,sample_time)
%%state vector is [q mass_actual mass_fictitious mass_dot_fictitious C_1 tau K_I omega_n zeta]
%%with sampling time of 0.01
x=x.*scale;
C_3=1.5;
C_1=x(5);
tau=0.05;
K_I=0.2149;
omega_n=x(6);
zeta=x(7);
theta_0=double(0.1701);
Sample_Time=double(sample_time);
L=double(0.03);
W=double(0.09*sin(max(u,theta_0)-theta_0));
% m_bev=(C_1/0.03)*max(L,W)*(min(L,W)^(C_3));
tau=tau/(1-td_dot);
A=[-1/tau 0 0 0;(1-td_dot) 0 0 0;0 0 0 1;K_I*omega_n^2 0  -omega_n^2 -2*zeta*omega_n];
B=[1/tau 0 0 0].';
dx_dC_1=Sample_Time*B*(1/0.03)*max(L,W)*(min(L,W)^(C_3));
% dx_dtau=[Sample_Time*(m_bev-x(1))*(-1/tau^2) 0 0 0].';
% dx_dK_I=[0 0 0 Sample_Time*omega_n^2*x(1)].';
dx_domega_n=[0 0 0 Sample_Time*(2*omega_n*K_I*x(1)-2*omega_n*x(3)-2*zeta*x(4))].';
dx_dzeta=[0 0 0 -Sample_Time*(2*omega_n*x(4))].';
dx_dx=Sample_Time*A+eye(4);
dx_dtheta=[dx_dC_1 dx_domega_n dx_dzeta];
J = [dx_dx, dx_dtheta;
         zeros(3,4,'double'), eye(3,'double')];
J= J.*(scale'./scale); % scale the Jacobian
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
B=[B;0;0;0]*dm_du;
end