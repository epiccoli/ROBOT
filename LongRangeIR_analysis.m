clear all
close all
clc


load('LongRangeIR_data.mat')

Position = Position(2:16);
Analog_avg = Analog_avg(2:16);
Analog_std = Analog_std(2:16);
weights = 1./Analog_std;

[fitresult, gof] = createFit_LongRangeIR(Position, Analog_avg, weights)
% [fitresult, gof] = createFit_LongRangeIR_analog2dist(Analog_avg, Position, weights);
% 
my_coeffs = coeffvalues(fitresult);
a = my_coeffs(1);
b = my_coeffs(2);
% 
% my_confint = confint(fitresult);
% delta_a = (my_confint(2,1) - my_confint(1,1))/2; 
% delta_b = (my_confint(2,2) - my_confint(1,2))/2; 
% 
% Analog_range = max(Analog_avg) - min(Analog_avg);
% 
% analog_read = min(Analog_avg):Analog_range/100:max(Analog_avg);
% distance = a*analog_read.^b;
% 
% delta_x = abs(Analog_avg.^b)*delta_a +...
%     abs(a*b*Analog_avg.^(b-1)).*Analog_std +...
%     abs(a*Analog_avg.^(b).*log(Analog_avg)).*delta_b;
% 
% figure()
% plot(analog_read,distance,'b');
% hold on
% plot(Analog_avg, Position,'r')
% hold on
% plot(Analog_avg, a*Analog_avg.^b + delta_x,'g')
% hold on
% plot(Analog_avg, a*Analog_avg.^b - delta_x,'g')
