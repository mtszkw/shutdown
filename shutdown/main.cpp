#include <iostream>
#include <nana/gui.hpp>
#include <nana/gui/widgets/label.hpp>
#include "scheduler.hpp"

int main() {
    nana::form fm;
    nana::label lb{ fm, nana::rectangle{ 10, 10, 100, 100 } };
    lb.caption("Hello world!");

    fm.show();
    nana::exec();
}