clear all
close all
clc

load('ir_data.mat')

figure, hold on
errorbar(long_range(:,1),long_range(:,2),long_range(:,3),'-b','LineWidth',2);
errorbar(short_range(:,1),short_range(:,2),short_range(:,3),'-r','LineWidth',2);
xlabel('Obstacle position [cm]')
ylabel('Analog signal (a.u.)')
legend('Long-range IR', 'Short-range IR')
