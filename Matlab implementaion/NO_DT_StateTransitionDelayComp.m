 function x_next = NO_DT_StateTransitionDelayComp(x,u,td_dot,sample_time)
    coder.inline('always'); % Force inlining for speed
    x=double(x);
    u=double(u);
    %%state vector is [q mass_actual mass_fictitious mass_dot_fictitious C_1 tau K_I omega_n zeta]
    x_next=zeros(1,4,"double");
    C_1=183.55;
    C_3=double(1.5);
    theta_0=double(0.1701);
    tau=0.05;
    tau=tau/(1-td_dot);
    K_I=0.2149;
    omega_n=56.31;
    zeta=0.43;
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
    x_dot=A*x+B*m_bev;
    x_next=x+x_dot*Sample_Time;
end

