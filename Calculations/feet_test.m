alpha = 0
beta = 0
gamma = -90
roll = 0 % rotation clockwise
pitch = 0
yaw = 0

Coxa2CenterX = [-0.120, 0.0, 0.120, -0.120, 0.0, 0.120];
Coxa2CenterX *= 1000;
Coxa2CenterY = [-0.055, -0.090, -0.055, 0.055, 0.090, 0.055];
Coxa2CenterY *= 1000;
INIT_COXA_ANGLE = [-60.0, 0.0, 60.0, -60.0, 0.0, 60.0];
INIT_COXA_ANGLE = INIT_COXA_ANGLE.*(pi/180);

coxa = 83;
femur = 100;
tibia = 161.8;

bodyz = 0;


tx = roll*pi/180;
ty = pitch*pi/180;
tz = yaw*pi/180;
body_roll = 0;
body_pitch = 0;

g = -alpha*pi/180 .- INIT_COXA_ANGLE;
a = body_roll + sign(Coxa2CenterY).*beta*pi/180;
b = a+sign(Coxa2CenterY).*gamma*pi/180;


px0 = 0;
px1 = px0 + cos(body_pitch).*Coxa2CenterX;
px2 = px1 - sin(g).*cos(body_roll)*coxa;
px3 = px2 - sin(g).*cos(a)*femur;
px4 = px3 - sin(g).*cos(b)*tibia;

py0 = 0;
py1 = py0 + cos(body_roll).*Coxa2CenterY; 
py2 = py1 + cos(g).*sign(Coxa2CenterY).*cos(body_roll)*coxa;
py3 = py2 + cos(g).*sign(Coxa2CenterY).*cos(a)*femur;
py4 = py3 + cos(g).*sign(Coxa2CenterY).*cos(b)*tibia;

pz0 = 0;
pz1 = pz0 + sin(body_roll).*Coxa2CenterY + sin(body_pitch).*Coxa2CenterX;
pz2 = pz1 + sign(Coxa2CenterY).*sin(body_roll)*coxa;
pz3 = pz2 + sign(Coxa2CenterY).*sin(a)*femur;
pz4 = pz3 + sign(Coxa2CenterY).*sin(b)*tibia;


Rx = [1 0 0; 0 cos(tx) -sin(tx); 0 sin(tx) cos(tx)];
Ry = [cos(ty) 0 sin(ty); 0 1 0; -sin(ty) 0 cos(ty)];
Rz = [cos(tz) -sin(tz) 0; sin(tz) cos(tz) 0; 0 0 1];
Rot = Rx * Ry * Rz;

px1_ = transpose(transpose( Rot * [px1;py1;pz1]) * [1;0;0]);
py1_ = transpose(transpose( Rot * [px1;py1;pz1]) * [0;1;0]);
pz1_ = transpose(transpose( Rot * [px1;py1;pz1]) * [0;0;1]);
px2_ = transpose(transpose( Rot * [px2;py2;pz2]) * [1;0;0]);
py2_ = transpose(transpose( Rot * [px2;py2;pz2]) * [0;1;0]);
pz2_ = transpose(transpose( Rot * [px2;py2;pz2]) * [0;0;1]);
px3_ = transpose(transpose( Rot * [px3;py3;pz3]) * [1;0;0]);
py3_ = transpose(transpose( Rot * [px3;py3;pz3]) * [0;1;0]);
pz3_ = transpose(transpose( Rot * [px3;py3;pz3]) * [0;0;1]);
px4_ = transpose(transpose( Rot * [px4;py4;pz4]) * [1;0;0]);
py4_ = transpose(transpose( Rot * [px4;py4;pz4]) * [0;1;0]);
pz4_ = transpose(transpose( Rot * [px4;py4;pz4]) * [0;0;1]);

px1 = px1_;
py1 = py1_;
pz1 = pz1_+bodyz;
px2 = px2_;
py2 = py2_;
pz2 = pz2_+bodyz;
px3 = px3_;
py3 = py3_;
pz3 = pz3_+bodyz;
px4 = px4_;
py4 = py4_;
pz4 = pz4_+bodyz;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Plot
close all;
figure;
hold on;
plot3([px1(1), px1(2)], [py1(1), py1(2)],[pz1(1), pz1(2)],'b','LineWidth',1)
plot3([px1(2), px1(3)], [py1(2), py1(3)],[pz1(2), pz1(3)],'b','LineWidth',1)
plot3([px1(3), px1(6)], [py1(3), py1(6)],[pz1(3), pz1(6)],'r','LineWidth',1)
plot3([px1(4), px1(5)], [py1(4), py1(5)],[pz1(4), pz1(5)],'b','LineWidth',1)
plot3([px1(5), px1(6)], [py1(5), py1(6)],[pz1(5), pz1(6)],'b','LineWidth',1)
plot3([px1(1), px1(4)], [py1(1), py1(4)],[pz1(1), pz1(4)],'b','LineWidth',1)

