function [T] = DAE_Modell(pn_1,u)
%Modellkonstanten
global C1;
global C2;
global R;
global h;

x1 = pn_1(1);
x2 = pn_1(2);
z1 = pn_1(3);
z2 = pn_1(4);
z3 = pn_1(5);
z4 = pn_1(6);

f1 = z1/C1;
f2 = z2/C2;

g1 = z3 + x1 - u;
g2 = x2 - x1;
g3 = -z4 +z1 + z2;
g4 = -z3 + R*z4;

T = [f1;f2;g1;g2;g3;g4];%Temporary
end