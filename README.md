# mavis

Lightweight, header only C++14 unit test framework inspired by jasmin.js

## Usage

Just put the ``mavis.hpp`` somewhere into your project and use it like this:

    #include "path/to/mavis.hpp"

    // whereever you want to write your tests

    mavis::describe("A suite", [](auto &suite) {
        int a = 0;

        suite.it("contains spec with an expectation", [&a](auto &spec) {
            spec.expect_equals(a, 0);
        });

        suite.it("contains specs with multiple expectations", [&a](auto &spec) {
            spec.expect_equals(a + 2, 2);
            spec.expect_equals(a * 2, 0);
        });
    });

## License

MIT
