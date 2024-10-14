% clc 
% close all
% 
% x_temp = 0:0.1:60;
% for i = 1:30:28000
%     draw_veh(0, 0,-pi/2,2,4.5,'k',1)
%     draw_veh(PosX01(i), PosY01(i), -pi/2, 2, 4.5, 'k', 1);
%     draw_veh(PosX02(i), PosY02(i), -pi/2, 2, 4.5, 'k', 1);
%     draw_veh(PosX03(i), PosY03(i), -pi/2, 2, 4.5, 'k', 1);
%     draw_veh(PosX04(i), PosY04(i), -pi/2, 2, 4.5, 'k', 1);
%     draw_veh(PosX05(i), PosY05(i), -pi/2, 2, 4.5, 'k', 1);
%     draw_veh(PosX06(i), PosY06(i), -pi/2, 2, 4.5, 'k', 1);
%     draw_veh(PosX07(i), PosY07(i), -pi/2, 2, 4.5, 'k', 1);
%     draw_veh(PosX08(i), PosY08(i), -pi/2, 2, 4.5, 'k', 1);
%     plot([0 20],[0 10],'m--')
%     plot([0 20],[0 -10],'m--')
%     c2_radar(i) =YAW_RATE(i)*pi/180/(2*Speed2D(i));
%     y_temp_radar = c2_radar(i)*(x_temp).^2;
%     plot(x_temp, y_temp)
%     xlim([0 60])
%     ylim([-10 10])
%     hold on
%     grid on
% 
%     hold off
%     drawnow
% end


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

% subplot(411)
% plot(c0)
% hold on
% subplot(412)
% plot(c1)
% subplot(413)
% plot(c2)
% subplot(414)
% plot(c3)

x_temp = 0:0.1:60;

for i=1:30:28000
    subplot(211)
    y_temp_l = c0_l(i)*ones(size(x_temp)) ...
    + c1_l(i)*x_temp + ...
    c2_l(i)*x_temp.^2 + c3_l(i)*x_temp.^3;

    y_temp_r = c0_r(i)*ones(size(x_temp)) ...
    + c1_r(i)*x_temp + ...
    c2_r(i)*x_temp.^2 + c3_r(i)*x_temp.^3;

    
    plot(x_temp,-y_temp_l,'r')
    hold on
    grid on
    plot(x_temp,-y_temp_r,'b')

    c2_radar(i) = YAW_RATE(i)*pi/180 / Speed2D(i) / 2;
    y_temp_radar = c2_radar(i)*x_temp.^2;

    draw_veh(0,0,-pi/2,2,4.5,'b',1);
    draw_veh(PosX01(i),PosY01(i),...
    -pi/2,2,4.5,'k',1);
    draw_veh(PosX02(i),PosY02(i),...
    -pi/2,2,4.5,'k',1);
    draw_veh(PosX03(i),PosY03(i),...
    -pi/2,2,4.5,'k',1);
    draw_veh(PosX04(i),PosY04(i),...
    -pi/2,2,4.5,'k',1);
    draw_veh(PosX05(i),PosY05(i),...
    -pi/2,2,4.5,'k',1);
    draw_veh(PosX06(i),PosY06(i),...
    -pi/2,2,4.5,'k',1);
    draw_veh(PosX07(i),PosY07(i),...
    -pi/2,2,4.5,'k',1);
    draw_veh(PosX08(i),PosY08(i),...
    -pi/2,2,4.5,'k',1);

    plot([0 20],[0 10],'m--')
    plot([0 20],[0 -10],'m--')
%     xlim([0 60])
%     ylim([-10 10])
    plot(x_temp,y_temp_radar,'c--')

    xlim([0 60])
    ylim([-10 10])

    hold off
    drawnow

    subplot(212)
    plot((c0_r + c0_l)/2)
    hold on
    grid on
    plot(i,(c0_r(i) + c0_l(i))/2,'r*')  
    hold off
    drawnow
end
% draw_veh(0,0,-pi/2,2,4.4,'r',1);
