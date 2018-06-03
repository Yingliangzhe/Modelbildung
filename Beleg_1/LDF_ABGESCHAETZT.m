function [d_dach] = LDF_ABGESCHAETZT(y,t,h)

Tm = 10;
global u_2;
%situation 1: e=0, x(t)''= 0
if y(2) == 0
    d_dach=0;
%situation 2: e=1, x(t)'''=-8/(Tm^4)*exp(-2/Tm*t)
% d_dach = h^2/2*max(x'''(t)),t belongs to (ti, ti+1)
elseif y(2) ==1
    x_3_ableitung=u_2*8/(Tm^4)*exp(-2/Tm*t);
    d_dach = h^3/6*x_3_ableitung; % luckily the maximal di+1(tao) shows up at the very begin of this sample.
    
elseif y(2) ==-1
    d_dach = 0;
else
    error('output of system 2 is not any of the feasible values.');
end    
