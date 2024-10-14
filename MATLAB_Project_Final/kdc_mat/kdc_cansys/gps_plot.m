clear all
close all
clc

load testset3.mat

idx_ini = min(find(PosLon~=0));
idx_end = size(PosLon,1);
for i=idx_ini:10:idx_end
    plot(PosLon(idx_ini:idx_end) ...
    ,PosLat(idx_ini:idx_end))
    hold on
    grid on
    plot(PosLon(i),PosLat(i),'kd')

    hold off
    drawnow
end

% Plot a circle.
angles = linspace(0, 2*pi, 720); % 720 is the total number of points
radius = 20;
xCenter = 50;
yCenter = 40;
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
