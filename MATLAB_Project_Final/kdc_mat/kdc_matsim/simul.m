Vs = input('Please enter the source voltage\n');
Rn = input('Please enter the value of th4e resistors as elements in a row vector\n');
Req = 0;
for k = Rn
    Req = Req+k;
end
disp('');
disp('Resistance    Voltage     Power');
disp('   (Ohms)     (Volts)     (Watts)');
for x = Rn
    Vn = x/Req*Vs;
    Pn = x/(Req)^2*(Vs)^2;
    fprintf("%10.4f %10.4f  %10.4f\n",x, Vn, Pn);
end