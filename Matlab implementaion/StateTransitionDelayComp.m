 function x_next = StateTransitionDelayComp(x,u,scale,td_dot,sample_time)
    scale=double(scale);
    coder.inline('always'); % Force inlining for speed
    x=double(x);
    u=double(u);
    x=x.*scale; % Rescale the state input
    %%state vector is [q mass_actual mass_fictitious mass_dot_fictitious C_1 tau K_I omega_n zeta]
    x_next=zeros(7,1,"double");
    C_1=x(5);
    C_3=double(1.5);
    theta_0=double(0.1701);
    tau=0.05;
    tau=tau/(1-td_dot);
    K_I=0.2149;
    omega_n=x(6);
    zeta=x(7);
    Sample_Time=double(sample_time);
    L=double(0.03);
    W=double(0.09*sin(max(u,theta_0)-theta_0));
    if W<0
        warning("W negative");
        disp(u-theta_0);
    end
    m_bev=(C_1/0.03)*max(L,W)*(min(L,W)^(C_3));
    A=[-1/tau 0 0 0;(1-td_dot) 0 0 0;0 0 0 1;K_I*omega_n^2 0  -omega_n^2 -2*zeta*omega_n];
    B=[1/tau 0 0 0].';
    x_dot=A*x(1:4)+B*m_bev;
    x_next(1:4)=x(1:4)+x_dot*Sample_Time;
    x_next(5:end)=x(5:end); % Parameters remain constant
    x_next=x_next./scale; % scale the state output
end

