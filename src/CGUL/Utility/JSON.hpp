// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file JSON.hpp
 */

#pragma once

// Configuration
#include <CGUL/Config.hpp>

// CGUL Includes
#include "../Utility/String.hpp"

// Defines
#include "../External/Defines.hpp"

 namespace CGUL
 {
    namespace JSON
    {
        namespace ValueType
        {
            enum
            {
                INT = 0,
                FLOAT,
                BOOL,
                STRING,
                OBJECT,
                ARRAY,
                NIL
            };
        }

        namespace Grammar
        {
            namespace Structural
            {
                const char BEGIN_ARRAY = '[';
                const char BEGIN_OBJECT = '{';
                const char END_ARRAY = ']';
                const char END_OBJECT = '}';
                const char PAIR_SEPERATOR = ':';
                const char VALUE_SEPERATOR = ',';
                const char STRING_DELIMITOR = '"';
            }
            namespace Literals
            {
                const CGUL::String FALSE_STRING = "false";
                const CGUL::String TRUE_STRING = "true";
                const CGUL::String NULL_STRING = "null";
            }
            namespace Numbers
            {
                const char DECIMAL_POINT = '.';
                const char LOWER_EXP = 'e';
                const char UPPER_EXP = 'E';
                const char MINUS = '-';
                const char PLUS = '+';
            }
            namespace Strings
            {
                const char QUOTATION_MARK = '"';
                const char REVERSE_SOLIDUS = '\\';
                const char SOLIDUS = '/';
                const char BACKSPACE = '\b';
                const char FORM_FEED = '\f';
                const char LINE_FEED = '\n';
                const char CARRIAGE_RETURN = '\r';
                const char TAB = '\t';

                namespace Escape
                {
                    const char BEGIN_ESCAPE = '\\';
                    const char QUOTATION_MARK = '"';
                    const char REVERSE_SOLIDUS = '\\';
                    const char SOLIDUS = '/';
                    const char BACKSPACE = 'b';
                    const char FORM_FEED = 'f';
                    const char LINE_FEED = 'n';
                    const char CARRIAGE_RETURN = 'r';
                    const char TAB = 't';
                    const char BEGIN_UNICODE = 'u';
                    namespace StringForm
                    {
                        const CGUL::String QUOTATION_MARK = "\\\"";
                        const CGUL::String REVERSE_SOLIDUS = "\\\\";
                        const CGUL::String SOLIDUS = "\\/";
                        const CGUL::String BACKSPACE = "\\b";
                        const CGUL::String FORM_FEED = "\\f";
                        const CGUL::String LINE_FEED = "\\n";
                        const CGUL::String CARRIAGE_RETURN = "\\r";
                        const CGUL::String TAB = "\\t";
                        const CGUL::String BEGIN_UNICODE = "\\u";
                    }
                }
            }
        }

        static UInt32 ind;
        _CGUL_EXPORT CGUL::String __Indent();

        class Array;
        class Object;
        class Value;

        class Array
        {
            std::vector<Value> items;
        public:
            _CGUL_EXPORT Array();
            _CGUL_EXPORT ~Array();

            _CGUL_EXPORT Array(const Array& a);
            _CGUL_EXPORT Array& operator=(const Array& a);

            _CGUL_EXPORT Value& operator[] (Size i);
            _CGUL_EXPORT std::vector<Value>::const_iterator Begin() const;
            _CGUL_EXPORT std::vector<Value>::const_iterator End() const;
            _CGUL_EXPORT std::vector<Value>::iterator Begin();
            _CGUL_EXPORT std::vector<Value>::iterator End();

            _CGUL_EXPORT void PushBack(const Value& v);
            _CGUL_EXPORT void PopBack();
            _CGUL_EXPORT void Erase(std::vector<Value>::iterator i);
            _CGUL_EXPORT Size GetSize() const;

            _CGUL_EXPORT String ToString();
        };

        class Object
        {
            std::map<String, Value> pairs;
        public:
            _CGUL_EXPORT Object();
            _CGUL_EXPORT ~Object();

            _CGUL_EXPORT Object(const Object& o);
            _CGUL_EXPORT Object& operator=(const Object& o);

            _CGUL_EXPORT Value& operator[] (const String& key);
            _CGUL_EXPORT std::map<String, Value>::const_iterator Begin() const;
            _CGUL_EXPORT std::map<String, Value>::const_iterator End() const;
            _CGUL_EXPORT std::map<String, Value>::iterator Begin();
            _CGUL_EXPORT std::map<String, Value>::iterator End();

            _CGUL_EXPORT std::pair<std::map<String,Value>::iterator, bool> Insert(String key, Value v);
            _CGUL_EXPORT CGUL::Size Size() const;

            _CGUL_EXPORT String ToString();
        };

        class Value
        {
            UInt32 type;

            SInt32 valueInt;
            Float32 valueFloat;
            bool valueBool;
            String valueString;

            Object valueObject;
            Array valueArray;
        public:
            _CGUL_EXPORT Value();
            _CGUL_EXPORT Value(const Value& v);
            _CGUL_EXPORT Value(const SInt32 v);
            _CGUL_EXPORT Value(const UInt32 v);
            _CGUL_EXPORT Value(const Float32 v);
            _CGUL_EXPORT Value(const double v);
            _CGUL_EXPORT Value(const bool v);
            _CGUL_EXPORT Value(const String& v);
            _CGUL_EXPORT Value(const Object& v);
            _CGUL_EXPORT Value(const Array& v);

            _CGUL_EXPORT UInt32 Type() const;

            _CGUL_EXPORT Value& operator=(const Value& v);

            _CGUL_EXPORT operator Float32() const;
            _CGUL_EXPORT operator SInt32() const;
            _CGUL_EXPORT operator bool() const;
            _CGUL_EXPORT operator String() const;
            _CGUL_EXPORT operator Object() const;
            _CGUL_EXPORT operator Array() const;

            _CGUL_EXPORT String ToString();
        };

        _CGUL_EXPORT Value ParseNumber(String str);
        _CGUL_EXPORT Value ParseString(String str);
        _CGUL_EXPORT Array ParseArray(String str);
        _CGUL_EXPORT Object ParseObject(String str);
        _CGUL_EXPORT Value ParseValue(String str);
        _CGUL_EXPORT Value Parse(String str);
    }
 }

// Undefines
#include "../External/Undefines.hpp"
