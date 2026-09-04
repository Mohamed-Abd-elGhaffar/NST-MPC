function [X_k_plus1]  = f_dynamics(x,u,Ts)
i = 5;
Ts2 = Ts ;
b1= 1.4434;
K_start= 1076400;
B_start= 9.0407e+03;
C_valve1= 0.1056;
v_stribeck= 0.005;
ratio= 0.9178;
C_valve3= 0.0729;
c2= 0.0087;
K_end= 1076400;
B_end= 9.6617e+03;
M_structure_ext= 15.7405;
C_valve5= 0.0591;
F_total_ext= 2.0280;
F_total_ret=  1.4820;
M_structure_ret= 4.7308;
%% constants
g = -9.81;
gamma = 0.5191;
m_gate = 0.19217;
m_Q = 0.02301;
m_G = 0.0957;
m_S = 0.02129;
I_gate = 0.001333991;
I_B = 0.00114162;
Loa = 0.2230;
Lob = 0.1612;
Loc = 0.071;
Las = 0.157;
Lbg = 0.0885;
Lbh = 0.1770;
% pneumatic cylinder constants
%v_stribeck = 0.01;
%F_static = 20.1;
k_air = 1.2; 
R_air = 287; 
T = 294; 
V_tank = 24e-3; 
p_atm = 101325;
A_ext = pi*((16e-3)^2)/4;
A_ret = pi*(((16e-3)^2)-(6e-3)^2)/4;
V_dead_ext = A_ext * (12e-3);
V_dead_ret = A_ret * (12e-3);
Stroke = 100e-3;
buffer = .5e-4;
Rmax = 0.3337+buffer;
Rmin = Rmax-Stroke-buffer;
%% Unpack
theta = x(1);
theta_dot = x(2);
p_tank  = 9*101325;
p_ext   = x(3);
p_ret   = x(4);
b2_ext = 96.198638912657557;
b2_ret = 15.071999999999999;
p_ret_g = p_ret - p_atm;
p_ext_g = p_ext - p_atm;
F_cyl = A_ext*p_ext_g - A_ret*p_ret_g;
% Macros
s = sin(theta-gamma);
c = cos(theta - gamma);
%% 1.calculating alpha
alpha = atan2(Lob*cos(gamma)-Loa*sin(theta),...
    Lob*sin(gamma)+Loa*cos(theta));
%% 2. Calculating alpha_dot (C_val), R_dot (R_val) jacobians
C_val = (Loa*(Lob * s-Loa))/ ...
    (Loa^2+Lob^2-2*Loa*Lob*s);
dC_dtheta = (Loa * Lob * (Lob^2 - Loa^2) * c) / ...
             (Loa^2 + Lob^2 - 2*Loa*Lob*s)^2;
R_val = - Loa * sin(theta+alpha);
R = sqrt(Loa^2+Lob^2-2*Loa*Lob*s);
Rdot = R_val * theta_dot;
%% 3. Calculate Mechanical Inertia M_eq
M_eq = I_gate ...   %gate's inertia
    + I_B * C_val^2 ...  %cylinder's equivalent inertia around B
    + m_Q * (1/12 * Las^2 * C_val^2 ... %Rod's equivalent inertia
    + (-Loa * sin(theta) + 1/2 * Las * C_val * sin(alpha))^2 ...
    + (Loa * cos(theta) + 1/2 * Las * C_val * cos(alpha))^2) ...
    + m_S * ((-Loa * sin(theta) + Las * C_val * sin(alpha))^2 ... %Piston's equivalent inertia
    + (Loa * cos(theta) + Las * C_val * cos(alpha))^2);

%% 3. Calculate Dynamic Forces
% V_eq = m_gate * g * (Loc * cos(theta)) ...
%      + m_G * g * (-Lob *sin(gamma) + Lbg * cos(alpha)) ...
%      + m_Q * g * (Loa * cos(theta) - 1/2 * Las * cos(alpha)) ...
%      + m_S * g * (Loa * cos(theta) - Las * cos(alpha));
G_val = m_gate * g * (Loc * -sin(theta - 0.036765969138185)) ...
      + m_G * g * (Lbg * C_val * -sin(alpha)) ...
      + m_Q * g * (Loa * -sin(theta) + 1/2 * Las * C_val * sin(alpha)) ...
      + m_S * g * (Loa * -sin(theta) + Las * C_val * sin(alpha)); 
