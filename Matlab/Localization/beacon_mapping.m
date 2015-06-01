clear all
close all
clc


side_length = 8;

%% Define beacon positions
beacons = [side_length, side_length;...
    0, side_length;...
    0, 0;...
    side_length, 0];

%% Randomly initialize robot state vector
state_vector = [side_length*rand(), side_length*rand(), 2*pi*rand()];

%% Plot beacons and robot
figure()
hold on
plot(beacons(:,1),beacons(:,2),'or','LineWidth',4)
plot(state_vector(:,1),state_vector(:,2),'xk','LineWidth',4)
quiver(state_vector(:,1),state_vector(:,2),cos(state_vector(:,3)),sin(state_vector(:,3)),'k','LineWidth',4)

%% Generate theoretical beacon vectors based on robot current position
color = 'brgm';
vec_theory = zeros(4,2);

for i = 1:4
    
    vec_theory(i,1) = beacons(i,1) - state_vector(1);
    vec_theory(i,2) = beacons(i,2) - state_vector(2);
    mag = sqrt(vec_theory(i,1)*vec_theory(i,1) + vec_theory(i,2)*vec_theory(i,2));
    vec_theory(i,1) = vec_theory(i,1)/mag;
    vec_theory(i,2) = vec_theory(i,2)/mag;
    quiver(state_vector(:,1),state_vector(:,2),vec_theory(i,1),vec_theory(i,2),color(i))
end

%% Generate theoretical beacon vectors in robot referential
vec_theory = ([cos(state_vector(:,3)), sin(state_vector(:,3));-sin(state_vector(:,3)),cos(state_vector(:,3))]*vec_theory')';

figure()
hold on
quiver(0,0,1,0,'k','LineWidth',4)
quiver(0,0,vec_theory(1,1),vec_theory(1,2),color(1))
quiver(0,0,vec_theory(2,1),vec_theory(2,2),color(2))
quiver(0,0,vec_theory(3,1),vec_theory(3,2),color(3))
quiver(0,0,vec_theory(4,1),vec_theory(4,2),color(4))

% angles_theory = atan2(vec_theory(:,2),vec_theory(:,1))*180/pi
% angles_theory = mod(mod(angles_theory,360) + 360, 360)

%% Generate noise to simulate measured beacon vectors

angle_noise_sigma = 2;
angle_measured = -ones(5,1);
vec_measured = zeros(5,2);
oddsNotMeasured = 0.25;
oddsFalse = 0.25;

for ii = 1:size(vec_theory,1)
    
    isMeasured = rand();
    if isMeasured > oddsNotMeasured
        
        angle_noise =  random(makedist('Normal','mu',0,'sigma',angle_noise_sigma/180*pi));
        angle_measured(ii,1) = atan2(vec_theory(ii,2),vec_theory(ii,1)) + angle_noise;
        angle_measured(ii,1) =  mod(mod(angle_measured(ii,1),2*pi) + 2*pi, 2*pi);
        vec_measured(ii,:) = [cos(angle_measured(ii,1)), sin(angle_measured(ii,1))];
        quiver(0,0,vec_measured(ii,1),vec_measured(ii,2),color(ii),'LineStyle','--')
    else
        isFalse = rand();
        if isFalse < oddsFalse
            angle_measured(ii,1) = 2*pi*rand();
            angle_measured(ii,1) =  mod(mod(angle_measured(ii,1),2*pi) + 2*pi, 2*pi);
            vec_measured(ii,:) = [cos(angle_measured(ii,1)),sin(angle_measured(ii,1))];
            quiver(0,0,vec_measured(ii,1),vec_measured(ii,2),'k','LineStyle','--')
        end

    end
    
end

isFalse = rand();
if isFalse < oddsFalse
    angle_measured(5,1) = 2*pi*rand();
    angle_measured(5,1) =  mod(mod(angle_measured(5,1),2*pi) + 2*pi, 2*pi);
    vec_measured(5,:) = [cos(angle_measured(5,1)),sin(angle_measured(5,1))];
    quiver(0,0,vec_measured(5,1),vec_measured(5,2),'k','LineStyle','--')
end

temp_angle_measured = sort(angle_measured(angle_measured >= 0));
nb_measured = length(temp_angle_measured);
angle_measured(1:nb_measured) = temp_angle_measured;
if nb_measured < 5
    angle_measured(nb_measured+1:end) = -ones(1,nb_measured-1);
end

x = state_vector(1)
y = state_vector(2)
theta = state_vector(3)

%% clearing of variables so that we only have the state vector (estimate) and measurement

clear angle_noise angle_noise_sigma color i ii isFalse isMeasured mag nb_measured oddsFalse...
    oddsNotMeasured temp_angle_measured vec_measured vec_theory

%% 



