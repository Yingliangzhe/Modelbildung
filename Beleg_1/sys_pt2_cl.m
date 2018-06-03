% TOPOLOGY DESCRIPTION: sys_pt2_cl.m

%  input:  	x    ... system state vector @ t
%  	     	t    ... current time 
%  output: 	xdot ... system state vector derivative @ t 
%          	y    ... subsystem outputs @ t
%angenommen: Der Ausgang von system 2 ist Zustand X1, und der Ausgang von
%System 3 ist X2.
%Eingang des 2.Systemes ist die Regeldifferenz, so gennant, Ausgang von
%System 1 (y(1)).

function [xdot,y] = sys_pt2_cl(x,t)

% u_2 = u_2(t) modeled as internal part of the system
%u_2 = 0.17; % need to be modified
global u_2;
global m;
% system_3 ---> START Block
% REM: xdot ="dumx" is obsolete, input u3 not yet known! 
[dumx,y3] = system_3(x(2),0,t);

% system_1   
u1(1) = u_2(m);
u1(2) = y3;
[dumx,y(1)] = system_1(0,u1,t);   % no states!

% system_2
u2(1) = y(1);
[xdot(1),y(2)] = system_2(x(1),u2,t);

% system_3    REM: Now xdot is correct because the input is known!
u3(1) = y(2);
[xdot(2),y(3)] = system_3(x(2),u3,t);