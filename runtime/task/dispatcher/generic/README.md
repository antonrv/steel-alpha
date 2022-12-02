

## Generic dispatcher characteristics

This is a fairly generic dispatcher that exposes several extraction possibilities.


--- Heterogeneous system:
Some tasks dispatched by this dispatcher may be runnable on some worker set but not on other.

So it is needed a reference to a global queue where any task pulled by an incompatible worker can be placed.



--- Double extraction
Workers can resume this dispatcher in two ways:

· Push mode: Tasks are moved (only compatible) to a specific worker local queue. There is a greed parameter to specify how many compatible tasks must be dispatched before coroutine suspension.

· Extract mode: Tasks are dispatched until one compatible is found (incompatible ones are pushed into a queue). In this case, it is returned to the worker for execution. Only if it is not ready, it is placed in a queue of the worker.
