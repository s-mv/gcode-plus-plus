# Language Features Added To The rs274ngc Specification
This is what I've dubbed to be "gcode++" which introduces modern control-flow
constructs like import, while, for, and if, to support modular, readable, and
maintainable CNC programs.

## Imports
```
import "./filename"
```
Imports are as good as C's `include` - all parameters and subroutines are
essentially copy-pasted accross files. Circular imports result in an error.

## While loops
```
while #1 < 3
    ; do something here
end ; or endwhile
```
Evaluate the loop body as long as the condition holds true.

## For loops
```
for #1 from 0 to 3
    ; do something here
end ; or endfor
```
Iterate from the start to the end value (inclusive). The loop variable must be
a parameter like #1.

## Continue and Break
`continue` and `break` keywords can be used in order to exit a loop or skip
iterations.

## If Statements
```
if #1 > 30
    ; do something here
end ; or endif
```
Executes the block only if the condition is true.

