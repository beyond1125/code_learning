from vpython import *
g = 9.8  # g = 9.8 m/s^2
size = 0.25  # ball radius = 0.25 m
theta = pi/4
C_drag = 0.9
scene = canvas(width=600, height=600,align='left',
               center=vec(0, 10, 0), background=vec(0.5, 0.2, 0.3))
floor = box(length=30, height=0.01, width=4, color=color.blue)
ball = sphere(radius=size, color=color.red, make_trail=True)
ball.pos = vec(-15, size, 0)
ball.v = vec(20 * cos(theta), 20 * sin(theta), 0)

a1 = arrow(color=color.green, shaftwidth=0.1)

vtgraph=graph(width=450,align='right')
funct=gcurve(graph=vtgraph,color=color.blue,width=4)

highest_point=0
distant=0
dt = 0.001
t=0
count = 0
while count<3:
    rate(1000)
    ball.v+=vec(0,-g*dt,0)-C_drag*dt*ball.v
    ball.pos+=ball.v*dt
    distant+=ball.v.mag*dt
    t+=dt
    funct.plot(pos=(t,ball.v.mag))
    if count==0 and ball.v.y<0.01 and ball.v.y>0 :
        highest_point=ball.pos.y

    if ball.pos.y <= size:  # Check if ball hits the ground
        ball.v.y = -ball.v.y  # Reverse y component of velocity
        count += 1
    a1.pos = ball.pos
    a1.axis = ball.v/2
displacement=ball.pos.x-(-15)
msg1=text(text='The highest position is '+ str(highest_point),pos=vec(-15,20,0))
msg2=text(text='The distant is '+ str(distant),pos=vec(-15,15,0))
msg3=text(text='The displacement is'+ str(displacement),pos=vec(-15,10,0))
    
