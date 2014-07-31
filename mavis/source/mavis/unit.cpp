/*
    Copyright (c) 2014 Christopher Kaster <http://christopher.kaster.ws>

    This file is part of the "mavis" C++ unit testing framework <https://github.com/kasoki/mavis>

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
    THE SOFTWARE.
*/
#include <mavis/unit.hpp>

mavis::unit::unit(std::string name) : name(name) {}

void mavis::unit::add_test(std::function<mavis::test()> test) {
    this->tests.push_back(test);
}

void mavis::unit::run_tests() const {
    std::cout << std::endl << "Test case: " << this->name << std::endl <<
        "------------------" << std::endl;

    size_t tests_passed = 0;

    for(auto test : this->tests) {
        auto result = test();

        if(result.result) {
            tests_passed++;
        }

        this->print_result(result);
    }

    std::cout << std::endl << tests_passed << " of " << this->tests.size() <<
        " tests passed." << std::endl;
}

void mavis::unit::print_result(mavis::test test) const {
    std::cout << (test.result ? "PASS" : "FAIL") << ": " << test.func << ", expected " << test.expected
        << " got " << test.got << " at file: " << test.file << ", line: " << test.line << std::endl;
}