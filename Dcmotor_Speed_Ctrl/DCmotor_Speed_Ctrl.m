%%예제 제목
clear

% DC motor
 R = 2; % Ohms
 L = 0.5; % Henrys
 Km = 1; % torque constant
 Kb = 0.1; % back emf constant
 Kf = 0.01; % Nms
 J = 0.02; % kg.m^2/s^2

 Ts = 1e-2;
 num = 2;
 den = [0.05 1];