N_val = 1/2 * (2 * I_B * C_val * dC_dtheta  ...   %cylinder's Component
      + m_Q * (1/6 * Las^2 * C_val * dC_dtheta ...  %Rod's  Component
      + 2 * (-Loa * sin(theta) + 1/2 * Las * C_val * sin(alpha)) ...
      * (-Loa * cos(theta) + 1/2 * Las * (dC_dtheta * sin(alpha) + C_val^2 * cos(alpha))) ...
      + 2 * (Loa * cos(theta) + 1/2 * Las * C_val * cos(alpha)) ...
      * (Loa * -sin(theta) + 1/2 * Las * (dC_dtheta * cos(alpha) + C_val^2 * -sin(alpha)))) ...
      + 2 * m_S * ((-Loa * sin(theta) + Las * C_val * sin(alpha)) ...
      * ((-Loa * cos(theta) + Las * (dC_dtheta * sin(alpha) + C_val^2 * cos(alpha))) ...
      + (Loa * cos(theta) + Las * C_val * cos(alpha)) ...
      * (Loa * -sin(theta) + Las * (dC_dtheta * cos(alpha)+ C_val^2 * -sin(alpha)))))) * theta_dot^2;
%% Pneumatics model
R_i =R-Rmin+0.001; %the 0.0001 is added to make sure the stroke doesnt turn -ve
V_ext = V_dead_ext + (A_ext * R_i);
V_ret = V_dead_ret + (A_ret * (Stroke-R_i));
%% calculating mdot
if u == 0  %extending
    m_dot_ext = get_mdot(p_tank,p_ext,C_valve1);
    m_dot_ret = -get_mdot(p_ret,p_atm,C_valve5);
    m_dot_tank = m_dot_ext;
elseif u == 1
    m_dot_ext = -get_mdot(p_ext, p_atm,C_valve3);
    m_dot_ret = get_mdot(p_tank,p_ret,C_valve1);
    m_dot_tank = m_dot_ret;
else 
    m_dot_tank = 0;
    m_dot_ext = 0;
    m_dot_ret= 0;
   
end

ret = u == 1;
ext = u == 0;
F_static = (ret*F_total_ret+ext*F_total_ext) * (1 + b1 * C_val^2 + (b2_ret*ret+b2_ext*ext) * R_val^2);
F_c = ratio * F_static;
Fric_visc = c2 * Rdot * R_val;
Fric_stiction = F_c + (F_static - F_c)*exp(-(Rdot/v_stribeck)^2);
Fric_total = Fric_visc+ Fric_stiction * tanh(150*theta_dot);
R_underMin = max(0 , Rmin-R); % Positive when hitting Retraction Wall
R_overMax = max(0, R-Rmax);   % Positive when hitting Extension Wall

% 2. Flags
RIsOverMax = (R_overMax > 0);
RIsUnderMin = (R_underMin > 0);

% 3. Forces (Calculated Explicitly)
% Extension Wall (Resists Positive Rdot)
F_Stop_Ext = (-K_start * R_overMax - B_start * Rdot) * RIsOverMax;

% Retraction Wall (Resists Negative Rdot)
F_Stop_Ret = (K_end * R_underMin - B_end * Rdot) * RIsUnderMin;

IsImpact = (R_underMin > 0) || (R_overMax > 0);

% If impacting, add the virtual mass
M_eq = M_eq + (M_structure_ext * ext + M_structure_ret * ret) * IsImpact * R_val^2;

% 4. Total Force
F_stopper = F_Stop_Ext + F_Stop_Ret;
% 4. State Space Update
x_dot = zeros(4,1);
x_dot(1) = theta_dot;
x_dot(2) = (1/M_eq) * (F_cyl*R_val - N_val - G_val - Fric_total + F_stopper * R_val );
x_dot(3) = (m_dot_ext * R_air * k_air * T / V_ext) - (A_ext*Rdot) * p_ext * k_air/ V_ext;
x_dot(4) = (m_dot_ret * R_air * k_air * T / V_ret) + (A_ret*Rdot) * p_ret * k_air/ V_ret;
X_k_plus1 = zeros(4,1);
X_k_plus1 = x_dot .* Ts + x;



end
function mdot = get_mdot(p_up,p_down,C_valve)
%% constants
S = 4.9; C_hardware = (S/5)*1e-8; rho_air = 1.225; b_crit = 0.528;
C_actual = C_hardware * C_valve;
%% deciding subsonic vs chocked
if p_up>p_down
   r = p_down/p_up;
   direction = 1;
else
   r = p_up/p_down;
   direction = -1;
   p_up = p_down;
end
r = max(0,min(r,1));
if r > b_crit    %subsonic
    flow_factor = sqrt(1 - ( (r-b_crit) / (1-b_crit) )^2);
else            %chocked
    flow_factor = 1;
end
%% calcultating mdot
mdot = C_actual * p_up * rho_air * flow_factor*direction;
end