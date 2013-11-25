/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#include "JSON.hpp"

_JATTA_EXPORT Jatta::JSON::Object::Object()
{
}

_JATTA_EXPORT Jatta::JSON::Object::~Object()
{
}

_JATTA_EXPORT Jatta::JSON::Object::Object(const Object& o) :
    pairs(o.pairs)
{
}

_JATTA_EXPORT Jatta::JSON::Object& Jatta::JSON::Object::operator=(const Object& o)
{
    pairs = o.pairs;
    return *this;
}

_JATTA_EXPORT Jatta::JSON::Value& Jatta::JSON::Object::operator[] (const String& key)
{
    return pairs[key];
}

_JATTA_EXPORT std::map<Jatta::String, Jatta::JSON::Value>::const_iterator Jatta::JSON::Object::Begin() const
{
    return pairs.begin();
}

_JATTA_EXPORT std::map<Jatta::String, Jatta::JSON::Value>::const_iterator Jatta::JSON::Object::End() const
{
    return pairs.end();
}

_JATTA_EXPORT std::map<Jatta::String, Jatta::JSON::Value>::iterator Jatta::JSON::Object::Begin()
{
    return pairs.begin();
}

_JATTA_EXPORT std::map<Jatta::String, Jatta::JSON::Value>::iterator Jatta::JSON::Object::End()
{
    return pairs.end();
}

_JATTA_EXPORT std::pair<std::map<Jatta::String, Jatta::JSON::Value>::iterator, bool> Jatta::JSON::Object::Insert(String key, Value v)
{
    return pairs.insert(std::pair<String,Value>(key,v));
}

_JATTA_EXPORT Jatta::Size Jatta::JSON::Object::Size() const
{
    return pairs.size();
}

_JATTA_EXPORT Jatta::JSON::Array::Array()
{
}

_JATTA_EXPORT Jatta::JSON::Array::~Array()
{
}

_JATTA_EXPORT Jatta::JSON::Array::Array(const Array& a) :
    items(a.items)
{
}

_JATTA_EXPORT Jatta::JSON::Array& Jatta::JSON::Array::operator=(const Array& a)
{
    items = a.items;
    return *this;
}

_JATTA_EXPORT Jatta::JSON::Value& Jatta::JSON::Array::operator[] (Jatta::Size i)
{
    return items[i];
}

_JATTA_EXPORT std::vector<Jatta::JSON::Value>::const_iterator Jatta::JSON::Array::Begin() const
{
    return items.begin();
}

_JATTA_EXPORT std::vector<Jatta::JSON::Value>::const_iterator Jatta::JSON::Array::End() const
{
    return items.end();
}

_JATTA_EXPORT std::vector<Jatta::JSON::Value>::iterator Jatta::JSON::Array::Begin()
{
    return items.begin();
}

_JATTA_EXPORT std::vector<Jatta::JSON::Value>::iterator Jatta::JSON::Array::End()
{
    return items.end();
}

_JATTA_EXPORT void Jatta::JSON::Array::PushBack(const Value& v)
{
    items.push_back(v);
}

_JATTA_EXPORT void Jatta::JSON::Array::PopBack()
{
    items.pop_back();
}

_JATTA_EXPORT void Jatta::JSON::Array::Erase(std::vector<Value>::iterator i)
{
    items.erase(i);
}

_JATTA_EXPORT Jatta::Size Jatta::JSON::Array::Size() const
{
    return items.size();
}

_JATTA_EXPORT Jatta::JSON::Value::Value() :
    type(ValueType::NIL),
    valueInt(0),
    valueFloat(0.0f),
    valueBool(false)
{
}

_JATTA_EXPORT Jatta::JSON::Value::Value(const SInt32 v) :
    type(ValueType::INT),
    valueInt(v),
    valueFloat(0.0f),
    valueBool(false)
{
}

_JATTA_EXPORT Jatta::JSON::Value::Value(const UInt32 v) :
    type(ValueType::INT),
    valueInt(v),
    valueFloat(0.0f),
    valueBool(false)
{
}

