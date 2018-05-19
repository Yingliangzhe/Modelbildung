% MODSIM Laborpraktikum, 1. Aufgabe
% Prof. K. Janschek, Dr.-Ing. Th. Range, Dr.-Ing. S. Dyblenko
%
% main_a1.m - Realisierung der VPG-Methode mit Fehlersch?tzung
% f¨¹r PT1-Glied
% zu erg?nzende Codezeilen sind mit ">>> erg?nzen ...." und ...¡°gekennzeichnet
clear all % L?sche Arbeitsspeicher
Tm = 10; % Konstante des PT1, [s]
h = 0.1; % Schrittweite, (s)
h_neu = 0.3; % neue Schrittweite
h_alt = 0.1; % alte Schrittweite
e_LDF = 10e-6; % 
t0 = 0; % Integrationsbeginn, [s]
tf = 300; % Integrationsende, [s]
t = []; % Zeitwerte f¨¹r Plot [s]
d = []; % Fehler-Sch?tzwerte
u = []; % Stellwerte u(t)
y = []; % Ausgangswerte y(t)
ys = []; % Soll-Ausgangswerte y_soll(t)
% Initialisierung
[dum,x(1)] = system_pt1([],[],[],0);
d(1) = 0;
% Integration nach VPG-Methode
ti = t0;
i = 1;
d_dach(1)=0;
ys(1)=0; %erganzen 
%h_min und h_max berechnen
h_max = 2*Tm;
b0_u0=5*1/Tm*exp(-0/Tm);
h_min=6/abs(b0_u0)*(e_LDF);
h_alt = h;
false = 0;
true = 1;
flag = false;
h_test(1)=0;
while ti <= tf
    while flag == false
    % Berechnung der gesch?tzte lokaler Fehler
    % d_dach = h^2/2*max(x''(t)),t belongs to (ti, ti+1)
        if (ti+h)>=0 && (ti+h)<1
             d_dach(i+1) = 0; 
        elseif (ti+h)>= 1
            d_dach(i+1)=h^2/2*(-5*((ti+h-1)/Tm)^2*exp((-ti+h-1)/Tm)); %>>> erg?nzen ....
        end


        % Berechnung des Soll-Ausgangswertes
        h_neu = h_alt*(e_LDF/abs(d_dach(i+1)))^(1/3);
        if (h_neu >= h_max) || (h_neu <= h_min)
            if h_neu >= h_max 
                h_neu = h_max;
                flag = true;
            else  
                h_neu = h_min;
                flag = true;
            end
        elseif h_neu > 2*h_alt
            h=h_neu;
            flag = true;
        elseif h_neu <= h_alt
             h = 0.75*h_neu;
             flag = false;
             continue
        else
            flag = true;
        end

        % Berechnung des Stellwertes
        if ti>=0 && ti<1
         u(i)=0;
        elseif ti >= 1
         u(i) = 5;%>>> erg?nzen ....
        end

        if (ti+h)>=0 && (ti+h)<1
            ys(i+1) = 0; 
        elseif (ti+h)>= 1
            ys(i+1)= 5*(1-exp(-(ti+h-1)/Tm)); %>>> erg?nzen ....
        end

        % Berechnung des Ausgangswertes
        y(i) = system_pt1( ti , x(i) , u(i) , 3); %die Parameter einsetzen
        % Berechnung der Koeffizienten f¨¹r VPG-Methode
        k1 = system_pt1( ti ,  x(i) , u(i) , 1); %die Parameter einsetzen
        k2 = system_pt1( ti+h/2 ,  x(i)+h/2*k1 , u(i) , 1); %die Parameter einsetzen
        k3 = system_pt1(  ti+h ,  x(i)-h*k1+2*h*k2 , u(i) , 1); %die Parameter einsetzen,to be changed.
        % Wichtiger Hinweis: Die Parameter bei den Aufrufen von system_pt1(...)
        % m¨¹ssen unter Beachtung von jeweiligen Zeitpunkten bestimmt werden!
        % Berechnung des Zustands-Sch?tzwertes x(ti+h)
        x(i+1) =x(i)+h*k2; %>>> erg?nzen ....




        % Berechnung der LDF Fehlerabsch?tzung d(ti+h)
        d(i+1) =ys(i+1)-ys(i)-h*k3; %>>> erg?nzen ....
    end
    t(i) = ti; % Zeitwert f¨¹r Plot speichern
    ti = ti + h; % Zeitvariable um einen Schritt erh?hen
    i = i + 1; % Index inkrementieren
    h_alt = h;
    h_test(i+1)=h;
    flag = false;% sprungen in sub-schleife
end
%%selbst hinzugefuegt
ys(end)=[];
d = d(1:end-1); %-1
result = [t;d];
% Anzeige der Ergebnisse
figure(1);
subplot(2,1,1); plot(t,u); title('Eingang PT1-Glied');zoom on;grid on;
subplot(2,1,2); plot(t,y); title('Ausgang PT1-Glied');zoom on;grid on;
xlabel('Zeit, s');
figure(2);
subplot(2,1,1); plot(t,y-ys,'.-'); title('GDF berechnet');zoom on;grid on;
tit=sprintf('LDF gesch?tzt: max. Betrag = %g',max(abs(d)));
subplot(2,1,2); plot(t,d,'.-'); title(tit);zoom on;grid on;
xlabel('Zeit, s');
h_test(end)=[];h_test(end-1)=[];
figure(3);
plot(t,h_test);