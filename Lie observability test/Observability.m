syms x1 x2 x3 x4 x5 x6 x7 x8 x9 u % States and parameters
x = [x1; x2; x3; x4; x5; x8; x9];
f = [-(x5)*u+(1)*u;x1;x4;x7*x8^2*x1-x8^2*x3-2*x8*x9*x4;0;0;0]; 
h = x2+x3; 

n = length(x);
O = sym(zeros(n, n));
Lfh = h;

for i = 1:n
    O(i, :) = jacobian(Lfh, x);
    Lfh = jacobian(Lfh, x) * f;
end

obsv_rank = rank(O)
O;
obsv_det = simplify(det(O))