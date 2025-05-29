#1 = 5

while [#1 > 0] do
  g0 x[#1] y0 z0
  #1 = [#1 - 1]
end

do
  g0 x[0 - #1] y0 z0
  #1 = [#1 + 1]
while [#1 < 5] end
