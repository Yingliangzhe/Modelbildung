b1 = 2.39e6; %[Ns/m]
c_oe = 36.5e6; % [N/m]

m_k = 8.7; % [kg]
m_p = 260; %[kg]
c_p = 75e6; %[N/m]
m_g = m_k + m_p;

Ta = 0.015; 
syms s;

[A,B,C,D] = linmod('Regelstrecke');
%[num,den] = ss2tf(A,B,C,D);
%G = tf(num,den);


FI = expm(A*Ta);
I = diag([1,1,1]);
%FI = ilaplace(inv(s*I-A));

H = inv(A)*(FI - I)*B;

x_inf = inv(I-FI)*H*[1];
y = C*x_inf;

