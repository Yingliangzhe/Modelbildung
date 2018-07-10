clear all;
global R ;
R = single(100);
global C1 ;
C1 = single(0.01);
global C2 ;
C2 = single(0.02);

global h;
h = single(2e-1);
t0 = single(0);
tf = single(60);

ti = t0;
e =single( 1e-5);  %8-10 
us_const=single(10);
t = [];
u = [];
x1 = [];
x2 = [];
z1 =[];
z2 =[];
z3 =[];
z4 =[];

%Initialieren mit den Anfangswerten
u(1) = single(us_const);
x1(1) =single( 0);
x2(1) = single(0);
z1(1) =single(1/30);
z2(1) =single(1/15);
z3(1) =single(us_const);
z4(1) =single(0.1);
pn_0= [x1(1);x2(1);z1(1);z2(1);z3(1);z4(1)];
J = Jacobi_Matrix();

i = 1;
while ti <= tf
    
    if ti >= t0
       u(i) = single(10);
    else 
       u(i) =single(0);
    end
    x1_soll(i)=u(i)*(1-exp(-(ti/(R*(C1+C2)))));

    %Newton-Raphson-Verfahren  8-10

    pn_1= [x1(i);x2(i);z1(i);z2(i);z3(i);z4(i)];
    pn_0= [x1(i);x2(i);z1(i);z2(i);z3(i);z4(i)];
    %pn_1_old=pn_1;
    repeat = 1;
    n=1;%Konvergenzverhalten
    
    while repeat == 1
        
   %     PHI = Gl_sys(pn_1,x1(i),x2(i),z1(i),z2(i),h,u(i));
        PHI = Gl_sys(pn_1,pn_0,u(i));
        Jinv = inv(J);
        pn1_new = pn_1 -(Jinv*PHI); %p(n+1) Skript 8-10
        ep = norm(pn1_new - pn_1); 
        n = n + 1;
        %pn_0 = pn_1;

        if ep <= e 
            repeat = 0;
        end
        pn_1=pn1_new;        

    end
   % pn_0=pn_1_old;
%Differenz zwischen Sollwert und Realwert
d(i) = x1_soll(i) - x1(i);

%Werte erneuen
x1(i+1) = pn_1(1);
x2(i+1) = pn_1(2);
z1(i+1) = pn_1(3);
z2(i+1) = pn_1(4);
z3(i+1) = pn_1(5);
z4(i+1) = pn_1(6);


t(i) = ti; 
ti = ti + h; 
i = i + 1; 
end


figure(1);
plot(t,x1_soll,t, u); 
title('Eingangsgroesse und Sollverlauf von u2');
zoom on;grid on;
xlabel('Zeit(s)');
ylabel('Spannung(V)');
h = legend('u_soll', 'us(t)');
set(h,'Interpreter', 'none');

figure(2);
subplot(2,1,1);plot(t,x1(2:i)); title('Spannung von C1');
zoom on;grid on;
subplot(2,1,2);plot(t,x2(2:i)); title('Spannung von C2');
zoom on;grid on;
xlabel('Zeit(s)');
ylabel('Spannung(V)');

figure(3);
plot(t,d); title('Differenz');
zoom on;grid on;
xlabel('Zeit(s)');
ylabel('Differenz(V)');
