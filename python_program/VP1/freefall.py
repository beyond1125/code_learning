from vpython import *
g=9.8 # g = 9.8 m/s^2
size = 0.25 # ball radius = 0.25 m
height = 15.0 # ball center initial height = 15 m
C_drag = 1.2
scene = canvas(width=600, height=600,
               center =vec(0,height/2,0), background=vec(0.5,0.5,0))
floor=box(length=30,height=0.01,width=10,color=color.blue)
ball=sphere(radius=size,color=color.red,make_trail=True)
ball.pos=vec(0,100,0)
ball.v=vec(0,0,0)
spee=graph(width=450)
funct=gcurve(graph=spee,color=color.blue,width=4)

dt=0.001
t=0
while ball.pos.y>=size:
    rate(1000)
    ball.v+=vec(0,-g*dt,0)-C_drag*dt*ball.v
    ball.pos+=ball.v*dt
    t+=dt
    funct.plot(pos=(t,ball.v.mag))
    
msg=text(text='final speed ='+str(ball.v.mag),pos=vec(-10,15,0))