_JATTA_EXPORT Jatta::JSON::Value::Value(const double v) :
    type(ValueType::FLOAT),
    valueInt(0),
    valueFloat(v),
    valueBool(false)
{
}

_JATTA_EXPORT Jatta::JSON::Value::Value(const Float32 v) :
    type(ValueType::FLOAT),
    valueInt(0),
    valueFloat(v),
    valueBool(false)
{
}

_JATTA_EXPORT Jatta::JSON::Value::Value(const bool v) :
    type(ValueType::BOOL),
    valueInt(0),
    valueFloat(0.0f),
    valueBool(v)
{
}

_JATTA_EXPORT Jatta::JSON::Value::Value(const String& v) :
    type(ValueType::STRING),
    valueInt(0),
    valueFloat(0.0f),
    valueBool(false),
    valueString(v)
{
}

_JATTA_EXPORT Jatta::JSON::Value::Value(const Object& v) :
    type(ValueType::OBJECT),
    valueInt(0),
    valueFloat(0.0f),
    valueBool(false),
    valueObject(v)
{
}

_JATTA_EXPORT Jatta::JSON::Value::Value(const Array& v) :
    type(ValueType::ARRAY),
    valueInt(0),
    valueFloat(0.0f),
    valueBool(false),
    valueArray(v)
{
}

_JATTA_EXPORT Jatta::JSON::Value::Value(const JSON::Value& v) :
    type(ValueType::NIL),
    valueInt(0),
    valueFloat(0.0f),
    valueBool(false)
{
    switch (v.Type())
    {
        case ValueType::INT:
        {
            valueInt = v.valueInt;
            type = ValueType::INT;
            break;
        }
        case ValueType::FLOAT:
        {
            valueFloat = v.valueFloat;
            type = ValueType::FLOAT;
            break;
        }
        case ValueType::BOOL:
        {
            valueBool = v.valueBool;
            type = ValueType::BOOL;
            break;
        }
        case ValueType::STRING:
        {
            valueString = v.valueString;
            type = ValueType::STRING;
            break;
        }
        case ValueType::ARRAY:
        {
            valueArray = v.valueArray;
            type = ValueType::ARRAY;
            break;
        }
        case ValueType::OBJECT:
        {
            valueObject = v.valueObject;
            type = ValueType::OBJECT;
            break;
        }
        case ValueType::NIL:
        {
            type = ValueType::NIL;
            break;
        }
    }
}

_JATTA_EXPORT Jatta::UInt32 Jatta::JSON::Value::Type() const
{
    return type;
}

_JATTA_EXPORT Jatta::JSON::Value& Jatta::JSON::Value::operator=(const Value& v)
{
    switch (v.Type())
    {
        case ValueType::INT:
        {
            valueInt = v.valueInt;
            type = ValueType::INT;
            break;
        }
        case ValueType::FLOAT:
        {
            valueFloat = v.valueFloat;
            type = ValueType::FLOAT;
            break;
        }
        case ValueType::BOOL:
        {
            valueBool = v.valueBool;
            type = ValueType::BOOL;
            break;
        }
        case ValueType::STRING:
        {
            valueString = v.valueString;
            type = ValueType::STRING;
            break;
        }
        case ValueType::ARRAY:
        {
            valueArray = v.valueArray;
            type = ValueType::ARRAY;
            break;
        }
        case ValueType::OBJECT:
        {
            valueObject = v.valueObject;
            type = ValueType::OBJECT;
            break;
        }
        case ValueType::NIL:
        {
            type = ValueType::NIL;
            break;
        }
        default:
        {
            break;
        }
    }
    return *this;
}


_JATTA_EXPORT Jatta::String Jatta::JSON::__Indent()
{
    Jatta::String ret = "";
    for (UInt32 i = 0; i < ind; i++)
    {
        ret += "\t";
    }
    return ret;
}

