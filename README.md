-Rockets : - 
You’re leading an exploration of space, and it is your job to design a spaceship that
will go as far as possible. To do this, you have n available rockets. The ith rocket is
capable of accelerating the ship by a rate of ai meters per second squared and can do
this for a total of si seconds. The ship is initially at rest (its initial velocity is zero).
Your job is to determine the order in which to fire the rockets. You will choose one
rocket, fire it until si seconds have elapsed, then immediately switch to another
unused rocket. Each rocket can only be used once, and you may ignore the time it
takes to switch between rockets.
Given the accelerations and durations of each rocket, design and implement an
efficient algorithm to determine the optimal order to fire the rockets, to maximize the
total distance traveled.
Physics background: if our velocity is v before we start firing a single rocket whose
acceleration is a then, after t seconds, we will have traveled a total vt+ 1/2at2 meters
during that time, and our final velocity will be v’ = v + at
Input
Number of rockets: 2, r1,r2
Accelerations of each rocket: a1 = 2, a2 = 3
Durations of each rocket: s1 = 1, s2 = 2
Output
The optimal order to fire the rockets to maximize the total distance traveled: r1, r2
Total distance traveled: : [ 1/2 · 2 · 1 2 ] +[2 · 1 · 2+ 1/2 · 3 · 2 2 ] = 11 meters.
---------------------
Team Members : 
- Taha Hussein 
- Mahmoud Hamed @MEKKYUA
- Abd el rahman Mahmoud
- Ahmed gamal
