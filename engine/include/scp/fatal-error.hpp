#ifndef E0D7FDB6_0502_4472_9924_C8E5587C0AEF
#define E0D7FDB6_0502_4472_9924_C8E5587C0AEF

#include <string_view>

namespace scp
{
    class fatal_error_t
    {
    public:
        fatal_error_t(std::string_view what): m_what(what) {}
        
        const std::string_view m_what;
    };
}

#endif /* E0D7FDB6_0502_4472_9924_C8E5587C0AEF */
