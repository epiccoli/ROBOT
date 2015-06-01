%% trying out peakdet

clc
clear
close all

% Setting up

gauss = @(x, theta, mu, intensity) intensity*exp(-(x-mu)^2/(2*theta^2));

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


theta = 5;
intensity = 30+random(0, 30);

x = zeros(1,612);
for i = 1:612
    x(i) = round(210 + random(-10+random(-10, 10), 10+random(-10, 10)) + ...
        gauss(i, theta, mu(1), intensity) + ...
        gauss(i, theta, mu(2), intensity) + ...
        gauss(i, theta, mu(3), intensity) + ...
        gauss(i, theta, mu(4), intensity));
end


figure; hold on;
subplot 211
plot(x)

% Filtering
width = 2;
width_ind = -width:width;
y = zeros(1,612);
for i = 1:612
    indexes = mod(i+width_ind-1,612)+1;
    y(i) = sum([1 2 3 2 1].*x(indexes))/9;
end
x=y;

subplot 212
plot(x); hold on;

%% Peak detection
delta = 20;

plot(x, 'b'); hold on;
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

plot(maxtab(:,1), maxtab(:,2), 'or', 'MarkerSize', 9);
plot(maxtab(1:4,1), maxtab(1:4,2), 'ok', 'MarkerSize', 9);










