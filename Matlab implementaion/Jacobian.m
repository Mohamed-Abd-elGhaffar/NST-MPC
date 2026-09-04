function J = Jacobian(x, u,Ts)
    % Tunable perturbation size
    epsilon = 1e-7; 


    x_dot_nominal = f_dynamics(x, u,Ts);
    n = length(x);
    J = zeros(n, n);
    
    % Loop through each state column
    for j = 1:n
        x_perturbed = x;
        x_perturbed(j) = x(j) + epsilon;
        x_dot_perturbed = f_dynamics(x_perturbed, u,Ts);
        % Evaluate dynamics at perturbed state 
        % Calculate slope (Rise over Run)
        J(:, j) = (x_dot_perturbed - x_dot_nominal) / epsilon;
    end
end
