classdef LastStateInitializer < matlab.System & ...
        matlab.system.mixin.Propagates
    % LastStateInitializer Reads the last row of sim_data.csv for Code Gen.
    % Outputs Gate States(7x1), Agg States(9x1), Pg(7x7), and Pa(9x9).
    
    properties (Nontunable)
        % File Name
        FileName = 'sim_data.csv';
    end

    properties (Access = private)
        % Pre-allocate with fixed sizes for code generation
        GateData = zeros(6, 1);
        AggData  = zeros(9, 1);
        PgData   = zeros(6, 6);
        PaData   = zeros(9, 9);
    end

    methods (Access = protected)
        function setupImpl(obj)
            % Use coder.target to distinguish between simulation and generated code if needed
            % But standard fopen/fclose works in many C++ targets.
            
            fid = fopen(obj.FileName, 'r');
            if fid ~= -1
                fprintf('Successfully opened file: %s\n', obj.FileName);
                lastLine = '';
                
                % Read through the file to find the last line
                while ~feof(fid)
                    line = fgetl(fid);
                    if ischar(line) && ~isempty(line)
                        lastLine = line;
                    end
                end
                fclose(fid);
                
                if ~isempty(lastLine)
                    % Parse the CSV string. 
                    % Total columns: 7 (Gate) + 9 (Agg) + 49 (Pg) + 81 (Pa) = 146
                    vals = sscanf(lastLine, '%f,', [1, 132]);
                    
                    if length(vals) >= 132
                        % The new CSV doesn't have Time/Omega/Load, so it starts at index 1
                        obj.GateData(1:6) = vals(1:6).';
                        obj.AggData(5:9)  = vals(11:15).';
                        
                        % Extract the flattened matrices (49 and 81 elements)
                        % We reshape and then transpose (.') to convert C++ row-major 
                        % memory layout back into a correct MATLAB matrix.
                        obj.PgData = reshape(vals(16:51),  [6, 6]).';
                        obj.PaData = reshape(vals(52:132), [9, 9]).';
                       % fprintf("Dynamics state: %d \n",obj.GateData)
                       % fprintf("Aggregate state : %d \n",obj.AggData)
                        fprintf('Debug point\n')
                    else
                        fprintf('Warning: Last line does not contain 132 values.\n');
                    end
                else
                    fprintf('Debug point 2\n')
                end
            else
                fprintf("can't find the file\n")
            end
        end

        function [y1, y2, y3, y4] = stepImpl(obj)
            % Output the cached values
            y1 = obj.GateData;
            y2 = obj.AggData;
            y3 = obj.PgData;
            y4 = obj.PaData;
        end

        %% Mandatory for Code Generation with Propagates mixin
        function num = getNumOutputsImpl(~)
            % We now have 4 output ports
            num = 4;
        end

        function [sz1, sz2, sz3, sz4] = getOutputSizeImpl(~)
            sz1 = [6, 1]; 
            sz2 = [9, 1];
            sz3 = [6, 6]; % Pg Matrix
            sz4 = [9, 9]; % Pa Matrix
        end
        
        function [dt1, dt2, dt3, dt4] = getOutputDataTypeImpl(~)
            dt1 = 'double'; 
            dt2 = 'double';
            dt3 = 'double'; 
            dt4 = 'double';
        end
        
        function [cp1, cp2, cp3, cp4] = isOutputComplexImpl(~)
            cp1 = false; 
            cp2 = false;
            cp3 = false; 
            cp4 = false;
        end
        
        function [fs1, fs2, fs3, fs4] = isOutputFixedSizeImpl(~)
            fs1 = true; 
            fs2 = true;
            fs3 = true; 
            fs4 = true;
        end

        function [name1, name2, name3, name4] = getOutputNamesImpl(~)
            % This will label the ports on the Simulink block itself
            name1 = 'Gate_States';
            name2 = 'Agg_States';
            name3 = 'Pg';
            name4 = 'Pa';
        end
    end
end