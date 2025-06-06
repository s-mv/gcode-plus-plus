f600
g0 x0 y0 z0
g2 x2 r1  ; clockwise arc with radius
g3 x0 r1  ; counter-clockwise arc with radius

g0 x0 y0 z0
g2 x2 y2 i1 j1    ; clockwise arc using i/j offset
g3 x0 y0 i-1 j-1  ; counter-clockwise arc using i/j offset