_JATTA_EXPORT Jatta::String Jatta::JSON::Array::ToString()
{
    Jatta::String ret = "[\n";
    Jatta::JSON::ind++;
    for (std::vector<Jatta::JSON::Value>::iterator e = Begin(); e != End();)
    {
        ret += Jatta::JSON::__Indent();
        ret += (*e).ToString();
        if (++e != End())
            ret += ',';
        ret += "\n";
    }
    Jatta::JSON::ind--;
    ret += Jatta::JSON::__Indent();
    ret += "]";
    return ret;
}

_JATTA_EXPORT Jatta::String Jatta::JSON::Object::ToString()
{
    Jatta::String ret = "{\n";
    Jatta::JSON::ind++;
    for (std::map<Jatta::String, Jatta::JSON::Value>::iterator e = Begin(); e != End();)
    {
        ret += Jatta::JSON::__Indent();
        ret += '"';
        ret += e->first;
        ret += "\": ";
        ret += e->second.ToString();
        if (++e != End())
            ret += ',';
        ret += "\n";
    }
    Jatta::JSON::ind--;
    ret += Jatta::JSON::__Indent();
    ret += "}";
    return ret;
}

_JATTA_EXPORT Jatta::String Jatta::JSON::Value::ToString()
{
    switch (type)
    {
        case Jatta::JSON::ValueType::INT:
        {
            Jatta::String ret = "";
            ret += valueInt;
            return ret;
        }
        case Jatta::JSON::ValueType::FLOAT:
        {
            Jatta::String ret = "";
            ret += valueFloat;
            return ret;
        }
        case Jatta::JSON::ValueType::BOOL:
        {
            return (valueBool ? "true" : "false");
        }
        case Jatta::JSON::ValueType::STRING:
        {
            Jatta::String ret = "\"";
            ret += valueString;
            ret += "\"";
            return ret;
        }
        case Jatta::JSON::ValueType::ARRAY:
        {
            return valueArray.ToString();
        }
        case Jatta::JSON::ValueType::OBJECT:
        {
            return valueObject.ToString();
        }
        case Jatta::JSON::ValueType::NIL:
        default:
        {
            return U8("null");
        }
    }
}

_JATTA_EXPORT Jatta::JSON::Value::operator Float32() const
{
    return valueFloat;
}

_JATTA_EXPORT Jatta::JSON::Value::operator SInt32() const
{
    return valueInt;
}

_JATTA_EXPORT Jatta::JSON::Value::operator bool() const
{
    return valueBool;
}

_JATTA_EXPORT Jatta::JSON::Value::operator String() const
{
    return valueString;
}

_JATTA_EXPORT Jatta::JSON::Value::operator Object() const
{
    return valueObject;
}

_JATTA_EXPORT Jatta::JSON::Value::operator Array() const
{
    return valueArray;
}

