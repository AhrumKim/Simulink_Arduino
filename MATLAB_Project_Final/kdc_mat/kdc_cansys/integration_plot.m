for i=1:size(AccelForward,1)
    
    subplot(231)
    % Plot a circle.
    angles = linspace(0, 2*pi, 720); % 720 is the total number of points
    radius = 1.5;
    xCenter = 0;
    yCenter = 0;
    x = radius * cos(angles) + xCenter; 
    y = radius * sin(angles) + yCenter;
    % Plot circle.
    plot(x, y, 'b-', 'LineWidth', 1);
    % Plot center.
    hold on;
    plot(xCenter, yCenter, 'k+', 'LineWidth', 2, 'MarkerSize', 16);
    grid on;
    axis equal;
    xlabel('X', 'FontSize', 16);
    ylabel('Y', 'FontSize', 16);
    plot(AccelForward(i), ... 
        AccelLateral(i),'rd')
    xlim([-5 5])
    ylim([-5 5])
    hold off
    drawnow

    subplot(232)
    plot(YAW_RATE(idx_ini:idx_end),'r')
    hold on
    grid on
    plot(i,YAW_RATE(i),'go')
    hold off
    drawnow
end


clear all; close all; clc

load testset3.mat

idx_ini = find(PosLon ~=0, 1 );
idx_end = size(PosLon,1);


for i=idx_ini:10:idx_end
    subplot(2,3,1:2)
    plot(PosLon(idx_ini:idx_end) ...
    ,PosLat(idx_ini:idx_end))
hold on
grid on
    plot(PosLon(i),PosLat(i),'kd')
    hold off
    drawnow

    subplot(2,3,3)
    % Plot a circle.
    angles = linspace(0, 2*pi, 720); % 720 is the total number of points
    radius = 1.5;
    xCenter = 0;
    yCenter = 0;
    x = radius * cos(angles) + xCenter;
    y = radius * sin(angles) + yCenter;
    % Plot circle.
    plot(x, y, 'b-', 'LineWidth', 2);
    % Plot center.
    hold on;
    plot(xCenter, yCenter, 'k+', 'LineWidth', 2, 'MarkerSize', 16);
    grid on;
    axis equal;
    xlabel('X', 'FontSize', 16);
    ylabel('Y', 'FontSize', 16);
    plot(AccelForward(i) ...
        ,AccelLateral(i),'rd')
    xlim([-5 5])
    ylim([-5 5])
    hold off
    drawnow

    subplot(2,2,4)
    plot(YAW_RATE(idx_ini:idx_end),'b')
    hold on;
    plot(i,YAW_RATE(i),'go')
    grid on;
    hold off
    drawnow

end

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
    subplot(233)
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

    subplot(234)
    plot((c0_r+ c0_l)/2)
    hold on
    grid on
    plot(i,(c0_r(i)+ c0_l(i))/2, 'r*')
    hold off
end