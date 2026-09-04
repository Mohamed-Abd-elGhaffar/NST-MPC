classdef GateDriver < matlab.System & coder.ExternalDependency
    % GateDriver wraps the custom C++ gate control logic using pigpio.
    
    methods (Access = protected)
        function setupImpl(~)
            if coder.target('Rtw')
                % This line fixes the "implicit declaration" error
                coder.cinclude('gate.hpp'); 
                coder.ceval('gate_initialize');
            end
        end

        function stepImpl(obj, u)
            if coder.target('Rtw')
                coder.cinclude('gate.hpp');
                coder.ceval('gate_state', int32(u));
            end
        end

        function releaseImpl(~)
            % Cleanup if needed
        end
    end

    methods (Static)
        function name = getDescriptiveName(~)
            name = 'Gate Control (pigpio)';
        end

        function b = isSupportedContext(context)
            b = context.isCodeGenTarget('rtw');
        end

        function updateBuildInfo(buildInfo, context)
            if context.isCodeGenTarget('rtw')
                % 1. Add your source file
                buildInfo.addSourceFiles('gate.cpp');
                
                % 2. FORCE the linker flag directly
                buildInfo.addLinkFlags('-lpigpio');
                
                % 3. Include current directory
                buildInfo.addIncludePaths(pwd);
            end
        end
    end
end