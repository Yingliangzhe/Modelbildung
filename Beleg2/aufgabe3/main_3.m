i_max = 1; % [A]
K_L = 1; % [A/V]

Ksv = 0.796; % [m/As]
Fn = 63000; % [N]

b1 = 2.39e6; %[Ns/m]
c_oe = 36.5e6; % [N/m]

m_k = 8.7; % [kg]
m_p = 260; %[kg]
c_p = 75e6; %[N/m]
m_g = m_k + m_p;

Km = 1/Fn; % [V/N]
Ta = 0.015; 

[A,B,C,D] = linmod('Regelstrecke');

FI = expm(A*Ta);
I = diag([1,1,1]);
H = inv(A)*(FI - I)*B;

[Ad,Bd,Cd,Dd] = dlinmod('aufgeschnittenen_Regelkreis',Ta);

figure(1)
dbode(Ad,Bd,Cd,Dd,Ta);
grid on;

figure(2)
sim('geschlossenen_Regelkreis.mdl');
plot(ScopeData.time,ScopeData.signals.values,'k');
grid on;
xlabel('Zeit(s)');
ylabel('F_P(N)');
