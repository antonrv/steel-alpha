
## Lightweight dispatcher characteristics

This is a dispatcher that exposes a single interface and is fast to build.

--- Homogeneous system:
All tasks dispatched by this dispatcher can be executed in any worker in the system.

So there is no need for it to store a reference to a global queue where incompatible tasks pulled by a worker are pushed to, because there is no concept of 'incompatible'.

So these dispatchers are built when the worker set is homogeneous.


--- Single extraction:
They have a single resumption mode: extract a single task.
