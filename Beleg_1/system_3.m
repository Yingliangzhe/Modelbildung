% SUBSYSTEM DESCRIPTION: system_3.m

function  [xdot,y] = system_3(x,u,t)

% state equation (derivative)
xdot(1) = -1/10*x(1) + 1/10*u(1);

% output equation    
y(1) = x(1);