#1 = 3

while [#1 > 0]
  g0 x[#1] y0 z0
  #1 = [[#1] - 1]
endwhile

do
  g0 x[#1 + 5] y0 z0
  #1 = [#1 + 1]
while [[#1] > 3] endwhile
; this ^ is false by the way
