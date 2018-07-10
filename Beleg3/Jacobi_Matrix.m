function [J] = Jacobi_Matrix ()

global C1;
global C2;
global R;
global h;
J = [1  0 -h/(2*C1)   0     0  0 ;
     0  1     0   -h/(2*C2) 0  0 ;
     1  0     0       0     1  0 ;
    -1  1     0       0     0  0 ;
     0  0     1       1     0  -1;
     0  0     0       0     -1 R];
end