_JATTA_EXPORT Jatta::JSON::Value Jatta::JSON::ParseNumber(String str)
{
    bool negate = (str[0] == JSON::Grammar::Numbers::MINUS);

    UInt32 splitLoc = 0;
    UInt32 expLoc = 0;
    bool isInt = true;
    bool hasExp = false;
    for (UInt32 i = 1; i < str.GetLength(); i++)
    {
        if (str[i] == Grammar::Numbers::DECIMAL_POINT)
        {
            if (!isInt)
            {
                break;    //ERROR
            }
            isInt = false;
            splitLoc = i;
        }
        else if (str[i] == Grammar::Numbers::LOWER_EXP ||
                 str[i] == Grammar::Numbers::UPPER_EXP)
        {
            hasExp = true;
            expLoc = i;
            break;
        }
    }
    if (!hasExp)
    {
        expLoc = str.GetLength();
    }

    if (isInt)
    {
        splitLoc = expLoc;
    }

    float number = 0;
    float place = 1;

    // Start with the left side (> 0)
    for (SInt32 i = splitLoc - 1; i >= 0; i--)
    {
        if (str[i] == JSON::Grammar::Numbers::MINUS && i == 0)
        {
            break;
        }
        if (str[i] >= '0' && str[i] <= '9')
        {
            //Can't have a trail of zeros at start (unless it's the only 0)
            if (str[i] == '0' || i == splitLoc - 1)
            {
                bool bad = true;
                for (UInt32 j = 0; j < i; j++) //Check to see if there is only zeros before this.
                {
                    if (str[j] >= '1' && str[j] <= '9')
                    {
                        bad = false;
                        break;
                    }
                }
                if (bad)
                    break;
            }

            //Appears to be fine, lets add this number and increment the place.
            number += (str[i] - '0') * place;
            place *= 10;
        }
        else
        {
            //ERROR unknown Char
        }
    }

    if (!isInt) //It's a decimal!
    {
        place = 0.1;
        for (UInt32 i = splitLoc + 1; i < str.GetLength() && i < expLoc; i++)
        {
            if (str[i] >= '0' && str[i] <= '9')
            {
                number += (str[i] - '0')*place;
                place /= 10;
            }
            else
            {
                 //ERROR unknown Char
            }
        }
    }

    //Is it in scientific notation?
    if (hasExp)
    {
        float notationAmount = 0;
        bool negativeNotate = true;
        place = 1;
        for (SInt32 i = str.GetLength() - 1; i >= 0 && i > expLoc; i--)
        {
            if (str[i] >= '0' && str[i] <= '9')
            {
                notationAmount += (str[i] - '0') * place;
                place *= 10;
            }
            else if (i == expLoc+1 && str[i] == Grammar::Numbers::MINUS || str[i] == Grammar::Numbers::PLUS)
            {
                negativeNotate = (str[i] == Grammar::Numbers::MINUS);
            }
            else
            {
                //ERROR unknown Char
            }
        }
        place = 1;
        for (UInt32 i = 0; i < notationAmount; i++)
        {
            place *= 10;
        }

        if (negativeNotate)
        {
            place = 0.1;
            for (UInt32 i = 0; i < notationAmount - 1; i++)
            {
                place /= 10;
            }
        }

        number *= place;
    }

    if (negate)
    {
        number *= -1;
    }

    if ((SInt32)number == number && isInt)
    {
        return JSON::Value((SInt32)(number));
    }
    else
    {
        return JSON::Value(number);
    }
}

_JATTA_EXPORT Jatta::JSON::Value Jatta::JSON::ParseString(String str)
{
    Jatta::String ret;

    UInt32 i = 0;
    if (str[0] == Grammar::Structural::STRING_DELIMITOR)
    {
        i++;
    }

    for (i; i < str.GetLength(); i++)
    {
        if (str[i] == Grammar::Structural::STRING_DELIMITOR)
        {
            break;
        }
        if (str[i] == Grammar::Strings::Escape::BEGIN_ESCAPE)
        {
            if (i+1 >= str.GetLength())
            {
                //ERROR
            }
            switch (str[i+1])
            {
                case Grammar::Strings::Escape::QUOTATION_MARK:
                {
                    ret += Grammar::Strings::QUOTATION_MARK;
                    break;
                }
                case Grammar::Strings::Escape::REVERSE_SOLIDUS:
                {
                    ret += Grammar::Strings::REVERSE_SOLIDUS;
                    break;
                }
                case Grammar::Strings::Escape::SOLIDUS:
                {
                    ret += Grammar::Strings::SOLIDUS;
                    break;
                }
                case Grammar::Strings::Escape::BACKSPACE:
                {
                    ret += Grammar::Strings::BACKSPACE;
                    break;
                }
                case Grammar::Strings::Escape::FORM_FEED:
                {
                    ret += Grammar::Strings::FORM_FEED;
                    break;
                }
                case Grammar::Strings::Escape::LINE_FEED:
                {
                    ret += Grammar::Strings::LINE_FEED;
                    break;
                }
                case Grammar::Strings::Escape::CARRIAGE_RETURN:
                {
                    ret += Grammar::Strings::CARRIAGE_RETURN;
                    break;
                }
                case Grammar::Strings::Escape::TAB:
                {
                    ret += Grammar::Strings::TAB;
                    break;
                }
                case Grammar::Strings::Escape::BEGIN_UNICODE:
                {
                    Jatta::String copy = str;
                    copy.ToLower();
                    if (i + 5 >= str.GetLength()) //Need 4 hexadecimal digits
                    {
                        //ERROR
                    }

                    UInt32 charCode = 0;
                    UInt32 place = 1;
                    for (SInt32 j = i + 4; j >= i + 1; j--)
                    {
                        if (copy[j] >= '0' && copy[j] <= '9')
                        {
                            charCode += (copy[j]-'0')*place;
                            place *= 16;
                        }
                        else if (copy[j] >= 'a' || copy[j] <= 'f' )
                        {
                            charCode += (copy[j] - 'a' + 10) * place;
                            place *= 16;
                        }
                        else
                        {
                            //ERROR! Unknown character.
                        }
                    }
                    i += 4;

                    ret += String::FromCodePoint(charCode);
                }
                break;
            }
            i += 1;
        }
        else
        {
            ret += str[i];
        }
    }

    return JSON::Value(ret);
}

