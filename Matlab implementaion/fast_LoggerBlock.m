classdef fast_LoggerBlock < matlab.System & coder.ExternalDependency
    % LoggerBlock: Logs Omega, Load, GateS(7), AggS(9) to CSV
    
    methods (Access = protected)
        function stepImpl(~, gateS, aggS,Pg,Pa)
            if coder.target('Rtw')
                coder.cinclude('fast_csv_logger.hpp');
                
                % Pass arrays by reference
                coder.ceval('fast_log_full_row', ...
                    coder.ref(gateS), ...
                    coder.ref(aggS), ...
                    coder.ref(Pg), ...
                    coder.ref(Pa));
             %  coder.ceval('exit', int32(0));
            end
        end
    end

    methods (Static)
        function name = getDescriptiveName(~)
            name = 'Full CSV Logger';
        end

        function b = isSupportedContext(context)
            b = context.isCodeGenTarget('rtw');
        end

        function updateBuildInfo(buildInfo, context)
            if context.isCodeGenTarget('rtw')
                buildInfo.addSourceFiles('fast_csv_logger.cpp');
                buildInfo.addIncludePaths(pwd);
            end
        end
    end
end