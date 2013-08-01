#include <Jatta.h>
using namespace Jatta;
#include <iostream>

int main(int argc, char* argv[])
{
    enum
    {
        HELP = 0x1,
        PATTERN = 0x2,
        STRING = 0x4,
        QUIET = 0x8,
        RETURN = 0x10,
        ALL = 0x20,
        ONELINE = 0x40,
        VERSION = 0x80,
    };
    UInt32 flags = 0;
    String pattern, string;
    for (int i = 1; i < argc; i++)
    {
        String arg(argv[i]);
        if (arg == "--help")
        {
            flags |= HELP;
            break;
        }
        else if (arg == "-q" || arg == "--quiet")
        {
            flags |= QUIET;
        }
        else if (arg == "-r" || arg == "--return")
        {
            flags |= RETURN;
        }
        else if (arg == "-a" || arg == "--all")
        {
            flags |= ALL;
        }
        else if (arg == "-o" || arg == "--oneline")
        {
            flags |= ONELINE;
        }
        else if (arg == "-v" || arg == "--version")
        {
            flags |= VERSION;
        }
        else if (!(flags & PATTERN))
        {
            pattern = arg;
            flags |= PATTERN;
        }
        else if (!(flags & STRING))
        {
            string = arg;
            flags |= STRING;
        }
        else
        {
            flags |= HELP;
            break;
        }
    }
    if ((!(flags & PATTERN) || !(flags & STRING)) && !(flags & VERSION))
    {
        flags |= HELP;
    }
    if (flags & HELP)
    {
        std::cout << "Usage: " << argv[0] << " [OPTIONS] PATTERN STRING" << std::endl;
        std::cout << "  Search for a Regular Expression PATTERN in STRING." << std::endl;
        std::cout << "  Outputs the match or fails with 1 if the PATTERN was not found." << std::endl;
        std::cout << std::endl;
        std::cout << "Options:" << std::endl;
        std::cout << "      --help     displays usage and exits" << std::endl;
        std::cout << "  -v, --version  displays version information and exits" << std::endl;
        std::cout << "  -q, --quiet    do not display match, just pass or fail" << std::endl;
        std::cout << "  -r, --return   returns the position of the match as the return code (-1 for no match)" << std::endl;
        std::cout << "  -a, --all      output all matches, one line at a time" << std::endl;
        std::cout << "  -o, --oneline  modifies output to all be on one line" << std::endl;
        std::cout << std::endl;
        std::cout << "Part of the Jatta (General Utility Library) examples." << std::endl;
        std::cout << "See http://jatta.zethes.com/ for acknowledgements and licensing." << std::endl;
        return -1;
    }
    if (flags & VERSION)
    {
        std::cout << "Regex 1.0" << " using Jatta-" << GetJattaVersion() << "-" << GetJattaCompilerName() << std::endl;
        return 0;
    }

    Regex rx(pattern);
    Size start, end;
    if (!rx.Find(string, 0, &start, &end))
    {
        if (flags & RETURN)
        {
            return -1;
        }
        else
        {
            return 1;
        }
    }
    if (!(flags & QUIET))
    {
        std::cout << string.SubString(start, end - start + 1);
        if (!(flags & ONELINE))
        {
            std::cout << std::endl;
        }
        if (flags & ALL)
        {
            Size startAll, endAll = end + 1;
            while (rx.Find(string, endAll, &startAll, &endAll))
            {
                std::cout << string.SubString(startAll, endAll - startAll + 1);
                if (!(flags & ONELINE))
                {
                    std::cout << std::endl;
                }
                endAll++;
            }
        }
    }

    if (flags & RETURN)
    {
        return start;
    }
    return 0;
}