_JATTA_EXPORT Jatta::JSON::Array Jatta::JSON::ParseArray(Jatta::String str)
{
    Array ret;

    String value;
    bool insideString = false;
    int objInd = 0, arrayInd = 0;
    for (UInt32 i = 0; i < str.GetLength(); i++)
    {
        if (insideString)
        {
            if (str[i] == Grammar::Structural::STRING_DELIMITOR)
            {
                value += str[i];
                insideString = false;
            }
            else
            {
                value += str[i];
            }
        }
        else if (objInd > 0 || str[i] == Grammar::Structural::BEGIN_OBJECT)
        {
            if (str[i] == Grammar::Structural::END_OBJECT)
            {
                objInd--;
            }
            if (str[i] == Grammar::Structural::BEGIN_OBJECT)
            {
                objInd++;
            }
            value += str[i];
        }
        else if (arrayInd > 0 || str[i] == Grammar::Structural::BEGIN_ARRAY)
        {
            if (str[i] == Grammar::Structural::END_ARRAY)
            {
                arrayInd--;
            }
            if (str[i] == Grammar::Structural::BEGIN_ARRAY)
            {
                arrayInd++;
            }
            value += str[i];
        }
        else if (str[i] == Grammar::Structural::STRING_DELIMITOR)
        {
            value += str[i];
            insideString = true;
        }
        else if (str[i] == Grammar::Structural::VALUE_SEPERATOR)
        {
            ret.PushBack(Jatta::JSON::ParseValue(value));
            value.Set("");
        }
        else
        {
            value += str[i];
        }
    }

    if (value.GetLength() > 0)
    {
        ret.PushBack(Jatta::JSON::ParseValue(value));
    }

    return ret;
}

_JATTA_EXPORT Jatta::JSON::Object Jatta::JSON::ParseObject(Jatta::String str)
{
    Object ret;

    std::vector<String> parts;
    String part;
    bool insideString = false;
    int objInd = 0, arrayInd = 0;
    for (UInt32 i = 0; i < str.GetLength(); i++)
    {
        if (insideString)
        {
            if (str[i] == Grammar::Structural::STRING_DELIMITOR)
            {
                insideString = false;
                part += str[i];
            }
            else
            {
                part += str[i];
            }
        }
        else if (objInd > 0 || str[i] == Grammar::Structural::BEGIN_OBJECT)
        {
            if (str[i] == Grammar::Structural::END_OBJECT)
            {
                objInd--;
            }
            if (str[i] == Grammar::Structural::BEGIN_OBJECT)
            {
                objInd++;
            }
            part += str[i];
        }
        else if (arrayInd > 0 || str[i] == Grammar::Structural::BEGIN_ARRAY)
        {
            if (str[i] == Grammar::Structural::END_ARRAY)
            {
                arrayInd--;
            }
            if (str[i] == Grammar::Structural::BEGIN_ARRAY)
            {
                arrayInd++;
            }
            part += str[i];
        }
        else if (str[i] == Grammar::Structural::STRING_DELIMITOR)
        {
            part += str[i];
            insideString = true;
        }
        else if (str[i] == Grammar::Structural::VALUE_SEPERATOR)
        {
            parts.push_back(part);
            part.Set("");
        }
        else
        {
            part += str[i];
        }
    }
    parts.push_back(part);

    for (std::vector<String>::const_iterator i = parts.begin(); i != parts.end(); ++i)
    {
        bool insideString = false;

        Jatta::String key;
        for (UInt32 j = 0; j < i->GetLength(); j++)
        {
            if (insideString)
            {
                if (i->GetChar(j) == Grammar::Structural::STRING_DELIMITOR)
                {
                    insideString = false;
                }
                else
                {
                    key += i->GetChar(j);
                }
            }
            else if (i->GetChar(j) == Grammar::Structural::STRING_DELIMITOR)
            {
                insideString = true;
            }
            else if (i->GetChar(j) == Grammar::Structural::PAIR_SEPERATOR)
            {
                if (key.GetLength() == 0)
                {
                    //ERROR
                }
                ret.Insert(key, JSON::ParseValue(i->SubString(j + 1)));
                break;
            }
        }
    }

    return ret;
}

