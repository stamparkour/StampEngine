# Design Task system

requirements
- threadsafe generic task queue
- dedicated pmr for each task (memory lib)
- threadsafe memory page dispatcher
- coroutine support
- awaitor supports
- metrics
- way to prevent thread stuck on one task (kill tasks)
- no maneger thread
- time dependent tasks
- api that works with networking (so C compatible)


stamp::task will be a library dedicated to a general purpose user-space thread pool
to allow for efficient handling of long running single-threaded tasks
provide access to shared resources in an efficient manner.

specifically: provide polymorphic memory resource support for tasks, 
communication between tasks