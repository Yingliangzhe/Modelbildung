% STANDARD VPG: VPG.m

function [x_VPG,y] = VPG(model_name,x,u,t,h)

% derivatives @ t, t+h/2, t+h
[k1, y]   = feval(model_name, x,        t     );
[k2, dum] = feval(model_name, x+h/2*k1, t+h/2 );
%[k3, dum] = feval(model_name, x-h*k1+2*h*k2 , t+h );


% RK4 integration step
x_VPG = x + h*k2;