_JATTA_EXPORT Jatta::JSON::Value Jatta::JSON::ParseValue(Jatta::String str)
{
    String strLower = str;
    strLower.ToLower();
    if (strLower == Grammar::Literals::FALSE_STRING)
    {
        return Jatta::JSON::Value(false);
    }
    else if (strLower == Grammar::Literals::TRUE_STRING)
    {
        return Jatta::JSON::Value(true);
    }
    else if (strLower == Grammar::Literals::NULL_STRING)
    {
        return Jatta::JSON::Value();
    }
    //Is it a number?
    else if (str[0] == Grammar::Numbers::MINUS || (str[0] >= '0' && str[0] <= '9'))
    {
        return JSON::ParseNumber(str);
    }
    //What about a string?
    else if (str[0] == Grammar::Structural::STRING_DELIMITOR)
    {
        return JSON::ParseString(str);
    }
    else if (str[0] == Grammar::Structural::BEGIN_ARRAY) //Array
    {
        //Get the code.
        int ind = 0;
        Jatta::String code;
        for (UInt32 i = 0; i < str.GetLength(); i++)
        {
            if (str[i] == Grammar::Structural::BEGIN_ARRAY)
            {
                ind++;
            }
            else if (str[i] == Grammar::Structural::END_ARRAY)
            {
                ind--;
                if (ind == 0)
                {
                    break;
                }
            }

            if (ind > 0 && i > 0)
            {
                code += str[i];
            }
        }
        if (ind != 0)
        {
            //ERROR
        }

        return Jatta::JSON::Value(Jatta::JSON::ParseArray(code));
    }
    else if (str[0] == Grammar::Structural::BEGIN_OBJECT) //Object
    {
        //Get the code.
        int ind = 0;
        String code;
        for (UInt32 i = 0; i < str.GetLength(); i++)
        {
            if (str[i] == Grammar::Structural::BEGIN_OBJECT)
            {
                ind++;
            }
            else if (str[i] == Grammar::Structural::END_OBJECT)
            {
                ind--;
                if (ind == 0)
                {
                    break;
                }
            }

            if (ind > 0 && i > 0)
            {
                code += str[i];
            }
        }
        if (ind != 0)
        {
            //ERROR
        }

        return Jatta::JSON::Value(Jatta::JSON::ParseObject(code));
    }
    else
    {
        return Jatta::JSON::Value();
    }
}

_JATTA_EXPORT Jatta::JSON::Value Jatta::JSON::Parse(Jatta::String str)
{
    //Remove the unnecessary whitespacing.
    String newStr;
    bool insideString = false;
    for (UInt32 i = 0; i < str.GetLength(); i++)
    {
        if (insideString)
        {
            if (str[i] == Grammar::Structural::STRING_DELIMITOR)
            {
                newStr += str[i];
                insideString = false;
            }
            else
            {
                newStr += str[i];
            }
        }
        else if (str[i] == Grammar::Structural::STRING_DELIMITOR)
        {
            newStr += str[i];
            insideString = true;
        }
        else if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n' && str[i] != '\r')
        {
            newStr += str[i];
        }
    }

    //Parse!
    return ParseValue(newStr);
}
