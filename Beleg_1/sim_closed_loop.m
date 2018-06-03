% MAIN SIMULATION PROGRAM: sim_closed_loop.m

% system parameter
clear all;
model_name = 'sys_pt2_cl';
u = 0;                  % input modeled in the topology file!
global u_prev;
global state_prev;
global u_2;
global flag_x_y_cal;
state_prev=0;
u_prev = 0;
global m ;
m =1;
Tm = 10; % Konstante des PT1, [s]
%simulation parameter
t  = 0;                 % simulation start time
tf = 20;                 % simulation stop time
h  = 2e-3;              % constant stepsize
ts = 1;                 % step time
ha=0.065;
he=0.085;
u_2 =  [0.17 -0.25 0.49]; % need to be modified [0.17 -0.25 0.49]
d_dach = 0;
e_LDF = 10e-5; % 
% initial values
x = [0 0];              % x ... system state vector
y_values_1 = [];
%%
for m = 1:1:3
tau_e = -Tm*log(1-(he - ha)/(1 + he - abs(u_2(m))));
tau_p = Tm*(log((1-ha/abs(u_2(m)))/(1-he/abs(u_2(m))))-log(1-(he - ha)/(1 + he - abs(u_2(m)))));

b0_u0=u_2(m)*1/Tm;
h_min=6/abs(b0_u0)*(e_LDF);
%h_min=1e-5;
%h_max=1e-2;
h_max = Tm; %2/(2/Tm)

h_alt = h;
false = 0;
true = 1;
flag = false;
% simulation
i=1;
t = 0;
while t <= tf         %   loop t = t0...tf
    
    while flag == false
        flag_x_y_cal = false;
        [x_dumm,y_dumm,d_dach] = VPG(model_name,x,u,t,h); %VPG einsetzen
        %y(2) ist Ausgang des 2.Systemes, mit dem kann abgeschaetzter Fehler
        % d_dach under 3 Situations. 1. e=0   2. e=1   3.e=-1
        %[d_dach] = LDF_ABGESCHAETZT(y_dumm,t,h);
        
        h_neu = h*(e_LDF/abs(d_dach(2)))^(1/3);
        if (h_neu >= h_max) || (h_neu < h_min)
            if h_neu >= h_max 
                h_neu = h_max;
                h=h_neu;
                flag = true;
            else  
                h_neu = h_min;
                h=h_neu;
                flag = true;
            end
        elseif h_neu > 2*h_alt
            h=h_neu;
            flag = true;
        elseif h_neu <= h_alt
             h = 0.75*h_neu;
             h_alt=h;
             flag = false;
             continue
        else
            h=h_neu;
            flag = true;
        end
        %}
        flag_x_y_cal = true;
        [x,y,d_dach] = VPG(model_name,x,u,t,h); 
        % save the calculated values accoeding to pointer m
        if m == 1
            x_values_1(i,:) = x;
            y_values_1(i,:) = y;
            t_values_1(i)  = t;
            h_test_1(i) = h;
            d_test_1(i) = d_dach(2);
        elseif m == 2 
            x_values_2(i,:) = x;
            y_values_2(i,:) = y;
            t_values_2(i)  = t;
            h_test_2(i) = h;
            d_test_2(i) = d_dach(2);
        else 
            x_values_3(i,:) = x;
            y_values_3(i,:) = y;
            t_values_3(i)  = t;
            h_test_3(i) = h;
            d_test_3(i) = d_dach(2);
        end
        %y_exact(i)    = 29/49*(1-exp(-3.5*(t-ts))*...
                           %(cos(3.5*(t-ts))+sin(3.5*(t-ts))))*(t>ts);


        %start to compute the "abgeschatzter LDF" and the step length 
        
        
        %test with constant step size
        %x_values(i,:) = x;
        %y_values(i,:) = y;
        %t_values(i)   = t;        
        
    end 
    t = t + h;
    i = i+1;
    h_alt = h;

    flag = false;
 end % while
