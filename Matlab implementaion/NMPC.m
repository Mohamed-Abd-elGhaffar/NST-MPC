function [u] = NMPC(x_gate,x_flow,m_desired,start)
%NMPC Summary of this function goes here
% this function implements a Nonlinear Model Predictive Control (NMPC) strategy
% for a given system state x. The function returns the optimal control input u.
t_horizon = 2 ; % prediction horizon in seconds
persistent state
if isempty(state)
    state = 0;
end

if state == 0
    if start == 1
        state = 1;
    end
    u=0;
else
    options = optimset('Display','iter');
    t_off=fminbnd(@(t_off) Cost_func(t_off, x_gate, x_flow, t_horizon, m_desired), -1,t_horizon, options);
    u=1;
    if t_off <  5e-3
        state = 0;
        u=0;
    end
end

