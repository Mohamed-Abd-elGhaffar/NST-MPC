function mass = sim_batch(stop_time,trigger_time,current_gate, current_agg)
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here
    myPath = 'C:\Users\nabil\OneDrive\Documents\MATLAB\smart batch\NMPC\Simulation_ert_rtw';
    step_size = 2e-4;
    % 2. ADD SOURCE FILES (Use the string variable directly or the string literal)
    % Note: coder.const implies it won't change, but string literals are safest.
    
    coder.updateBuildInfo('addSourceFiles', 'functions.c', myPath);
    coder.updateBuildInfo('addSourceFiles', 'Simulation.c', myPath);
    coder.updateBuildInfo('addSourceFiles', 'Simulation_data.c', myPath);
    coder.updateBuildInfo('addSourceFiles', 'rt_nonfinite.c', myPath);
    coder.updateBuildInfo('addSourceFiles', 'rtGetInf.c', myPath);
    coder.updateBuildInfo('addSourceFiles', 'rtGetNaN.c', myPath);

    % 3. INCLUDE PATH
    coder.updateBuildInfo('addIncludePaths', myPath);
    coder.cinclude('functions.h');
    % 2. Define Inputs for the C function
    % Ensure types match the C definition (uint32, double, etc.)
    stop_time_u32 = uint32(round(stop_time/step_size));   % Example value
    trigger_time_u32   = uint32(round(trigger_time/step_size));   % Example value
    
    % 3. Call the C Function
    % coder.ceval( 'function_name', arg1, arg2, ... )
    cost_output = 0;
    
    % We pass the arrays by reference (coder.ref) or value depending on C definition
    % Since your C function takes arrays: real_T _gate_states[7]
    % MATLAB passes arrays by address automatically in ceval.
    
    cost_output = coder.ceval('simulate_batch', ...
                              stop_time_u32, ...
                              trigger_time_u32, ...
                              coder.rref(current_gate), ...
                              coder.rref(current_agg));

    % 4. Use the result
    mass = double(cost_output); 
end
