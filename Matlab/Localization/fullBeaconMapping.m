clear all
close all
clc

vec_beacons = [0 1 2 3];
vec_meas = [0 1 2 3 4];
c = 0;

for l2 = 1:5
    for l = 1:4
        c = c+1;
        for k = 1:4
%             mod((l2-1 + k-1),5) + 1
%             mod((l2-1 + l-1),5) + 1
            
            if mod((l2-1 + k-1),5) + 1 ~= mod((l2-1 + l-1),5) + 1
                temp(c, k) = vec_meas(mod((l2-1 + k-1),5) + 1);
            else
                temp(c, k) = -1;
            end
        end
    end
end

temp


for l2 = 1:5
    for l = 1:5
        c = c+1;
        for k = 1:5            
            if (l2 ~= l && k ~= l && k ~= l2)
                temp2(c, k) = vec_meas(k);
            else
                temp2(c, k) = -1;
            end
        end
    end
end

temp2


