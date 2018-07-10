function [phi] = Gl_sys (pn_1, pn_0,u)

%Trapezmethode
global C1;
global C2;
global R;
global h;

%    pn_0= [x1(i);x2(i);z1(i);z2(i);z3(i);z4(i)];

T = single(DAE_Modell(pn_1,u));

phi1 = pn_1(1) - pn_0(1) -(h/2)*((pn_0(3)/C1)+T(1)); % T(1) ist z1(i+1)/c1  8-10
phi2 = pn_1(2) - pn_0(2) -(h/2)*((pn_0(4)/C2)+T(2)); % ...z2(i+1)/c2
phi3 = T(3);
phi4 = T(4);
phi5 = T(5);
phi6 = T(6);
phi = [phi1;phi2;phi3;phi4;phi5;phi6];

end