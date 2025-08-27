#include"skip.h"

#include"execute_case_info.h"

namespace neotest{

void skip(neotest::SkipInfo const& si)noexcept{
    neotest::ExecuteCaseInfo::get_current()
        .set_skip(si);
}

}//namespace neotest
