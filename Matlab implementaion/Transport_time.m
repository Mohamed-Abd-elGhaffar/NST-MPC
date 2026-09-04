function [td, td_dot] = Transport_time(tk,T_s)
        coder.inline('always');
        tk=double(tk);
        T_s=double(T_s);
        persistent tk_prev state T_i T_f td_prev
        if (isempty(tk_prev))
        td_prev=double(0);
        tk_prev=tk;
        state=int8(0);
        T_i=double(1);
        T_f=double(1);
        end
        if (state==0)
                if(abs(tk_prev - tk) == double(0))
                        td=tk;
                        if nargout>1
                        td_dot=double(0);
                        end
                else
                        state=int8(1);
                        T_i=tk_prev;
                        T_f=tk;
                        td=tk_prev+T_s*((1/T_i)-(1/T_f))*T_i;
                        if nargout>1
                        td_dot=double(((1/T_i)-(1/T_f))*T_i);
                        end
                end
        else
                td= td_prev+T_s*((1/T_i)-(1/T_f))*T_i;
                if(abs(T_i-td)>abs(T_i-T_f))
                        td=tk;
                        state=int8(0);
                        if nargout>1
                        td_dot=double(0);
                        end
                end
                if nargout>1
                        td_dot=((1/T_i)-(1/T_f))*T_i;
                end
        end
        td_prev=td;
        tk_prev=tk;
        return;
end