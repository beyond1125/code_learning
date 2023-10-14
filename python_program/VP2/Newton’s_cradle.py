from vpython import *

mass = 1
size = 0.2
dt, k, g, L = 0.0001, 150000, vector(0, -9.8, 0), 2
t = 0
N = 2

def af_col_v(v1, v2, x1, x2):
    v1p = v1 + (x1 - x2) * dot(v2 - v1, x1 - x2) / dot(x1 - x2, x1 - x2)
    v2p = v2 + (x2 - x1) * dot(v1 - v2, x2 - x1) / dot(x2 - x1, x2 - x1)
    return v1p, v2p

scene = canvas(width=500, height=500, center=vec(0, -0.2, 0), background=vec(0.5, 0.3, 0.2))
graph1 = graph (height = 500, align = 'right')
graph2 = graph (height = 500, align = 'right')
Ek = gcurve(graph = graph1, color=color.blue, width = 3)
Ug = gcurve(graph = graph1, color=color.red, width = 3)
Ek_avg = gcurve(graph = graph2, color=color.blue, width = 3)
Ug_avg = gcurve(graph = graph2, color=color.red, width = 3)

juntions = []
for i in range(5):
    juntion = sphere(radius=0.07, color=color.white)
    juntion.pos = vec(-0.8 + 0.4 * i, 0, 0)
    juntions.append(juntion)

balls = []
for i in range(5):
    ball = sphere(radius=size, color=color.white)
    ball.pos = vec(-0.8 + 0.4 * i, -2, 0)
    ball.v=vec(0,0,0)
    balls.append(ball)
    

springs = []
spring_forces = []
for i in range(5):
    spring = cylinder(radius=0.04, color=color.white)
    spring.pos = vec(-0.8 + 0.4 * i, 0, 0)
    spring.axis = balls[i].pos - spring.pos
    springs.append(spring)
    spring_forces.append(vec(0, 0, 0))

for i in range(N):
    balls[i].pos = vec(-0.8+0.4*i-pow(L*L-1.95*1.95,1/2), -1.95, 0)

Ek_total=0
Ug_total=0
vsq_accumulate=0
height_accumulate=0
while True:
    rate(5000)
    
    vsq_total=0
    
    height_total=0
    
    for i in range(5):
        springs[i].axis = balls[i].pos - springs[i].pos
        spring_forces[i] = -k * (mag(springs[i].axis) - L) * springs[i].axis.norm()

        balls[i].a = g + spring_forces[i] / mass
        balls[i].v += balls[i].a * dt
        balls[i].pos += balls[i].v * dt

        next_index = (i + 1) % 5
        prev_index = (i - 1) % 5

        vsq_total+=mag(balls[i].v)*mag(balls[i].v)
        height_total+=balls[i].pos.y+2.0
        vsq_accumulate+=mag(balls[i].v)*mag(balls[i].v)
        height_accumulate+=balls[i].pos.y+2.0

        if mag(balls[i].pos - balls[next_index].pos) <= size + size and dot(balls[i].pos - balls[next_index].pos, balls[i].v - balls[next_index].v) <= 0:
            (balls[i].v, balls[next_index].v) = af_col_v(balls[i].v, balls[next_index].v, balls[i].pos, balls[next_index].pos)

        if mag(balls[i].pos - balls[prev_index].pos) <= size + size and dot(balls[i].pos - balls[prev_index].pos, balls[i].v - balls[prev_index].v) <= 0:
            (balls[i].v, balls[prev_index].v) = af_col_v(balls[i].v, balls[prev_index].v, balls[i].pos, balls[prev_index].pos)
        

    t += 0.0001
    if 1/2*mass*vsq_total<2 :
        Ek.plot(pos=(t,1/2*mass*vsq_total))
        Ek_avg.plot(pos=(t,1/2*mass*vsq_accumulate/t))
    Ug.plot(pos=(t,mass*mag(g)*height_total))
    Ug_avg.plot(pos=(t,mass*mag(g)*height_accumulate/t))
    
    
