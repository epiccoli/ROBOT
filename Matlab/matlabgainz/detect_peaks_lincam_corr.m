%% trying out peakdet

clc
clear
close all

% Setting up

gauss = @(x, theta, mu, intensity) intensity*exp(-(x-mu).^2/(2*theta^2));

random = @(MIN, MAX) randi(MAX-MIN, 1)-MIN;

mu = zeros(1, 4);
bad = 1;
while bad > 0
    bad = 0;
    for i = 1:4
        mu(i) = random(1, 612);
    end
    for i = 1:4
        for j = 1:4
            if (j ~= i) && (abs(mu(i) - mu(j)) < 20)
                bad = 1;
            end
        end
    end
end


theta = 2;
intensity = 50+random(0, 30);

x = zeros(1,612);
for i = 1:612
    x(i) = round(50 + random(-10+random(-10, 10), 10+random(-10, 10)) + ...
        gauss(i, theta, mu(1), intensity) + ...
        gauss(i, theta, mu(2), intensity) + ...
        gauss(i, theta, mu(3), intensity) + ...
        gauss(i, theta, mu(4), intensity) + ...
        gauss(i, 100, 300, 120));
end

figure;
subplot 511; hold on;
plot(x);


%% Filtering approach

tic
% Filtering
width = 5;
width_ind = -width:width;
y = zeros(1,612);
for i = 1:612
    indexes = mod(i+width_ind-1,612)+1;
    y(i) = sum([1 3 8 15 21 24 21 15 8 3 1].*x(indexes));
%     y(i) = sum([-29 -22 -9 11 30 38 30 11 -9 -22 -29].*x(indexes));
end
% x=y;
toc

subplot 512; hold on;
plot(y);


%% Correlation

N = length(x);
% High-pass filter
y = [-1 -1 -1 -1 -1 -1 12 -1 -1 -1 -1 -1 -1];
width = 6;

tic
Rhp = zeros(1,N);
for h=1:N
   for k=1:length(y)
        Rhp(h) = Rhp(h) + y(k).*x(mod((k-width-1)+h-1,N)+1);
   end
end
toc
Rhp = floor(Rhp/12);
x = Rhp;

% Convolution with peak shape
N = length(x);
y = gauss(-5:5, theta, 0, 255);
y = round(y/sum(abs(y))*120);
width = 5;

tic
R = zeros(1,N);
for h=1:N
   for k=1:length(y)
        R(h) = R(h) + y(k).*x(mod((k-width-1)+h-1,N)+1);
   end
end
toc

x = R;

subplot 513; hold on;
plot(Rhp);

subplot 514; hold on;
plot(x);

%% Peak detection

delta = 2000;

[maxtab, mintab] = peakdet(x, delta, 1:612);

% Take the FOURST FIR maxima!
i = 0; j = 0;
temp = 0;  % holding variable
numLength = length(maxtab); 
for i = 1:4 % element to be compared
    for j = (i+1):numLength % rest of the elements
        if (maxtab(i,2) < maxtab(j,2)) % descending order
        	temp = maxtab(i,2); % swap
            maxtab(i,2) = maxtab(j,2);
            maxtab(j,2) = temp;
            temp = maxtab(i,1);
            maxtab(i,1) = maxtab(j,1);
            maxtab(j,1) = temp;
        end
    end
end

subplot 515; hold on;
plot(x);
plot(maxtab(:,1), maxtab(:,2), 'or', 'MarkerSize', 9);
plot(maxtab(1:4,1), maxtab(1:4,2), 'ok', 'MarkerSize', 9);










