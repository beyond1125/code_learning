from vpython import *

g = 9.8
size, m = 0.05, 0.2
L, k = 0.5, [15, 12, 17]
v = [1, 2, 2.2]
d = [-0.06, 0, -0.1]

scene = canvas(width=400, height=400, center=vec(0.4, 0.2, 0), align='left', background=vec(0.5, 0.5, 0))
floor = box(pos=vec(0.4, 0, 0), length=0.8, height=0.005, width=0.8, color=color.blue)
wall = box(pos=vec(0, 0.05, 0), length=0.01, height=0.1, width=0.8)

balls = []
for i in range(3):
    ball = sphere(pos=vec(L + d[i], size, (i - 1) * 3 * size), radius=size, color=color.red)
    ball.v = vec(v[i], 0, 0)
    balls.append(ball)

springs = []
springs_force = []  # Initialize springs_force list

for i in range(3):
    spring = helix(pos=vec(0, size, (i - 1) * 3 * size), radius=0.02, thickness=0.01)
    spring.axis = balls[i].pos - spring.pos
    spring.k = k[i]
    springs.append(spring)
    springs_force.append(vector(0, 0, 0))  # Initialize springs_force vector

dt = 0.001

while True:
    for i in range(3):
        rate(1000)
        
        springs[i].axis = balls[i].pos - springs[i].pos
        springs[i].axis.norm()  # Normalize the axis vector
        
        springs_force[i] = -k[i] * (mag(springs[i].axis) - L) * springs[i].axis.norm()
        balls[i].a =  springs_force[i] / m
        balls[i].v += balls[i].a * dt
        balls[i].pos += balls[i].v * dt
