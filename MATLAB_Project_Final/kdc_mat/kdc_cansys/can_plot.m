close all
clc

c0_l = LaneMarkPosition_Lh_ME;
c1_l = LaneMarkHeadAngle_Lh_ME;
c2_l = LaneMarkModelA_Lh_ME;
c3_l = LaneMarkModelDerivA_Lh_ME;
c0_r = LaneMarkPosition_Rh_ME;
c1_r = LaneMarkHeadAngle_Rh_ME;
c2_r = LaneMarkModelA_Rh_ME;
c3_r = LaneMarkModelDerivA_Rh_ME;
%}
x_temp = 0:0.1:60;

for i = 1:10:28000
    subplot(211)
    y_temp_l = c0_l(i)*ones(size(x_temp)) + c1_l(i)*x_temp + c2_l(i)*x_temp.^2 + c3_l(i)*x_temp.^3;

    y_temp_r = c0_r(i)*ones(size(x_temp)) + c1_r(i)*x_temp + c2_r(i)*x_temp.^2 + c3_r(i)*x_temp.^3;

    plot(x_temp, -y_temp_l,'r')
    hold on
    plot(x_temp, -y_temp_r,'b')

    
    hold on
    grid on
    draw_veh(0,0,-pi/2,2,4.5,'r',1);

    xlim([0 20])
    ylim([-10 10])

    hold off
    drawnow

    subplot(212)
    plot((c0_r+ c0_l)/2)
    hold on
    grid on
    plot(i,(c0_r(i)+ c0_l(i))/2, 'r*')
    hold off
end
