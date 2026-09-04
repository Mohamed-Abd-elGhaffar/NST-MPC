function [x_out,P_out,r,S] = NO_DT_EKF_delay_compensated(u,z,Q,R,td_dot,x_km1,P_km1,SampleTime,P_U,new_measurement)
%% initialize variables
Q=double(Q);
R=double(R);
u=double(u);
z=double(z);
P_km1=double(P_km1);
x_old=x_km1(5:9);
x_km1=[x_km1(1:4)];
x_out=zeros(9,1,"double");
%% step 1 Prediction Step
x_next = NO_DT_StateTransitionDelayComp(x_km1, u,td_dot,SampleTime);
[F_k, B] = NO_DT_StateTransitionJacDelayCompen(x_km1, u,td_dot,SampleTime);
x_hat_pri = x_next;
P_pri = F_k * P_km1 * F_k' + Q + B*P_U*B';
if new_measurement==0
    x_est = x_hat_pri;
    P_out = P_pri;
    r = double(0);
    S = double(0);
    x_out(1:4) = x_est;
    x_out(5:9) = x_old;
    return;
end
%% step 2 innovation
y_hat = x_hat_pri(2)+x_hat_pri(3); 
H= [0 1 1 0];
r = z - y_hat;
S = H * P_pri * H' + R;
K= P_pri * H' / S;
%% step 3 update
I = eye(size(P_pri), 'double');
IKH = I - K * H;
x_est = x_hat_pri + K * r;
P_out = IKH * P_pri * IKH' + K * R * K';
x_out(1:4) = x_est;
x_out(5:9) = x_old;
end