clear all;
%close all;

distance_per_step = 0.003;

vy= distance_per_step / sqrt(2) * 0
vx= distance_per_step / sqrt(2) * 50
z= -0.8;
foot_pos_x = [-0.25, 0, 0.25, -0.25, 0, 0.25];
foot_pos_y = [-0.23, -0.308, -0.23, 0.23, 0.308, 0.23];

if z == 0
   vxn = vx
   vyn = vy
else 
  if (vy == 0) && (vx == 0)
    x0 = 0;
    y0 = 0;
  else
    x0 = -vy / sqrt((vy ** 2) + (vx ** 2)) * sign(z) * (5/(e^(abs(z))) - 5.51)
    y0 = vx / sqrt((vy ** 2) + (vx ** 2))  * sign(z) * (5/(e^(abs(z))) - 5.51)
  endif

  rho0 = sqrt((x0) ** 2 + (y0) ** 2)
  
  if (-x0) < 0
    phi0 = pi - asin((-y0)/rho0)
  else
    phi0 = asin((-y0)/rho0)
  endif
    

  for index = 1:6
    rho(index) = sqrt((foot_pos_x(index) - x0) ** 2 + (foot_pos_y(index) - y0) ** 2);

    if (foot_pos_x(index) - x0) < 0
      phi(index) = pi - asin((foot_pos_y(index) - y0)/rho(index));
    else
      phi(index) = asin((foot_pos_y(index) - y0)/rho(index));
    endif
  endfor
    
  dphi = sign(z) * atan(sqrt(vx ** 2 + vy ** 2) / max(rho))

  for index = 1:6

    x_new = rho(index) * cos(phi(index) + dphi);
    y_new = rho(index) * sin(phi(index) + dphi);

    vxn(index) = x_new + x0;
    vyn(index) = y_new + y0;
    dist = dphi * rho(index)
  endfor
endif



figure
hold on;
axis("equal")
plot(x0, y0, 'ro' , "linewidth" , 2)
plot(0, 0, 'r*', "linewidth" , 2)
plot(0 + vx, 0 + vy, 'g*', "linewidth" , 2)

for index = 1:6
  plot(foot_pos_x(index), foot_pos_y(index), 'k*', "linewidth" , 2)
  plot(0 + vxn(index), 0 + vyn(index), 'b*', "linewidth" , 2)
endfor

plot([x0, 0], [y0, 0])
plot([0, 0 + vx], [0, 0 + vy])
plot([x0, 0 + vx], [y0, 0 + vy])

t = linspace(phi0, phi0 + dphi, 100)'; 
circsx = rho0.*cos(t) + x0; 
circsy = rho0.*sin(t) + y0; 
plot(circsx,circsy, 'b'); 