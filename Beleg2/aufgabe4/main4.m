clear all

Fn = 63000; % [N]

b1 = 2.39e6; %[Ns/m]
c_oe = 36.5e6; % [N/m]

m_k = 8.7; % [kg]
m_p = 260; %[kg]
c_p = 75e6; %[N/m]
m_g = m_k + m_p;

Ta = 0.015; 
KI = 0.0000043;
Km = 1/Fn; % [V/N]



[A,B,C,D] = linmod('Regelstrecke');

FI = expm(A*Ta);
I = diag([1,1,1]);
H = inv(A)*(FI - I)*B;

[Ad,Bd,Cd,Dd] = dlinmod('aufgeschnittenen_Regelkreis',Ta);


[num,den] = ss2tf(A,B,C,D);
G = tf(num,den,Ta)
dbode(Ad,Bd,Cd,Dd,Ta);
grid on

