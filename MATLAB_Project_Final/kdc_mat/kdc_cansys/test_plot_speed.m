plot(WHL_SPD_FR)
hold on
grid on
plot(WHL_SPD_FL,'r--')
plot(WHL_SPD_RR,'b--')
plot(WHL_SPD_RL,'k--')
plot(Speed2D*3.6,'m--')
legend("FR","FL", "RR", "RL", "GPS")