end


%% result visualisation  
figure(1);
subplot(3,3,1);
co = plot(t_values_1(1,:),y_values_1(:,1), 'g-');
title({'bei u2 = 0.17';'Systemausgang 1'});grid on; zoom on;
xlabel('Zeit, s');
%,t_values,y_exact,...t_values,y_values(:,3)-y_exact'

subplot(3,3,4);
plot(t_values_1(1,:),y_values_1(:,2),'b-');
title('Systemausgang 2');grid on; zoom on;
xlabel('Zeit, s');

subplot(3,3,7);
plot(t_values_1(1,:),y_values_1(:,3),'r-');
title('Systemausgang 3');grid on; zoom on;
xlabel('Zeit, s');
% 
% figure(1);
% subplot(5,1,2);
% plot(t_values(1,:),h_test(1,:),'r.');
% title('Ausgang System 3');grid on; zoom on;
% xlabel('Zeit, s');
% 
% 
% figure(1);
% subplot(5,2,2);
% plot(t_values(1,:),d_test(1,:),'r.');
% title('Ausgang System 3');grid on; zoom on;
% xlabel('Zeit, s');

subplot(3,3,2);
co = plot(t_values_2(1,:),y_values_2(:,1), 'g-');
title({'bei u2 = -0.25';'Systemausgang 1'});grid on; zoom on;
xlabel('Zeit, s');

subplot(3,3,5);
plot(t_values_2(1,:),y_values_2(:,2),'b-');
title('Systemausgang 2');grid on; zoom on;
xlabel('Zeit, s');

subplot(3,3,8);
plot(t_values_2(1,:),y_values_2(:,3),'r-');
title('Systemausgang 3');grid on; zoom on;
xlabel('Zeit, s');

subplot(3,3,3);
co = plot(t_values_3(1,:),y_values_3(:,1), 'g-');
title({'bei u2 = 0.49';'Systemausgang 1'});grid on; zoom on;
xlabel('Zeit, s');
%,t_values,y_exact,...t_values,y_values(:,3)-y_exact'

subplot(3,3,6);
plot(t_values_3(1,:),y_values_3(:,2),'b-');
title('Systemausgang 2');grid on; zoom on;
xlabel('Zeit, s');

subplot(3,3,9);
plot(t_values_3(1,:),y_values_3(:,3),'r-');
title('Systemausgang 3');grid on; zoom on;
xlabel('Zeit, s');
suptitle('Systemausgang mit Schrittweitesteuerung');

%% step size visualisation  
figure(2)
subplot(3,1,1);
plot(t_values_1(1,:),h_test_1(1,:),'g-');
title(' bei u2 = 0.17');grid on; zoom on;
xlabel('Zeit, s');

subplot(3,1,2);
plot(t_values_2(1,:),h_test_2(1,:),'b-');
title(' bei u2 = -0.25');grid on; zoom on;
xlabel('Zeit, s');

subplot(3,1,3);
plot(t_values_3(1,:),h_test_3(1,:),'r-');
title(' bei u2 = 0.49');grid on; zoom on;
xlabel('Zeit, s');
suptitle('Schrittweite mit Schrittweitesteuerung')

%% Geschaetzte Lokale Distisierungsfehler
figure(3)
subplot(3,1,1);
plot(t_values_1(1,:),d_test_1(1,:),'g-');
title(' bei u2 = 0.17');grid on; zoom on;
xlabel('Zeit, s');

subplot(3,1,2);
plot(t_values_2(1,:),d_test_2(1,:),'b-');
title(' bei u2 = -0.25');grid on; zoom on;
xlabel('Zeit, s');

subplot(3,1,3);
plot(t_values_3(1,:),d_test_3(1,:),'r-');
title(' bei u2 = 0.49');grid on; zoom on;
xlabel('Zeit, s');
suptitle('Geschaetzte LDF mit Schrittweitesteuerung')



