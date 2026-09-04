function [Cost] = Cost_func(t,x_gate,x_flow,t_horizon,m_desired)
%COST_FUNC Summary of this function goes here
%   Detailed explanation goes here
m_sim=sim_batch(t_horizon,t,x_gate,x_flow);
Cost= (m_sim-m_desired)^2; 
end

