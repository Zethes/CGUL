#include "Obj.h"
#include "Group.h"
#include "../File/File.h"
#include "../Math/Math.h"
#include "../Math/Float4.h"

void Jatta::Obj::cleanLine(std::string* line)
{
    size_t find;
    while ((find = line->find("  ")) != std::string::npos)
    {
        line->erase(find, 1);
    }
    if (*line->begin() == ' ')
    {
        line->erase(line->begin());
    }
    if (*(line->end() - 1) == ' ')
    {
        line->erase(line->end() - 1);
    }
}

bool Jatta::Obj::getParameters(const std::string& parameters, float* data, unsigned int* size)
{
    std::istringstream ss;
    ss.str(parameters);
    for (*size = 0; *size < 4 && ss.good(); (*size)++)
    {
        ss >> data[*size];
    }
}

bool Jatta::Obj::getParameters(const std::string& parameters)//, std::vector<std::pair<float*, unsigned int>>* data)
{
    std::string number = "";
    for (unsigned int i = 0; i <= parameters.size(); i++)
    {
        if (i == parameters.size() || !isdigit(parameters[i]))
        {
            std::cout << number << std::endl;
            number = "";
            continue;
        }
        number += parameters[i];
    }
}

Jatta::Obj::Obj()
{
}

bool Jatta::Obj::load(const std::string& fileName)
{
    std::vector<std::string> file;
    if (!File::getLines(fileName, &file))
    {
        return false;
    }

    unsigned int verticesCount = 0;
    std::vector<Jatta::Float4> vertices;
    unsigned int texCoordCount = 0;
    std::vector<Jatta::Float4> texCoords;
    Group* group = nullptr;

    for (auto it = file.begin(); it != file.end(); it++)
    {
        std::string clean = *it;
        cleanLine(&clean);
        if (clean.empty() || clean.at(0) == '#')
        {
            continue;
        }
        size_t find = clean.find(' ');
        if (find == std::string::npos)
        {
            continue;
        }
        std::string type = clean.substr(0, find);
        std::string parameters = clean.substr(find + 1);
        float vector[4];
        unsigned int vectorSize;
        //std::cout << type << std::endl;
        if (type == "v")
        {
            getParameters(parameters, vector, &vectorSize);
            if (vectorSize != verticesCount)
            {
                if (verticesCount == 0)
                {
                    verticesCount = vectorSize;
                }
                else
                {
                    return false;
                }
            }
            vertices.push_back(*(Float4*)vector);
        }
        else if (type == "vt")
        {
            getParameters(parameters, vector, &vectorSize);
            if (vectorSize != texCoordCount)
            {
                if (texCoordCount == 0)
                {
                    texCoordCount = vectorSize;
                }
                else
                {
                    return false;
                }
            }
            texCoords.push_back(*(Float4*)vector);
        }
        else if (type == "g")
        {
            groups.push_back(Group());
            group = &(*(groups.end() - 1));
            group->name = parameters;
        }
        else if (type == "f")
        {
            if (group == nullptr)
            {
                return false;
            }
            getParameters(parameters);
        }
    }

    std::cout << "GROUPS: " << groups.size() << std::endl;

    return true;
}