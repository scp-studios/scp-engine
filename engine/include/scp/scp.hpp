#ifndef A855B898_4CA4_48BD_BB47_D005F2374B77
#define A855B898_4CA4_48BD_BB47_D005F2374B77

#ifdef SCP_ENGINE_BUILD_DLL
    #define SCPEXP __declspec(dllexport)
#else
    #ifdef SCP_ENGINE_LINK_DLL
        #define SCPEXP __declspec(dllimport)
    #else
        #define SCPEXP
    #endif
#endif

#endif /* A855B898_4CA4_48BD_BB47_D005F2374B77 */