for x = 1:6
  plot3([px1(x),px2(x)],[py1(x), py2(x)],[pz1(x), pz2(x)], 'g','LineWidth',1)
  plot3([px2(x),px3(x)],[py2(x), py3(x)],[pz2(x), pz3(x)], 'b','LineWidth',1)
  plot3([px3(x),px4(x)],[py3(x), py4(x)],[pz3(x), pz4(x)], 'k','LineWidth',1)
  
  % sanity checks
  if abs(coxa - norm([px1(x)- px2(x), py1(x) - py2(x), pz1(x) - pz2(x)])) > 0.00001
    disp("Error, coxa length does not match")
  end
  if abs(femur - norm([px2(x)- px3(x), py2(x) - py3(x), pz2(x) - pz3(x)])) > 0.00001
    disp("Error, femur length does not match")
  end
  if abs(tibia - norm([px3(x)- px4(x), py3(x) - py4(x), pz3(x) - pz4(x)])) > 0.00001
    disp("Error, tibia does not match")
  end
end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% sanity checks
aa = [px1(x), py1(x), pz1(x)];
bb = [px2(x), py2(x), pz2(x)];
cc = [px3(x), py3(x), pz3(x)];
dd = [px4(x), py4(x), pz4(x)];

S1 = bb - aa;
S2 = cc - bb;
S3 = dd - cc;

% angle between coxa and femur
angle1 = atan2(norm(cross(S1, S2)), dot(S1, S2)) / pi * 180

% angle between femur and tibia
angle2 = atan2(norm(cross(S2, S3)), dot(S2, S3)) / pi * 180



%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Output for CPP code
px4_out = px4./1000;
py4_out = py4./1000;
pz4_out = pz4./1000;
tempx = [sprintf("  testx = {"),sprintf('%d, ', px4_out(1:end-1)), sprintf('%d', px4_out(end)),sprintf("};")];
tempy = [sprintf("  testy = {"),sprintf('%d, ', py4_out(1:end-1)), sprintf('%d', py4_out(end)),sprintf("};")];
tempz = [sprintf("  testz = {"),sprintf('%d, ', pz4_out(1:end-1)), sprintf('%d', pz4_out(end)),sprintf("};")];
[...
sprintf("  body.position.x = 0;");...
sprintf("  body.position.y = 0;");...
sprintf("  body.position.z = %d;", bodyz);...
sprintf(" ");...
sprintf("  body.orientation.roll = %d * M_PI / 180;",-roll);...
sprintf("  body.orientation.pitch = %d * M_PI / 180;",-pitch);...
sprintf("  body.orientation.yaw = %d * M_PI / 180;",-yaw);...
sprintf(" ");...
tempx;...
tempy;...
tempz;...
sprintf(" ");...
sprintf("  for (int leg_index = 0; leg_index < 6; leg_index++) {");...
sprintf("    feet.foot[leg_index].position.x = testx[leg_index];");...
sprintf("    feet.foot[leg_index].position.y = testy[leg_index];");...
sprintf("    feet.foot[leg_index].position.z = testz[leg_index];");...
sprintf("  }");...
sprintf(" ");...
sprintf("  // Feet test Positions");...
sprintf("  inversekinematics.calculate_ik(feet, body, &legs);");...
sprintf(" ");...
sprintf("  for (int leg_index = 0; leg_index < 6; leg_index++) {");...
sprintf("    EXPECT_NEAR(%d * M_PI / 180, legs.leg[leg_index].coxa, 1e-4);",alpha);...
sprintf("    EXPECT_NEAR(%d * M_PI / 180, legs.leg[leg_index].femur, 1e-4);",beta);...
sprintf("    EXPECT_NEAR(%d * M_PI / 180, legs.leg[leg_index].tibia, 1e-4);",gamma);...
sprintf("  }");...
]
