function [x_out,P_out,r,S] = EKF_delay_compensated(u,z,Q,R,td_dot,x_km1,P_km1,SampleTime,P_U,new_measurement)
%% initialize variables
Q=double(Q);
R=double(R);
u=double(u);
z=double(z);
P_km1=double(P_km1);
x_old=x_km1(6:7);
x_km1=[x_km1(1:5); x_km1(8:9)];
x_out=zeros(9,1,"double");
scale=[1 1 1 1 150 50 0.4]';
x_km1=double(x_km1)./scale;
%% step 1 Prediction Step
x_next = StateTransitionDelayComp(x_km1, u,scale,td_dot,SampleTime);
[F_k, B] = StateTransitionJacDelayCompen(x_km1, u,scale,td_dot,SampleTime);
x_hat_pri = x_next;
P_pri = F_k * P_km1 * F_k' + Q + B*P_U*B';
if new_measurement==0
    x_est = x_hat_pri.*scale;
    disp(size(x_est));
    disp(size(x_old));
    x_out(1:5) = x_est(1:5);
    x_out(6:7) = x_old;
    x_out(8:9) = x_est(6:7);
    P_out = P_pri;
    r = double(0);
    S = double(0);
    return;
end
%% step 2 innovation
y_hat = x_hat_pri(2)+x_hat_pri(3); 
H= [0 1 1 0 0 0 0];
r = z - y_hat;
S = H * P_pri * H' + R;
K= P_pri * H' / S;
%% step 3 update
I = eye(size(P_pri), 'double');
IKH = I - K * H;
x_est = x_hat_pri + K * r;
P_out = IKH * P_pri * IKH' + K * R * K';
x_est=x_est.*scale;
x_out(1:5) = x_est(1:5);
x_out(6:7) = x_old;
x_out(8:9) = x_est(6:7);
end