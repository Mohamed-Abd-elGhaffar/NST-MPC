classdef SerialReadBlock < matlab.System & coder.ExternalDependency
    % SerialReadBlock: Reads Time, Omega, and Load from UART (standard Linux)
    
    % --- FIX 1: Use Properties instead of persistent variables ---
    properties (Access = private)
        t_hold
        w_hold
        l_hold
    end

    methods (Access = protected)
        function setupImpl(obj)
            % Initialize the state variables
            obj.t_hold = 0;
            obj.w_hold = 0;
            obj.l_hold = 0;

            if coder.target('Rtw')
                coder.cinclude('serial_reader.hpp');
                coder.ceval('init_serial');
            end
        end

        function [esp_time, omega, load] = stepImpl(obj)
            % Default outputs to the values stored in properties
            esp_time = obj.t_hold;
            omega = obj.w_hold;
            load = obj.l_hold;

            if coder.target('Rtw')
                coder.cinclude('serial_reader.hpp');
                
                % Create temp variables for C to write into
                t_val = 0; 
                w_val = 0; 
                l_val = 0;
                
                % Initialize status (required for code generation)
                status = int32(0); 
                
                % Call C function
                status = coder.ceval('read_serial_data', ...
                    coder.ref(t_val), ...
                    coder.ref(w_val), ...
                    coder.ref(l_val));
                
                if status == 1
                    % --- FIX 2: Update the Object Properties ---
                    obj.t_hold = t_val;
                    obj.w_hold = w_val;
                    obj.l_hold = l_val;
                    
                    % Update outputs for this immediate step
                    esp_time = t_val;
                    omega = w_val;
                    load = l_val;
                end
            end
        end

        function releaseImpl(~)
            if coder.target('Rtw')
                coder.cinclude('serial_reader.hpp');
                coder.ceval('close_serial');
            end
        end
    end

    methods (Static)
        function name = getDescriptiveName(~)
            name = 'Serial Read (921600)';
        end

        function b = isSupportedContext(context)
            b = context.isCodeGenTarget('rtw');
        end

        function updateBuildInfo(buildInfo, context)
            if context.isCodeGenTarget('rtw')
                buildInfo.addSourceFiles('serial_reader.cpp');
                buildInfo.addIncludePaths(pwd);
                buildInfo.addLinkFlags('-lrt -lpthread');
            end
        end
    end
end