# Changelog
 
## v0.0.0
                                 
DONE | Make ContextHandler a singleton.
DONE | Support for GLFW3.
DONE | Investigate why exception stop to triggers after one throwing.
DONE | Add a macro for PyTypeObject Initialization.
WIP  | Python binding.                                                                                      
WIP  | Add Histogram.
WIP  | Write unit tests for both C/C++ and Python code.
TODO | S'assurer que le thread supprimé est bien arrêté. Sinon forcer son arrêt.
TODO | Add DefaultLayout method.
TODO | Add a chart updater method for animation. 
TODO | Add DSight::AllocationException, Inherits from DSight::BaseException.
TODO | Raise DSight::AllocationException when 'new' usage failed.
TODO | Raise exception for every XXX_C_Side_init failure (returning NULL pointer).
TODO | Write documentation.
TODO | Refactor ContextBase to ContextBackend.
