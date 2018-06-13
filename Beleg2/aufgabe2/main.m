i_max = 1; % [A]
K_L = 1; % [A/V]

b1 = 2.39e6; %[Ns/m]
c_oe = 36.5e6; % [N/m]

m_k = 8.7; % [kg]
m_p = 260; %[kg]
c_p = 75e6; %[N/m]
m_g = m_k + m_p;

Ta = 0.015; 

[A,B,C,D] = linmod('Regelstrecke');

FI = expm(A*Ta);
I = diag([1,1,1]);

H = inv(A)*(FI - I)*B;

%x_inf = inv(I-FI)*H*[1];
%y = C*x_inf;

