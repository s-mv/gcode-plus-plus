# BYTECODE

The bytecode is just a bunch of function calls.
For instance, `g1 x2 f100` translates to:
```
INCREMENTAL MODE
SET X TO 2
SET FEED TO 100
EXECUTE!!!
```
We cans tore these functions as arrays using a stack:
```
[
  INCREMENTAL_MODE,
  PUSH(2),
  SET_X,
  PUSH(100),
  SET_Y,
  EXEC,
]
```
This is a rough representation of how the bytecode could look.

TODO: Build upon this.
