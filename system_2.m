% SUBSYSTEM DESCRIPTION: system_2.m Hysteresis
function[xdot,y] = system_2(x,u,t)
global u_prev;
global state_prev;
global flag_x_y_cal;
% state equation (derivative)
xdot(1) = 0; % no states ---> dummy output
% output equation
% u(1) is current input
ha=0.065;
he=0.085;
if abs(u(1)) <= ha
    y(1)=0;
elseif abs(u(1)) >= he
    if sign(u(1)) > 0
        y(1) = 1;
    else
        y(1) = -1;
    end
elseif u_prev < u(1)
    if sign(u(1)) > 0
        y(1) = 0;
    else
        y(1) = -1;
    end
elseif u_prev > u(1)
    if sign(u(1)) > 0 
        y(1) = 1;
    else
        y(1) = 0;
    end
else
    y(1) = state_prev;
end
if  flag_x_y_cal == 1
    state_prev=y(1);
    u_prev = u(1);
end
