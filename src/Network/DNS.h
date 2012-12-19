#pragma once

#include <string>
#include <vector>

namespace Jatta
{
    class DNS
    {
    public:
        enum class Filter
        {
            IPV4,
            IPV6,
            ANY
        };

        DNS();
        ~DNS();

        static std::vector<std::string> lookup(const std::string& host, Filter filter = Filter::ANY);
    };
}